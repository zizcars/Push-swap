/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:03:24 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/12 13:57:59 by Achakkaf         ###   ########.fr       */
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
	// ft_printf("a:%d ",place_min(stack_a, 8));
	// ft_printf("a:%d ",find_closest(stack_a, 8));
	// p_s_a(&stack_a, &stack_b);
	// selection_sort(&stack_a);
	// ft_printf("%d\n", place_of_n(stack_a, 8));
	// go_to(&stack_a, 8);
	sort_stack(&stack_a, &stack_b);
	// sort2_3(&stack_a, 2);
	if (is_not_sort(stack_a) == 1)
		ft_printf("not sorted\n");
	else
		ft_printf("sorted\n");
	// while (stack_a)
	// {
	// 	ft_printf("%d ", *(int *)stack_a->content);
	// 	stack_a = stack_a->next;
	// }

}
