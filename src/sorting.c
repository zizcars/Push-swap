/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:55:17 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/06 14:12:07 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void selection_sort(t_list **stack_a) // in 6 takes 36 operation
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	int smal;
	int tmp;
	t_list *stack_b;
	// t_list *ptr;
	stack_b = NULL;
	while ((*stack_a)->next)
	{
		smal = top(*stack_a);
		r_(stack_a, 'a', 1);
		tmp = top(*stack_a);
		while (tmp != smal)
		{
			if (tmp < smal)
				smal = tmp;
			r_(stack_a, 'a', 1);
			tmp = top(*stack_a);
		}
		p_(stack_a, &stack_b, 'b', 1);
	}
	while (stack_b)
		p_(&stack_b, stack_a, 'a', 1);
}

int is_not_sort(t_list *stack_a)
{
	t_list *tmp;
	int tmp_a;
	int first;
	if (stack_a == NULL || stack_a->next == NULL)
		return (0);
	while (stack_a)
	{
		tmp = stack_a;
		first = *(int *)tmp->content;
		while (tmp)
		{
			tmp_a = *(int *)tmp->content;
			if (first > tmp_a)
				return (1);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

// int find_min(t_list *stack)
// {
// 	int min;
// 	min = *(int *)stack->content;
// 	while (stack)
// 	{
// 		if (min > *(int *)stack->content)
// 			min = *(int *)stack->content;
// 		stack = stack->next;
// 	}
// 	return (min);
// }

// void _sort(t_list **stack_a)
// {
// 	t_list *stack_b;
// 	int min = find_min(*stack_a);
// 	int size = ft_lstsize(*stack_a);
// 	int i = 0;
// 	int tmp;
// 	int tmp2;
// 	//-----------------------//
// 	printf("MIN=%d\n", min);
// 	//-----------------------//
// 	while(i < size/2)
// 	{
// 		push(stack_a, &stack_b, 'b', 1);
// 		i++;
// 	}
// }

void sort2_3(t_list **stack_a, int size)
{
	if (size == 2)
		s_(stack_a, 'a', 1);
	else if (size == 3)
	{
		int tmp1 = *(int *)(*stack_a)->content;
		int tmp2 = *(int *)(*stack_a)->next->content;
		int tmp3 = *(int *)(*stack_a)->next->next->content;
		if (tmp1 < tmp2 && tmp1 < tmp3)
		{
			rr_(stack_a, 'a', 1);
			s_(stack_a, 'a', 1);
		}
		else if (tmp2 > tmp3 && tmp2 < tmp1)
		{
			s_(stack_a, 'a', 1);
			rr_(stack_a, 'a', 1);
		}
		else if (tmp3 > tmp1 && tmp3 > tmp2)
			s_(stack_a, 'a', 1);
		else if (tmp2 > tmp1 && tmp2 > tmp3)
			rr_(stack_a, 'a', 1);
		else
			r_(stack_a, 'a', 1);
	}
}

// void sort_(t_list *stack_a)
// {
// 	t_list *stack_b = NULL;
// 	int sizea = ft_lstsize(stack_a);
// 	int sizeb = 0;
// 	while (sizea > 3)
// 	{
// 		push(&stack_a, &stack_b, 'a', 1);
// 		sizea--;
// 	}
// 	sort2_3(&stack_a, sizea);
// 	sizeb = ft_lstsize(stack_b);
// 	if (sizeb <= 3)
// 	{
// 		sort2_3(&stack_b, sizeb);
// 		return stack_b;
// 	}
// 	stack_b = sort_(stack_b);
// 	while (stack_b)
// 	{
// 		if (top(stack_b) > top(stack_a))
// 			push(&stack_b, &stack_a, 'a', 1);
// 		rotation(&stack_a, 'a', 1);
// 	}
// 	return stack_a;
// }