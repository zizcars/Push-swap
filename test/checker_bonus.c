/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:59:37 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/16 17:45:46 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/// @brief it check rule name is it correct or not
/// @param r_name the rule name
void check_rule_name(char *r_name)
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
/// @param r_name the rule name
void apply_rule(char *r_name, t_list **stack_a, t_list **stack_b)
{
	if (r_name == NULL)
		return;
	check_rule_name(r_name);
	if (r_name[0] == 's')
	{
		if (r_name[1] == 'a')
			s_(stack_a, 'a', 0);
		else if (r_name[1] == 'b')
			s_(stack_b, 'b', 0);
		else
			ss(stack_a, stack_b, 0);
	}
	else if (r_name[0] == 'p')
	{
		if (r_name[1] == 'a')
			p_(stack_b, stack_a, 'a', 0);
		else if (r_name[1] == 'b')
			p_(stack_a, stack_b, 'b', 0);
	}
	else if (r_name[0] == 'r')
	{
		if (r_name[1] == 'a')
			r_(stack_a, 'a', 0);
		else if (r_name[1] == 'b')
			r_(stack_b, 'b', 0);
		else
		{
			if (r_name[2] == '\0')
				rr(stack_a, stack_b, 0);
			else if (r_name[2] == 'a')
				rr_(stack_a, 'a', 0);
			else if (r_name[2 == 'b'])
				rr_(stack_b, 'b', 0);
		}
	}
}

int main(int count, char **numbers)
{
	t_list *stack_a;
	t_list *stack_b;
	char *rule_name;

	stack_b = NULL;
	stack_a = NULL;
	if (count == 1)
		exit(0);
	c_stack(count, numbers, &stack_a);
	while (1)
	{
		rule_name = get_next_line(0);
		apply_rule(rule_name, &stack_a, &stack_b);
		ft_printf("A:");
		while (stack_a)
		{
			ft_printf("%d ", *(int *)stack_a->content);
			stack_a = stack_a->next;
		}
		ft_printf("B:");
		while (stack_b)
		{
			ft_printf("%d ", *(int *)stack_b->content);
			stack_b = stack_b->next;
		}
	}
}