/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tooles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:15:54 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/15 20:48:17 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct min_big_
{
	int min;
	int big;
} min_big;

/// @brief calculate who many numbers n are bigger then and who many are smaller then
/// @param stack of numbers
/// @param medium the number
/// @return a struct has who many numbers bigger and smaller
min_big cal_min_big(t_list *stack, int medium)
{
	min_big n;

	n.min = 0;
	n.big = 0;
	while (stack)
	{
		if (medium < top(stack))
			n.min++;
		else if (medium > top(stack))
			n.big++;
		stack = stack->next;
	}
	return (n);
}

/// @brief find the medium number in a stack
/// @param stack of numbers
/// @return the medium number
int find_medium(t_list *stack)
{
	int medium;
	min_big n;
	t_list *ptr;
	int size;

	size = ft_lstsize(stack);
	ptr = stack;
	while (stack)
	{
		medium = *(int *)stack->content;
		n = cal_min_big(ptr, medium);
		if (size % 2 == 0)
			n.big++;
		if (n.big == n.min)
			break;
		stack = stack->next;
	}
	return (medium);
}

/// @brief Find the number that is smaller than pivot in a linked list.
/// @param head
/// @param pivot
/// @return The first small number than pivot.if there is no number return pivot.
int find_smaller(t_list *head, int pivot)
{
	int tmp;

	while (head)
	{
		tmp = *(int *)head->content;
		if (tmp < pivot)
			return (tmp);
		head = head->next;
	}
	return (pivot);
}