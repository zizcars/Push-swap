/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:59:37 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/17 21:55:10 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:59:37 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/17 21:49:11 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int rule_cmp(char *rule, char **rules)
{
	int i;
	int j;

	i = 0;
	while (rules[i])
	{
		j = 0;
		while (rule[j] && rules[i][j] && rule[j] == rules[i][j])
			j++;
		if (rule[j] == '\0' && rules[i][j] == '\0')
			return (0);
		i++;
	}
	return (1);
}

/// @brief it check rule name is it correct or not
/// @param r_name the rule name
void check_rule_name(char *r_name)
{
	char *rules_name[12];

	rules_name[0] = "sa\n";
	rules_name[1] = "sb\n";
	rules_name[2] = "ss\n";
	rules_name[3] = "ra\n";
	rules_name[4] = "rb\n";
	rules_name[5] = "rr\n";
	rules_name[6] = "rra\n";
	rules_name[7] = "rrb\n";
	rules_name[8] = "rrr\n";
	rules_name[9] = "pa\n";
	rules_name[10] = "pb\n";
	rules_name[11] = NULL;
	if (rule_cmp(r_name, rules_name))
	{
		write(STDERR, "Error\n", 6);
		exit(1);
	}
}

void apply_r(char *r_name, t_list **stack_a, t_list **stack_b)
{
	if (r_name[1] == 'a')
		r_(stack_a, 'a', 0);
	else if (r_name[1] == 'b')
		r_(stack_b, 'b', 0);
	else
	{
		if (r_name[2] == 'r')
			rrr(stack_a, stack_b, 0);
		else if (r_name[2] == 'a')
			rr_(stack_a, 'a', 0);
		else if (r_name[2] == 'b')
			rr_(stack_b, 'b', 0);
		else
			rr(stack_a, stack_b, 0);
	}
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
		apply_r(r_name, stack_a, stack_b);
}

int main(int count, char **numbers)
{
	t_list *stack_a;
	t_list *stack_b;
	char *rule_name;

	rule_name = NULL;
	stack_b = NULL;
	stack_a = NULL;
	if (count == 1)
		exit(0);
	c_stack(count, numbers, &stack_a);
	rule_name = get_next_line(0);
	while (rule_name)
	{
		apply_rule(rule_name, &stack_a, &stack_b);
		rule_name = get_next_line(0);
	}
	if (stack_b || is_not_sort(stack_a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

