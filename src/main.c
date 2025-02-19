/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:03:24 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/18 17:24:04 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **numbers)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc == 1)
		exit(0);
	c_stack(argc, numbers, &stack_a);
	sort_stack(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	return (0);
}
