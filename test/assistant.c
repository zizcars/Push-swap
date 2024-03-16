/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:55:17 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/16 23:02:27 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Check if the linked list is sorted or not.
/// @param head of linked list
/// @return 0 if the stack is sorted else 1
int	is_not_sort(t_list *head)
{
	t_list	*tmp;
	int		tmp_a;
	int		first;

	if (head == NULL || head->next == NULL)
		return (0);
	while (head)
	{
		tmp = head;
		first = *(int *)tmp->content;
		while (tmp)
		{
			tmp_a = *(int *)tmp->content;
			if (first > tmp_a)
				return (1);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (0);
}

/// @brief Sort 3 element in a stack.
/// @param stack_a
/// @param size
void	sort_three(t_list **stack)
{
	int	max;

	if (is_not_sort(*stack))
	{
		max = find_max(*stack);
		if (max == *(int *)(*stack)->content)
			r_(stack, 'a', 1);
		else if (max == *(int *)(*stack)->next->content)
			rr_(stack, 'a', 1);
		if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
				s_(stack, 'a', 1);
	}
}

/// @brief find the closest number to a pivot.
/// @param head of linked list
/// @param pivot
/// @return the closest number to pivot
int	find_closest(t_list *head, int pivot)
{
	int	tmp1;
	int	close;
	int	min;

	min = find_min(head);
	close = find_max(head);
	if (pivot > close)
		return (min);
	while (head)
	{
		tmp1 = top(head);
		if (tmp1 > pivot && tmp1 < close)
			close = tmp1;
		head = head->next;
	}
	return (close);
}

/// @brief find the place of the number in linked list.
/// @param head of the linked list
/// @return The place of the minimun number
int	place_of_n(t_list *head, int n)
{
	int	n_index;
	int	tmp;

	if (head == NULL)
		return (-1);
	n_index = -1;
	tmp = top(head);
	if (tmp == n)
		return (0);
	while (tmp != n && head)
	{
		n_index++;
		tmp = top(head);
		head = head->next;
	}
	if (head == NULL && tmp != n)
		return (-1);
	return (n_index);
}

/// @brief get the number to top of the stack
/// @param stack 
/// @param number 
void	go_to(t_list **stack, int number)
{
	int	size;
	int	n_top;
	int	moves;

	moves = place_of_n(*stack, number);
	if (moves == -1)
		return;
	n_top = top(*stack);
	size = ft_lstsize(*stack);
	while (number != n_top)
	{
		if (moves <= size / 2)
			r_(stack, 'a', 1);
		else if (moves > size / 2)
			rr_(stack, 'a', 1);
		n_top = top(*stack);
	}
}
