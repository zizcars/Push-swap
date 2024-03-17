/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:48:27 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/17 19:52:27 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ss(t_list **stack_a, t_list **stack_b, int per)
{
	s_(stack_a, 'a', 0);
	s_(stack_b, 'b', 0);
	if (per)
		ft_printf("%s\n", "ss");
}

void rr(t_list **stack_a, t_list **stack_b, int per)
{
	r_(stack_a, 'a', 0);
	r_(stack_b, 'b', 0);
	if (per)
		ft_printf("%s\n", "rr");
}

void rrr(t_list **stack_a, t_list **stack_b, int per)
{
	rr_(stack_a, 'a', 0);
	rr_(stack_b, 'b', 0);
	if (per)
		ft_printf("%s\n", "rrr");
}

/// @brief Push the element from stack A to stack B starting from less first
/// @param stack_a
/// @param stack_b
void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int medium;
	t_list *ptr;
	int smaller;
	int size;

	size = ft_lstsize(*stack_a);
	medium = find_medium(*stack_a);
	ptr = *stack_a;
	smaller = medium + 1;
	while (ptr && smaller != medium && size > 3)
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

/// @brief sort a stack in less moves.
/// @param stack_a 
/// @param stack_b 
void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int size;
	movedata data;

	if (is_not_sort(*stack_a) == 0)
		return;
	size = ft_lstsize(*stack_a);
	if (size == 1)
		return;
	else if (size <= 3)
	{
		sort_three(stack_a);
		return;
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
