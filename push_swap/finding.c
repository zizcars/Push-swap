/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:15:54 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/18 22:19:04 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_smaller(t_list *head, int pivot)
{
	int	tmp;

	while (head)
	{
		tmp = *(int *)head->content;
		if (tmp < pivot)
			return (tmp);
		head = head->next;
	}
	return (pivot);
}

int	find_min(t_list *head)
{
	int	min;
	int	tmp;

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

int	find_max(t_list *head)
{
	int	max;
	int	tmp;

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
