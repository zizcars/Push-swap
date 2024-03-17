/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:58:08 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/17 18:05:19 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

#define STDERR 2

typedef struct number_
{
	int	num;
	int	error;
} number;

/*---------------- tooles.c --------------*/
t_list	*c_node(int content);
int		check_d(t_list *head, int data);
void	c_stack(int argc, char **argv, t_list **stack_a);
int		is_empty(const char *str);
void	error();
/*-------------------------------------*/

/*---------- new_atoi.c --------------*/
number	new_atoi(const char *str);
/*----------------------------------*/

/*------------------------ rules.c --------------------------*/
void	s_(t_list **stack, char c, int per);
void	p_(t_list **s_src, t_list **s_dst, char c, int per);
void	r_(t_list **stack, char c, int per);
void	rr_(t_list **stack, char c, int per);
void	ss(t_list **stack_a, t_list **stack_b, int per);
void	rr(t_list **stack_a, t_list **stack_b, int per);
void	rrr(t_list **stack_a, t_list **stack_b, int per);
int		top(t_list *stack);
/*----------------------------------------------------------*/

/*----------------- sorting.c ----------------*/
// void	selection_sort(t_list **stack_a);
int		is_not_sort(t_list *head);
void	sort_three(t_list **stack);
int		place_of_n(t_list *head, int n);
int		find_closest(t_list *head, int pivot);
void	go_to(t_list **stack, int number);
/*------------------------------------------*/

/*------------------ sort_tooles.c -----------------------*/
typedef struct min_big_
{
	int min;
	int big;
} min_big;

min_big cal_min_big(t_list *stack, int medium);
int		find_medium(t_list *stack);
int		find_smaller(t_list *head, int pivot);
int		find_min(t_list *stack);
int		find_max(t_list *head);
/*-----------------------------------------------*/
/*------------------ sort.c -----------------------*/
typedef struct movedata_
{
	int number;
	int moves_a;
	int moves_b;
	int moves_ab;
	int r_or_rr_a;
	int r_or_rr_b;
} movedata;

void		push_to_b(t_list **stack_a, t_list **stack_b);
movedata	cal_moves(t_list *stack_a, t_list *stack_b, int number_in_b);
movedata	take_smale_moves(t_list *stack_a, t_list *stack_b);
void		apply_moves(t_list **stack_a, t_list **stack_b, movedata data);
void		sort_stack(t_list **stack_a, t_list **stack_b);
/*-----------------------------------------------*/
#endif