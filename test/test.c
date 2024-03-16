#include <stdio.h>
#include <stdlib.h>
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
		if (rule[j] == '\n' && rules[i][j] == '\n')
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
	int a = rule_cmp(r_name, rules_name);
	if (a)
	{
		printf("Error\n", a);
// 		write(STDERR, "Error\n", 6);
		exit(1);
	}
	printf("yes\n", a);
}
int main() {
    check_rule_name("sa");
    return 0;
}