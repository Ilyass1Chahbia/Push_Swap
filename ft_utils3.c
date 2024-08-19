/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:58:27 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/07 15:46:44 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_val(t_stack *a)
{
	t_stack	*tempo;

	tempo = a;
	while (a)
	{
		if (a->data < tempo->data)
			tempo = a;
		a = a->next;
	}
	return (tempo->i);
}

int	ft_max_val(t_stack *a)
{
	int	max;

	max = a->data;
	while (a)
	{
		if (a->data > max)
			max = a->data;
		a = a->next;
	}
	return (max);
}

t_stack	*ft_min_node(t_stack *a)
{
	t_stack	*tempo;

	tempo = a;
	while (a)
	{
		if (a->data < tempo->data)
			tempo = a;
		a = a->next;
	}
	return (tempo);
}
