/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:55:17 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/06 19:55:32 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void selection_sort(t_list **stack_a) // in 6 takes 36 operation
// {
// 	if (*stack_a == NULL || (*stack_a)->next == NULL)
// 		return ;
// 	int smal;
// 	int tmp;
// 	t_list *stack_b;
// 	// t_list *ptr;
// 	stack_b = NULL;
// 	while ((*stack_a)->next)
// 	{
// 		smal = top(*stack_a);
// 		r_(stack_a, 'a', 1);
// 		tmp = top(*stack_a);
// 		while (tmp != smal)
// 		{
// 			if (tmp < smal)
// 				smal = tmp;
// 			r_(stack_a, 'a', 1);
// 			tmp = top(*stack_a);
// 		}
// 		p_(stack_a, &stack_b, 'b', 1);
// 	}
// 	while (stack_b)
// 		p_(&stack_b, stack_a, 'a', 1);
// }

/// @brief Check if the stack is sorted or not
/// @param stack 
/// @return 0 if the stack is sorted else 1
int is_not_sort(t_list *stack)
{
	t_list *tmp;
	int tmp_a;
	int first;
	if (stack == NULL || stack->next == NULL)
		return (0);
	while (stack)
	{
		tmp = stack;
		first = *(int *)tmp->content;
		while (tmp)
		{
			tmp_a = *(int *)tmp->content;
			if (first > tmp_a)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

/// @brief Sort 2 or 3 element in a stack.
/// @param stack_a 
/// @param size 2 or 3.
void sort2_3(t_list **stack, int size)
{
	if (size == 2)
		s_(stack, 'a', 1);
	else if (size == 3)
	{
		int tmp1 = *(int *)(*stack)->content;
		int tmp2 = *(int *)(*stack)->next->content;
		int tmp3 = *(int *)(*stack)->next->next->content;
		if (tmp1 < tmp2 && tmp1 < tmp3)
		{
			rr_(stack, 'a', 1);
			s_(stack, 'a', 1);
		}
		else if (tmp2 > tmp3 && tmp2 < tmp1)
		{
			s_(stack, 'a', 1);
			rr_(stack, 'a', 1);
		}
		else if (tmp3 > tmp1 && tmp3 > tmp2)
			s_(stack, 'a', 1);
		else if (tmp2 > tmp1 && tmp2 > tmp3)
			rr_(stack, 'a', 1);
		else
			r_(stack, 'a', 1);
	}
}

/// @brief Find the smallest number in the linked list.
/// @param head of linked list
/// @return the smallest number
int find_min(t_list *head)
{
	int min;
	int tmp;

	min = *(int *)head->content;
	while (head)
	{
		tmp = *(int *)head->content;
		if (min > tmp)
			min = tmp;
		head = head->next;
	}
	return (min);
}

/// @brief Push from stack A to stack B and let just 3 elements in stack A and sort them.
/// @param stack_a source stack A
/// @param stack_b	Distnetion stack B
void	p_s_a(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	while(size > 3)
	{
		p_(stack_a, stack_b, 'b', 1);
		size--;
	}
	sort2_3(stack_a, size);
}

