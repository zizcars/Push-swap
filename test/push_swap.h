/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:58:08 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/12 21:27:15 by Achakkaf         ###   ########.fr       */
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
/*-------------------------------------*/

/*---------- new_atoi.c --------------*/
number	new_atoi(const char *str);
/*----------------------------------*/

/*------------------------ rules.c --------------------------*/
void	s_(t_list **stack, char c, int per);
void	p_(t_list **s_src, t_list **s_dst, char c, int per);
void	r_(t_list **stack, char c, int per);
void	rr_(t_list **stack, char c, int per);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		top(t_list *stack);
/*----------------------------------------------------------*/

/*----------------- sorting.c ----------------*/
// void	selection_sort(t_list **stack_a);
int		is_not_sort(t_list *head);
void	sort2_3(t_list **stack, int size);
int		find_min(t_list *stack);
void	push_sort_a(t_list **stack_a, t_list **stack_b);
int		place_of_n(t_list *head, int n);
int		find_closest(t_list *head, int pivot);
void	sort_stack(t_list **stack_a, t_list **stack_b);
int		find_max(t_list *head);
void	go_to(t_list **stack, int number);
/*------------------------------------------*/

/*------------------ sort.c -----------------------*/
int find_medium(t_list *stack);
/*-----------------------------------------------*/
#endif