/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_tooles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:27:32 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/17 22:52:06 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_movedata	default_values(t_list *stack_a, t_list *stack_b, int number)
{
	t_movedata	data;

	data.number = number;
	data.moves_b = place_of_n(stack_b, number);
	data.moves_a = place_of_n(stack_a, find_closest(stack_a, number));
	data.moves_ab = 0;
	data.r_or_rr_a = 1;
	data.r_or_rr_b = 1;
	return (data);
}

t_movedata	cal_moves(t_list *stack_a, t_list *stack_b, int number)
{
	t_movedata	data;
	int			sizea;
	int			sizeb;

	sizea = ft_lstsize(stack_a);
	sizeb = ft_lstsize(stack_b);
	data = default_values(stack_a, stack_b, number);
	if (data.moves_a > (sizea / 2))
	{
		data.moves_a = sizea - data.moves_a;
		data.r_or_rr_a = -1;
	}
	if (data.moves_b > (sizeb / 2))
	{
		data.moves_b = sizeb - data.moves_b;
		data.r_or_rr_b = -1;
	}
	if (data.r_or_rr_a == data.r_or_rr_b && data.moves_a && data.moves_b)
	{
		if (data.moves_a > data.moves_b)
			data.moves_ab = data.moves_b;
		else
			data.moves_ab = data.moves_a;
	}
	return (data);
}

t_movedata	take_smale_moves(t_list *stack_a, t_list *stack_b)
{
	t_movedata	src;
	t_movedata	tmp;
	t_list		*ptr;
	int			tmp_total;
	int			src_total;

	ptr = stack_b;
	src = cal_moves(stack_a, stack_b, top(stack_b));
	if (src.moves_a + src.moves_b == 0 || src.moves_a + src.moves_b == 1)
		return (src);
	while (ptr)
	{
		tmp = cal_moves(stack_a, stack_b, top(ptr));
		tmp_total = tmp.moves_a + tmp.moves_b - tmp.moves_ab;
		src_total = src.moves_a + src.moves_b - src.moves_ab;
		if (tmp_total < src_total)
			src = tmp;
		ptr = ptr->next;
	}
	return (src);
}

t_movedata	apply_move_ab(t_list **stack_a, t_list **stack_b, t_movedata data)
{
	while (data.moves_ab > 0)
	{
		if (data.r_or_rr_a == 1)
			rr(stack_a, stack_b, 1);
		else
			rrr(stack_a, stack_b, 1);
		data.moves_ab--;
		data.moves_a--;
		data.moves_b--;
	}
	return (data);
}

void	apply_moves(t_list **stack_a, t_list **stack_b, t_movedata data)
{
	data = apply_move_ab(stack_a, stack_b, data);
	while (data.moves_a > 0)
	{
		if (data.r_or_rr_a == 1)
			r_(stack_a, 'a', 1);
		else
			rr_(stack_a, 'a', 1);
		data.moves_a--;
	}
	while (data.moves_b > 0)
	{
		if (data.r_or_rr_b == 1)
			r_(stack_b, 'b', 1);
		else
			rr_(stack_b, 'b', 1);
		data.moves_b--;
	}
}
