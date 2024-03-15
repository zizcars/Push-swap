/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:59:37 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/15 22:46:20 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/// @brief it check rule name is it correct or not
/// @param r_name 
void	check_rule_name(char *r_name)
{
	char *rules_name[12];
	int ri;

	rules_name[0] = "sa";
	rules_name[1] = "sb";
	rules_name[2] = "ss";
	rules_name[3] = "ra";
	rules_name[4] = "rb";
	rules_name[5] = "rr";
	rules_name[6] = "rra";
	rules_name[7] = "rrb";
	rules_name[8] = "rrr";
	rules_name[9] = "pa";
	rules_name[10] = "pb";
	rules_name[11] = NULL;
	ri = 0;
	while (rules_name[ri])
	{
		if (ft_strncmp(r_name, rules_name[ri], ft_strlen(rules_name[ri])) == 0)
			return;
		ri++;
	}
	write(2, "Error\n", 6);
	exit(1);
}

/// @brief apply the rules
/// @param r_name 
void	ap_rule(char *r_name)
{
	
}


int	main(int count, char **numbers)
{
	t_list	*stack_a;
	// t_list	*stack_b;
	char *rule_name;

	stack_a = NULL;
	if (count == 1)
		exit(0);
	c_stack(count, numbers, &stack_a);
	rule_name = get_next_line(0);
	check_rule_name(rule_name);
	ft_printf("%s", rule_name);
	// while (stack_a)
	// {
	// 	ft_printf("%d ", *(int *)stack_a->content);
	// 	stack_a = stack_a->next;
	// }
}