/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:59:55 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/06 17:58:19 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
