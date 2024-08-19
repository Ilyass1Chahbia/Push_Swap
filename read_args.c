/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:59:38 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/07 20:05:53 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check(char *av, char *str)
{
	int	j;
	int	checker;

	checker = 0;
	j = 0;
	while (av[j])
	{
		if (av[j] >= '0' && av[j] <= '9')
			checker = 1;
		j++;
	}
	if (checker == 0)
		return (write(2, "Error\n", 6), free(str), exit(1));
}

char	*args_join(char **av, char *str)
{
	int		i;
	char	*tempo;

	i = 1;
	str = ft_strdup("");
	if (str == NULL)
		return (NULL);
	while (av[i])
	{
		ft_check(av[i], str);
		tempo = str;
		str = ft_strjoin(str, av[i]);
		free(tempo);
		if (str == NULL)
			break ;
		if (av[i + 1])
		{
			tempo = str;
			str = ft_strjoin(str, " ");
			free(tempo);
		}
		i++;
	}
	return (str);
}

char	**read_args(char **av)
{
	char	*str;
	char	**res;

	str = NULL;
	str = args_join(av, str);
	res = ft_split(str, ' ');
	free(str);
	return (res);
}
