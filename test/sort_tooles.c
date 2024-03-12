/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:15:54 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/12 22:55:05 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct min_big_
{
	int min;
	int big;
} min_big;


min_big cal_min_big(t_list *stack, int medium)
{
	min_big n;

	n.min = 0;
	n.big = 0;
	while (stack)
	{
		if (medium < *(int *)stack->content)
			n.min++;
		else if (medium > *(int *)stack->content)
			n.big++;
		stack = stack->next;
	}
	return (n);
}
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
