/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tooles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:26:42 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/06 14:14:27 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Create a node with an allocation for its content.
/// @param content of the new node.
/// @return the created node.
t_list*c_node(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->content = malloc(sizeof(int));
	*(int *)(node->content) = content;
	return (node);
}

/// @brief Check if there is a duplicate number.
/// @param stack The head of stack
/// @param n The number
/// @return 1 if dublicated else 0
int check_d(t_list *stack, int n)
{
	t_list	*ptr;
	int		tmp;

	ptr = stack;
	if (ptr == NULL)
		return (0);
	tmp = *(int *)stack->content;
	while (ptr != NULL)
	{
		if (tmp == n)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

t_list *c_stack(int argc, char **argv)
{
	t_list	*stack_a;
	char	**numbers;
	number	data;

	stack_a = NULL;
	while (argc > 1)
	{
		numbers = ft_split(*argv, ' ');
		while (*numbers)
		{
			data = new_atoi(*numbers);
			free(*numbers);
			if (data.error || check_d(stack_a, data.num))
			{
				write(STDERR, "Error\n", 6);
				free(numbers);
				exit(1);
			}
			ft_lstadd_back(&stack_a, c_node(data.num));
			numbers++;
		}
		free(numbers);
		argv++;
		argc--;
	}
	return stack_a;
}

// void free_stack(t_list **stack)
// {
// 	t_list *ptr;
// 	t_list *tmp;
// 	ptr = *stack;
// 	while(ptr)
// 	{
// 		tmp = ptr;
// 		free(tmp->content);
// 		free(tmp); 
// 		ptr = ptr->next;
// 	}
// }