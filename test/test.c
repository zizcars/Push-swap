/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:03:24 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/08 12:19:32 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list *stack_a;
	// t_list *stack_b;
	stack_a = NULL;
	if (argc == 1)
		exit(0);
	c_stack(argc, argv, &stack_a);
	// p_s_a(&stack_a, &stack_b);
	ft_printf("min index = %d\n", find_closest(stack_a , -8));
	while (stack_a)	
	{
		ft_printf("a:%d ", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	// while (stack_b)
	// {
	// 	ft_printf("b:%d ", *(int *)stack_b->content);
	// 	stack_b = stack_b->next;
	// }
}
