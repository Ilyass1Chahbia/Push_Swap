/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:11:13 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/05/18 12:01:23 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc(sizeof (char) * ft_strlen(src) + 1);
	if (!(dup))
	{
		return (0);
	}
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	if (dstsize > 0)
	{
		while (src[index] != '\0' && index < dstsize - 1)
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	index = 0;
	while (src[index] != '\0')
		index++;
	return (index);
}
