/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:27:32 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/16 22:58:20 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Note: You can change it to sort stack b in pushing in stad of push just
// smaller than pivot push the smallest first and the next ...
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

/// @brief this function fill the data about how many moves and the best ones for a number.
/// @param stack_a
/// @param stack_b
/// @param number_in_b the number in b to search for its right position in stack_a
/// @return all the data that has add to bestmove data structer
movedata	cal_moves(t_list *stack_a, t_list *stack_b, int number_in_b)
{
	movedata data;
	int sizea;
	int sizeb;

	sizea = ft_lstsize(stack_a);
	sizeb = ft_lstsize(stack_b);
	data.number = number_in_b;
	data.moves_b = place_of_n(stack_b, number_in_b);
	data.moves_a = place_of_n(stack_a, find_closest(stack_a, number_in_b));
	data.moves_ab = 0;
	data.r_or_rr_a = 1;
	data.r_or_rr_b = 1;
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

/// @brief it rule is to applice the information in movedata variable.
/// @param stack_a
/// @param stack_b
/// @param data the movedata
void	apply_moves(t_list **stack_a, t_list **stack_b, movedata data)
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
