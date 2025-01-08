/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_two_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:48:27 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/18 22:16:31 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
