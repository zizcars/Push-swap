/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:55:17 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/18 23:10:26 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int		medium;
	int		smaller;
	t_list	*ptr;
	int		size;

	size = ft_lstsize(*stack_a);
	medium = average(*stack_a);
	ptr = *stack_a;
	// smaller = medium + 1;
	smaller = find_smaller(*stack_a, medium);
	while (ptr && smaller < medium && size > 3)
	{
		smaller = find_smaller(*stack_a, medium);
		go_to(stack_a, smaller);
		p_(stack_a, stack_b, 'b', 1);
		ptr = *stack_a;
		ptr = ptr->next;
		size--;
	}
	while (size > 3)
	{
		p_(stack_a, stack_b, 'b', 1);
		size--;
	}
	if (size <= 3)
		sort_three(stack_a);
}

int		is_not_sort(t_list *head)
{
	t_list	*tmp;
	int		tmp_a;
	int		first;

	if (head == NULL || head->next == NULL)
		return (0);
	while (head)
	{
		tmp = head;
		first = *(int *)tmp->content;
		while (tmp)
		{
			tmp_a = *(int *)tmp->content;
			if (first > tmp_a)
				return (1);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (0);
}

void	sort_three(t_list **stack)
{
	int	max;

	if (is_not_sort(*stack))
	{
		max = find_max(*stack);
		if (max == *(int *)(*stack)->content)
			r_(stack, 'a', 1);
		else if (max == *(int *)(*stack)->next->content)
			rr_(stack, 'a', 1);
		if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
			s_(stack, 'a', 1);
	}
}

void	go_to(t_list **stack, int number)
{
	int	size;
	int	n_top;
	int	moves;

	moves = place_of_n(*stack, number);
	if (moves == -1)
		return ;
	n_top = top(*stack);
	size = ft_lstsize(*stack);
	while (number != n_top)
	{
		if (moves <= size / 2)
			r_(stack, 'a', 1);
		else if (moves > size / 2)
			rr_(stack, 'a', 1);
		n_top = top(*stack);
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int			size;
	t_movedata	data;

	if (is_not_sort(*stack_a) == 0)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 1)
		return ;
	else if (size <= 3)
	{
		sort_three(stack_a);
		return ;
	}
	push_to_b(stack_a, stack_b);
	while (*stack_b)
	{
		data = take_smale_moves(*stack_a, *stack_b);
		apply_moves(stack_a, stack_b, data);
		p_(stack_b, stack_a, 'a', 1);
	}
	go_to(stack_a, find_min(*stack_a));
}
