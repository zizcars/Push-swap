/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:55:17 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/12 21:39:09 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void selection_sort(t_list **stack_a) // in 6 takes 36 operation
// {
// 	if (*stack_a == NULL || (*stack_a)->next == NULL)
// 		return ;
// 	int smal;
// 	// int tmp;
// 	t_list *stack_b;
// 	// t_list *ptr;
// 	stack_b = NULL;
// 	while ((*stack_a)->next)
// 	{
// 		// smal = top(*stack_a);
// 		// r_(stack_a, 'a', 1);
// 		// tmp = top(*stack_a);
// 		// while (tmp != smal)
// 		// {
// 		// 	if (tmp < smal)
// 		// 		smal = tmp;
// 		// 	r_(stack_a, 'a', 1);
// 		// 	tmp = top(*stack_a);
// 		// }
// 		smal = find_min(*stack_a);
// 		go_to(stack_a, smal);
// 		p_(stack_a, &stack_b, 'b', 1);
// 	}
// 	while (stack_b)
// 		p_(&stack_b, stack_a, 'a', 1);
// }

/// @brief Check if the linked list is sorted or not.
/// @param head of linked list
/// @return 0 if the stack is sorted else 1
int is_not_sort(t_list *head)
{
	t_list *tmp;
	int tmp_a;
	int first;
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

/// @brief Sort 2 or 3 element in a stack.
/// @param stack_a
/// @param size 2 or 3.
void sort2_3(t_list **stack, int size)
{
	if (is_not_sort(*stack))
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
}

/// @brief Push from stack A to stack B and let just 3 elements in stack A and sort them.
/// @param stack_a source stack A
/// @param stack_b	Distnetion stack B
void push_sort_a(t_list **stack_a, t_list **stack_b)
{
	int size;
	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		p_(stack_a, stack_b, 'b', 1);
		size--;
	}
	sort2_3(stack_a, size);
}
/*--------------------------------------------------------------*/
/// @brief Find the smallest number in the linked list.
/// @param head of linked list
/// @return the smallest number
int find_min(t_list *head)
{
	int min;
	int tmp;
	min = top(head);
	while (head)
	{
		tmp = top(head);
		if (min > tmp)
			min = tmp;
		head = head->next;
	}
	return (min);
}

int find_max(t_list *head)
{
	int max;
	int tmp;
	max = top(head);
	while (head)
	{
		tmp = top(head);
		if (max < tmp)
			max = tmp;
		head = head->next;
	}
	return (max);
}

/// @brief find the closest number to a pivot.
/// @param head of linked list
/// @param pivot
/// @return the closest number to pivot
int find_closest(t_list *head, int pivot)
{
	int tmp1;
	int close;
	close = find_max(head);
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
int place_of_n(t_list *head, int n)
{
	int n_index;
	int tmp;
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

void go_to(t_list **stack, int number)
{
	int size;
	int n_top;
	int moves;
	// int tmp;
	moves = place_of_n(*stack, number);
	if (moves == -1)
		return;
	n_top = top(*stack);
	size = ft_lstsize(*stack);
	// tmp = moves;
	while (number != n_top)
	{
		if (moves <= size / 2)
			r_(stack, 'a', 1);
		else if (moves > size / 2)
			rr_(stack, 'a', 1);
		// tmp--;
		n_top = top(*stack);
	}
}

void sort_stack(t_list **stack_a, t_list **stack_b)
{
	int size;
	if (is_not_sort(*stack_a) == 0)
		return;
	size = ft_lstsize(*stack_a);
	if (size == 1)
		return;
	else if (size <= 3)
	{
		sort2_3(stack_a, size);
		return;
	}
	int max;
	max = find_max(*stack_a);
	push_sort_a(stack_a, stack_b);
	int top_b;
	int close;
	int min;
	while (*stack_b)
	{
		top_b = top(*stack_b);
		if (top_b == max)
			close = find_min(*stack_a);
		else
			close = find_closest(*stack_a, top_b);
		go_to(stack_a, close);
		p_(stack_b, stack_a, 'a', 1);
	}
	min = find_min(*stack_a);
	go_to(stack_a, min);
}

