/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:27:32 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/13 15:14:53 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Find the number that is smaller than pivot in a linked list.
/// @param head 
/// @param pivot 
/// @return The first small number than pivot.if there is no number return pivot. 
int	find_smaller(t_list *head, int pivot)
{
	int tmp;

	while (head)
	{
		tmp = *(int *)head->content;
		if (tmp < pivot)
			return (tmp);
		head = head->next;
	}
	return (pivot);
}
// Note: You can change it to sort stack b in pushing in stad of push just 
// smaller than pivot push the smallest first and the next ...
/// @brief Push the element from stack A to stack B starting from less first
/// @param stack_a 
/// @param stack_b 
void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int		medium;
	t_list	*ptr;
	int		smaller;
	int		size;

	size = ft_lstsize(*stack_a);
	medium = find_medium(*stack_a);
	ptr = *stack_a;
	smaller = medium + 1;
	while (ptr && smaller != medium && size > 3)
	{
		smaller = find_smaller(*stack_a, medium);
		go_to(stack_a, smaller);
		p_(stack_a, stack_b, 'b', 1);
		ptr = *stack_a;
		ptr = ptr->next;
		size--;
	}
	while (size > 3)
	{
		p_(stack_a, stack_b, 'b', 1);
		size--;
	}
	if(size <= 3)
		sort2_3(stack_a, size);
}
void	final_sort(t_list **stack_a, t_list **stack_b)
{
	
}