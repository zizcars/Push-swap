/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:58:08 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/18 23:42:51 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "get_next_line_bonus.h"
# define STDERR 2

typedef struct number
{
	int	num;
	int	error;
}	t_number;

int			check_d(t_list *head, int data);
int			is_empty(const char *str);
void		error(void);
int			is_not_sort(t_list *head);
t_number	new_atoi(const char *str);
t_list		*c_node(int content);
void		c_stack(int argc, char **argv, t_list **stack_a);
void		s_(t_list **stack, char c, int per);
void		p_(t_list **s_src, t_list **s_dst, char c, int per);
void		r_(t_list **stack, char c, int per);
void		rr_(t_list **stack, char c, int per);
void		ss(t_list **stack_a, t_list **stack_b, int per);
void		rr(t_list **stack_a, t_list **stack_b, int per);
void		rrr(t_list **stack_a, t_list **stack_b, int per);
int			top(t_list *stack);

#endif