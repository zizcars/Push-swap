/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:58:08 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/18 22:14:54 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# define STDERR 2

typedef struct movedata
{
	int	number;
	int	moves_a;
	int	moves_b;
	int	moves_ab;
	int	r_or_rr_a;
	int	r_or_rr_b;
}	t_movedata;

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
int			place_of_n(t_list *head, int n);
int			find_closest(t_list *head, int pivot);
void		go_to(t_list **stack, int number);
int			average(t_list *stack);
int			find_smaller(t_list *head, int pivot);
int			find_min(t_list *stack);
int			find_max(t_list *head);
void		push_to_b(t_list **stack_a, t_list **stack_b);
t_movedata	cal_moves(t_list *stack_a, t_list *stack_b, int number_in_b);
t_movedata	take_smale_moves(t_list *stack_a, t_list *stack_b);
void		apply_moves(t_list **stack_a, t_list **stack_b, t_movedata data);
void		sort_three(t_list **stack);
void		sort_stack(t_list **stack_a, t_list **stack_b);

#endif