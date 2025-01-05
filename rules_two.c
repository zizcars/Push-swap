/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:48:27 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/18 22:45:36 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b, int per)
{
	s_(stack_a, 'a', 0);
	s_(stack_b, 'b', 0);
	if (per)
		ft_printf("%s\n", "ss");
}

void	rr(t_list **stack_a, t_list **stack_b, int per)
{
	r_(stack_a, 'a', 0);
	r_(stack_b, 'b', 0);
	if (per)
		ft_printf("%s\n", "rr");
}

void	rrr(t_list **stack_a, t_list **stack_b, int per)
{
	rr_(stack_a, 'a', 0);
	rr_(stack_b, 'b', 0);
	if (per)
		ft_printf("%s\n", "rrr");
}

int		average(t_list *stack)
{
	int	total;
	int	size;

	total = 0;
	size = 0;
	while (stack)
	{
		total = total + top(stack);
		size++;
		stack = stack->next;
	}
	return (total / size);
}
