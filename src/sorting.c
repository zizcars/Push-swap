/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:55:17 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/06 17:02:06 by Achakkaf         ###   ########.fr       */
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

// int is_not_sort(t_list *stack_a)
// {
// 	t_list *tmp;
// 	int tmp_a;
// 	int first;
// 	if (stack_a == NULL || stack_a->next == NULL)
// 		return (0);
// 	while (stack_a)
// 	{
// 		tmp = stack_a;
// 		first = tmp->content;
// 		while (tmp)
// 		{
// 			tmp_a = tmp->content;
// 			if (first > tmp_a)
// 				return (1);
// 			tmp = tmp->next;
// 		}
// 		stack_a = stack_a->next;
// 	}
// 	return (0);
// }

// void sort2_3(t_list **stack_a, int size)
// {
// 	if (size == 2)
// 		s_(stack_a, 'a', 1);
// 	else if (size == 3)
// 	{
// 		int tmp1 = (*stack_a)->content;
// 		int tmp2 = (*stack_a)->next->content;
// 		int tmp3 = (*stack_a)->next->next->content;
// 		if (tmp1 < tmp2 && tmp1 < tmp3)
// 		{
// 			rr_(stack_a, 'a', 1);
// 			s_(stack_a, 'a', 1);
// 		}
// 		else if (tmp2 > tmp3 && tmp2 < tmp1)
// 		{
// 			s_(stack_a, 'a', 1);
// 			rr_(stack_a, 'a', 1);
// 		}
// 		else if (tmp3 > tmp1 && tmp3 > tmp2)
// 			s_(stack_a, 'a', 1);
// 		else if (tmp2 > tmp1 && tmp2 > tmp3)
// 			rr_(stack_a, 'a', 1);
// 		else
// 			r_(stack_a, 'a', 1);
// 	}
// }
