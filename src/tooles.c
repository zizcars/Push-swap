/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tooles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:26:42 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/06 17:37:04 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Create a node with an allocation for its content.
/// @param content of the new node.
/// @return the created node.
t_list *c_node(int content)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	node->content = (int *)malloc(sizeof(int));
	*(int *)node->content = content;
	node->next = NULL;
	return (node);
}

/// @brief Check if there is a duplicate number.
/// @param stack The head of stack
/// @param n The number
/// @return 1 if dublicated else 0
int check_d(t_list *stack, int n)
{
	while (stack != NULL)
	{
		if (*(int *)stack->content == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/// @brief Store the input in linked list called.
/// @param argc The number of arguments
/// @param argv The arguments
/// @param stack_a the head of a linked list
void	c_stack(int argc, char **argv, t_list **stack_a)
{
	int		argv_i;
	number	data;
	char	**numbers;
	int		num_i;

	argv_i = 1;
	while (argv_i < argc)
	{
		numbers = ft_split(argv[argv_i++], ' ');
		num_i = 0;
		while (numbers[num_i])
		{
			data = new_atoi(numbers[num_i]);
			free(numbers[num_i++]);
			if (data.error || check_d(*stack_a, data.num))
			{
				write(STDERR, "Error\n", 6);
				free(numbers);
				exit(1);
			}
			ft_lstadd_back(stack_a, c_node(data.num));
		}
		free(numbers);
	}
}
