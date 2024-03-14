/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:03:24 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/14 22:07:36 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	stack_b = NULL;
	stack_a = NULL;
	if (argc == 1)
		exit(0);
	c_stack(argc, argv, &stack_a);
	push_to_b(&stack_a, &stack_b);
	// p_(&stack_b, &stack_a, 'a', 1);
	bestmove a = take_smale_moves(stack_a, stack_b);
	ft_printf("the best number: %d\n", a.number);
	ft_printf("the best movesa: %d\n", a.moves_a);
	ft_printf("the best movesb: %d\n", a.moves_b);
	ft_printf("the best movesab: %d\n", a.moves_ab);
	ft_printf("the best r or rr a: %d\n", a.r_or_rr_a);
	ft_printf("the best r or rr b: %d\n", a.r_or_rr_b);
	// final_sort(&stack_a, &stack_b);
	// if (is_not_sort(stack_a) == 1)
	// 	ft_printf("not sorted\n");
	// else
	// 	ft_printf("sorted\n");
	while (stack_a)
	{
		ft_printf("%d ", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\nb:");
	while (stack_b)
	{
		ft_printf("%d ", *(int *)stack_b->content);
		stack_b = stack_b->next;
	}
}
