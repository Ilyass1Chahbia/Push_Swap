/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 10:23:11 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/07 15:44:34 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	long_n(long n, int neg, int j)
{
	long	nb;

	nb = n;
	if (nb == -2147483648)
		return (-2147483648);
	if (j >= 20 && neg > 0)
		return (-1);
	if (n > LONG_MAX && neg > 0)
		return (-1);
	if (n > LONG_MAX && neg < 0)
		return (0);
	if (j >= 20 && neg < 0)
		return (0);
	return (n * neg);
}

void	skip_wspaces(const char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
}

long	ft_atoi(const char *str)
{
	int		neg;
	long	n;
	int		j;

	neg = 1;
	j = 0;
	n = 0;
	skip_wspaces(str);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		n = n * 10 + *str - 48;
		if ((n > INT_MAX && neg == 1) || (n > 2147483648 && neg == -1))
			return (2147483649);
		str++;
		j++;
	}
	return (long_n(n, neg, j));
}
