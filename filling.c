/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:57:49 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/09 10:23:08 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_argsize(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		i++;
	}
	return (i);
}

void	first_node(t_stack **a, char **res, int r)
{
	*a = ft_lstnew(r);
	if (!(*a))
		return (free(res), exit(1));
}

void	filling(char **res, t_stack **a)
{
	long		n;
	int			r;
	int			size;
	t_stack		*tmp;

	n = 0;
	r = 0;
	size = ft_argsize(res);
	while (n < size)
	{
		if (ft_atoi(res[n]) == 2147483649)
			return (write(2, "Error\n", 7), free_func(res), exit(1));
		r = ft_atoi(res[n]);
		if (n == 0)
			first_node(a, res, r);
		else
		{
			tmp = ft_lstnew(r);
			if (!(tmp))
				return (free(a), free(res), exit(1));
			ft_lstadd_back(a, tmp);
		}
		n++;
	}
}

void	arr_sort(int *res, int n)
{
	int	i;
	int	m;
	int	t1;

	i = 0;
	while (i < n - 1)
	{
		m = i + 1;
		while (m < n)
		{
			if (res[i] < res[m])
			{
				t1 = res[i];
				res[i] = res[m];
				res[m] = t1;
			}
			m++;
		}
		i++;
	}
}

int	getting_med(t_stack **a)
{
	int		n;
	int		i;
	int		med;
	t_stack	*tempo;
	int		*res;

	n = ft_nmnd(*a);
	i = 0;
	tempo = *a;
	res = malloc(sizeof(int) * n);
	if (!res)
		return (exit(1), 0);
	while (tempo)
	{
		res[i] = tempo->data;
		tempo = tempo->next;
		i++;
	}
	arr_sort(res, n);
	med = res[n / 2];
	free(res);
	return (med);
}
