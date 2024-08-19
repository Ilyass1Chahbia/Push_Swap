/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:59:09 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/07 15:57:16 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdg(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int	is_def_digit(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdg(args[i][j]))
			{
				if (args[i][j] == '+' || args[i][j] == '-')
				{
					if (ft_isdg(args[i][j - 1]) || !ft_isdg(args[i][j + 1]))
						return (0);
				}
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_full_spaces(char **ag)
{
	int	i;
	int	j;

	i = 0;
	while (ag[i])
	{
		j = 0;
		while (ag[i][j])
		{
			if ((ag[i][j] >= 9 && ag[i][j] <= 13) || ag[i][j] == 32)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_nums_sorted(t_stack	**a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_parsing(char **args)
{
	if (!args)
		return (write(2, "Error\n", 6), free_func(args), exit(1));
	else if (!is_def_digit(args))
		return (write(2, "Error\n", 6), free_func(args), exit(1));
	else if (!is_full_spaces(args))
		return (write(2, "Error\n", 6), free_func(args), exit(1));
}
