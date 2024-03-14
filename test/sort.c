/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:27:32 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/14 22:05:58 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
// Note: You can change it to sort stack b in pushing in stad of push just
// smaller than pivot push the smallest first and the next ...
/// @brief Push the element from stack A to stack B starting from less first
/// @param stack_a
/// @param stack_b
void push_to_b(t_list **stack_a, t_list **stack_b)
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
		sort2_3(stack_a, size);
}

/*
			Best move function.
2 6 8 9 1 4 7
3 5 10
ex int movesB, movesA, movesAB, r_or_rr
ex cal_moves(t_list *head, number number)
	// stack : B
	// 	moves > size / 2
	// 		size - moves
	// 	moves < size / 2
	// 		moves
	// stack : A
	// 	moves > size / 2
	// 		size - moves
	// 	moves < size / 2
	// 		moves
	if ((moves B and moves A > size / 2) or (moves B and moves A < size / 2))
		if moves B > moves A
			rr of moves A
		else
			rr of moves B
	else if ((moves B and moves A < size / 2) or (moves B and moves A < size / 2))
		if moves B < moves A
			rrr of moves A
		else
			rrr of moves B

ex take_smale_moves(t_list *head)
	src = cal_moves(head->content)
	while(head)
		tmp = cal_moves(head->content)
		if (tmp.movesAB != 0)
			if(tmp.movesAB < src.movesAB)
				src = tmp
		else if(tmp.movesA + tmp.movesB < src.movesA + src.movesB)
			src = tmp;
	return src
*/

// void final_sort(t_list **stack_a, t_list **stack_b)
// {
// 	int size;
// 	int close;
// 	if (is_not_sort(*stack_a) == 0)
// 		return;
// 	size = ft_lstsize(*stack_a);
// 	if (size == 1)
// 		return;
// 	else if (size <= 3)
// 	{
// 		sort2_3(stack_a, size);
// 		return;
// 	}
// 	push_to_b(stack_a, stack_b);
// }

// typedef struct bestmove_
// {
// 	int number;
// 	int moves_a;
// 	int moves_b;
// 	int moves_ab;
// 	int r_or_rr_a; // 0 for r_ or 1 for rr_
// 	int r_or_rr_b;
// } bestmove;

/// @brief this function fill the data about how many moves and the best ones for a number.
/// @param stack_a
/// @param stack_b
/// @param number_in_b the number in b to search for its right position in stack_a
/// @return all the data that has add to bestmove data structer
bestmove cal_moves(t_list *stack_a, t_list *stack_b, int number_in_b)
{
	bestmove data;
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
	if ((data.r_or_rr_a == -1 && data.r_or_rr_b == -1) || (data.r_or_rr_a == 1 && data.r_or_rr_b == 1))
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
bestmove take_smale_moves(t_list *stack_a, t_list *stack_b)
{
	bestmove src;
	bestmove tmp;
	t_list *ptr;

	ptr = stack_b;
	src = cal_moves(stack_a, stack_b, top(stack_b));
	while (ptr)
	{
		tmp = cal_moves(stack_a, stack_b, top(ptr));
		if (tmp.moves_ab != 0)
		{
			if (tmp.moves_ab < src.moves_ab)
				src = tmp;
		}
		else if ((tmp.moves_a + tmp.moves_b) < (src.moves_a + src.moves_b))
			src = tmp;
		ptr = ptr->next;
	}
	return (src);
}

// voidnew_go_to(t_list **stack)
// {
// }