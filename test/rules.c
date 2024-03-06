/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:39:39 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/06 17:04:25 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// You can add char c to argumant and add an if condition to check if 
// if it is 'a' print like pa or pb ...

void s_(t_list **stack, char c, int per)
{
	t_list *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if(per)
		ft_printf("s%c\n", c);
}

void p_(t_list **s_src, t_list **s_dst, char c, int per)
{
	t_list *tmp_s;
	t_list *tmp_d;

	if (s_src == NULL || s_dst == NULL || *s_src == NULL)
		return;
	tmp_s = (*s_src)->next;
	tmp_d = (*s_dst);
	*s_dst = *s_src;
	(*s_dst)->next = tmp_d;
	*s_src = tmp_s;
	if(per)
		ft_printf("p%c\n", c);
}

void rr_(t_list **stack, char c, int per)
{
	t_list *last;
	t_list *ptr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	ptr = *stack;
	last = ft_lstlast(*stack);
	while (ptr->next->next)
		ptr = ptr->next;
	last->next = *stack;
	*stack = last;
	ptr->next = NULL;
	if(per)
		ft_printf("rr%c\n", c);
}

void r_(t_list **stack, char c, int per)
{
	t_list *tmp;
	t_list *last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	last = ft_lstlast(*stack);
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	last->next = *stack;
	*stack = tmp;
	if(per)
		ft_printf("r%c\n", c);
}

void ss(t_list **stack_a, t_list **stack_b)
{
	s_(stack_a, 'a', 0);
	s_(stack_b, 'b', 0);
	ft_printf("%s\n", "ss");
}

void rr(t_list **stack_a, t_list **stack_b)
{
	r_(stack_a, 'a', 0);
	r_(stack_b, 'b', 0);
	ft_printf("%s\n", "rr");
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	rr_(stack_a, 'a', 0);
	rr_(stack_b, 'b', 0);
	ft_printf("%s\n", "rrr");
}

int top(t_list *stack)
{
	return (*(int *)stack->content);
}
