/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_tooles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:27:32 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/17 19:48:37 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief it set a movedata variable to it default value.
/// @param stack_a 
/// @param stack_b 
/// @param number 
/// @return movedata variable
movedata default_values(t_list *stack_a, t_list *stack_b, int number)
{
	movedata data;

	data.number = number;
	data.moves_b = place_of_n(stack_b, number);
	data.moves_a = place_of_n(stack_a, find_closest(stack_a, number));
	data.moves_ab = 0;
	data.r_or_rr_a = 1;
	data.r_or_rr_b = 1;
	return (data);
}

/// @brief this function fill the data about how many moves and the best ones for a number.
/// @param stack_a
/// @param stack_b
/// @param number_in_b the number in b to search for its right position in stack_a
/// @return all the data that has add to bestmove data structer
movedata	cal_moves(t_list *stack_a, t_list *stack_b, int number)
{
	movedata data;
	int sizea;
	int sizeb;

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
	if (data.r_or_rr_a == data.r_or_rr_b && data.moves_a > 0 && data.moves_b > 0)
	{
		if (data.moves_a > data.moves_b)
			data.moves_ab = data.moves_b;
		else
			data.moves_ab = data.moves_a;
	}
	return (data);
}

/// @brief compare all the data that are comes form cal_moves and take the small one
/// @param stack_a
/// @param stack_b
/// @return the small data that is found about a number
movedata	take_smale_moves(t_list *stack_a, t_list *stack_b)
{
	movedata src;
	movedata tmp;
	t_list *ptr;
	int t;
	int s;

	ptr = stack_b;
	src = cal_moves(stack_a, stack_b, top(stack_b));
	if (src.moves_a + src.moves_b == 0 || src.moves_a + src.moves_b == 1)
		return (src);
	while (ptr)
	{
		tmp = cal_moves(stack_a, stack_b, top(ptr));
		t = tmp.moves_a + tmp.moves_b - tmp.moves_ab;
		s = src.moves_a + src.moves_b - src.moves_ab;
		if (t < s)
			src = tmp;
		ptr = ptr->next;
	}
	return (src);
}

/// @brief apply moves for just moving stack A and stack B
/// @param stack_a
/// @param stack_b
/// @param data
/// @return new move data
movedata apply_move_ab(t_list **stack_a, t_list **stack_b, movedata data)
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

/// @brief it rule is to applice the information in movedata variable.
/// @param stack_a
/// @param stack_b
/// @param data the movedata
void	apply_moves(t_list **stack_a, t_list **stack_b, movedata data)
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
