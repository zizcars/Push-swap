/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:59:55 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/06 14:10:15 by Achakkaf         ###   ########.fr       */
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
	// int		argv_i;
	// number	data;
	// t_list	*element;
	// char	**numbers;
	// int		num_i;
	t_list	*stack_a;

	stack_a = NULL;
	// argv_i = 1;
	if (argc == 1)
		exit(0);
	// while (argv_i < argc)
	// {
	// 	numbers = ft_split(argv[argv_i], ' ');
	// 	num_i = 0;
	// 	while (numbers[num_i])
	// 	{
	// 		data = new_atoi(numbers[num_i]);
	// 		free(numbers[num_i]);
	// 		if (data.error || check_d(stack_a, data.num))
	// 		{
	// 			write(STDERR, "Error\n", 6);
	// 			free(numbers);
	// 			exit(1);
	// 		}
	// 		element = c_node(data.num);
	// 		ft_lstadd_back(&stack_a, element);
	// 		num_i++;
	// 	}
	// 	free(numbers);
	// 	argv_i++;
	// }
	// Selection_Sort(&stack_a);
	// system("leaks push_swap");
	stack_a = c_stack(argc, argv);
	while (stack_a)
	{
		ft_printf("%d ", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
}
