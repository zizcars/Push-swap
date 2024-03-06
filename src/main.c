/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:59:55 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/06 17:33:58 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

// void sort_(t_list **stack_a)
// {
// 	t_list *ptr;
// 	ptr = *stack_a;
// 	int tmp1;
// 	int tmp2;
// 	if (ptr == NULL || ptr->next == NULL)
// 		return;
// 	while(is_not_sort(*stack_a))
// 	{
// 		tmp1 = *(int *)(*stack_a)->content;
// 		tmp2 = *(int *)(*stack_a)->next->content;
// 		if (tmp1 > tmp2)
// 			s_swap(stack_a, 'a', 1);
// 		rotation(stack_a, 'a', 1);
// 		rotation(stack_a, 'a', 1);
// 	}
// }

int main(int argc, char **argv)
{
	t_list	*stack_a = NULL;
	if (argc == 1)
		exit(0);
	c_stack(argc, argv, &stack_a);
	while (stack_a)
	{
		ft_printf("%d ", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
}
