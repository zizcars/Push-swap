/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:03:24 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/17 20:38:39 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **numbers)
{
	t_list *stack_a;
	t_list *stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc == 1)
		exit(0);
	c_stack(argc, numbers, &stack_a);
	sort_stack(&stack_a, &stack_b);
	// if (is_not_sort(stack_a))
	// 	ft_printf("not sorted\n");
	// else
	// 	ft_printf("sorted\n");
	ft_lstclear(&stack_a, free); 
	// while (stack_a)
	// {
	// 	ft_printf("%d ", *(int *)stack_a->content);
	// 	stack_a = stack_a->next;
	// }
	// ft_printf("\nb:");
	// while (stack_b)
	// {
	// 	ft_printf("%d ", *(int *)stack_b->content);
	// 	stack_b = stack_b->next;
	// }
}
