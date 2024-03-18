/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tooles_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:26:42 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/18 21:28:49 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

#define EMPTY 1
#define NOT_EMPTY 0

int	is_empty(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[i] == '\0')
		return (EMPTY);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '\0')
		return (EMPTY);
	return (NOT_EMPTY);
}

t_list	*c_node(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = malloc(sizeof(int));
	if (node->content == NULL)
		return (NULL);
	*(int *)node->content = content;
	node->next = NULL;
	return (node);
}

int	check_d(t_list *stack, int n)
{
	while (stack != NULL)
	{
		if (*(int *)stack->content == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	error(void)
{
	write(STDERR, "Error\n", 6);
	exit(1);
}

void	c_stack(int argc, char **argv, t_list **stack_a)
{
	int			argv_i;
	t_number	data;
	char		**numbers;
	int			num_i;

	argv_i = 1;
	while (argv_i < argc)
	{
		if (is_empty(argv[argv_i]))
			error();
		numbers = ft_split(argv[argv_i++], ' ');
		num_i = 0;
		while (numbers[num_i])
		{
			data = new_atoi(numbers[num_i]);
			free(numbers[num_i++]);
			if (data.error || check_d(*stack_a, data.num))
			{
				free(numbers);
				error();
			}
			ft_lstadd_back(stack_a, c_node(data.num));
		}
		free(numbers);
	}
}
