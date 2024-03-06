/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:57:53 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/02/26 13:00:12 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

int part_start(int arr[], int low, int high)
{
	int pivot = high;
	int swap = low;

	while (low < high)
	{
		if (arr[pivot] > arr[low])
		{
			ft_swap(&arr[low], &arr[swap]);
			swap++;
		}
		low++;
	}
	ft_swap(&arr[pivot], &arr[swap]);
	return (swap);
}

void quick_sort(int arr[], int low, int high)
{
	int part;

	if (low < high)
	{
		part = part_start(arr, low, high);
		quick_sort(arr, low, part - 1);
		quick_sort(arr, part + 1, high);
	}
}
