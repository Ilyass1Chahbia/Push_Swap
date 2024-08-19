/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:57:20 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/05/18 11:57:50 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	safe_malloc(char **res, int position, size_t buffer)
{
	int	i;

	i = 0;
	res[position] = malloc(buffer);
	if (!res[position])
	{
		while (i < position)
			free(res[i++]);
		free(res);
		return (1);
	}
	return (0);
}

int	fill(char **res, char const *s, char delimeter)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimeter && *s)
			++s;
		while (*s != delimeter && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (safe_malloc(res, i, len + 1))
				return (1);
			ft_strlcpy(res[i], s - len, len + 1);
		}
		++i;
	}
	return (0);
}

size_t	count_words(char const *s, char delimeter)
{
	size_t	words;
	int		inside_word;

	words = 0;
	while (*s)
	{
		inside_word = 0;
		while (*s == delimeter && *s)
			++s;
		while (*s != delimeter && *s)
		{
			if (!inside_word)
			{
				++words;
				inside_word = 1;
			}
			++s;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**res;

	if (!s)
		return (0);
	words = 0;
	words = count_words(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (0);
	res[words] = 0;
	if (fill(res, s, c))
		return (0);
	return (res);
}
