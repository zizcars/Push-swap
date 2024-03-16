/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Achakkaf <zizcarschak1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:27:50 by Achakkaf          #+#    #+#             */
/*   Updated: 2024/03/16 21:54:08 by Achakkaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	whitespace(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

static number	nmber(const char *str, number res, int sign)
{
	long	tmp;

	tmp = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			tmp = tmp * 10 + *str - '0';
			str++;
		}
		else
		{
			res.error = 1;
			return (res);
		}
	}
	tmp = tmp * sign;
	if (tmp < -2147483648 || tmp > 2147483647)
	{
		res.error = 1;
		return (res);
	}
	res.num = tmp;
	return (res);
}

number	new_atoi(const char *str)
{
	int		sign;
	number	res;

	res.error = 0;
	res.num = 0;
	sign = 1;
	str += whitespace(str);
	if (*str == '-' && ft_strlen(str) > 1)
	{
		sign = -1;
		str++;
	}
	else if (*str == '+' && ft_strlen(str) > 1)
		str++;
	res = nmber(str, res, sign);
	return (res);
}
