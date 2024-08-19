/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_movez.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:59:48 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/07 16:30:36 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a, int check)
{
	t_stack	*tempo;
	t_stack	*bottom;

	if (ft_nmnd(*a) >= 2)
	{
		tempo = *a;
		*a = (*a)->next;
		bottom = ft_last_node(*a);
		tempo->next = NULL;
		bottom->next = tempo;
		ft_node_indx(a);
		if (check != 1)
			write(1, "ra\n", 3);
	}
	else
		return ;
}

void	rotate_b(t_stack **b, int check)
{
	t_stack	*tempo;
	t_stack	*bottom;

	if (ft_nmnd(*b) >= 2)
	{
		tempo = *b;
		*b = (*b)->next;
		bottom = ft_last_node(*b);
		tempo->next = NULL;
		bottom->next = tempo;
		ft_node_indx(b);
		if (check != 1)
			write(1, "rb\n", 3);
	}
	else
		return ;
}

void	rotate_r(t_stack **a, t_stack **b)
{
	rotate_a(a, 1);
	rotate_b(b, 1);
	write(1, "rr\n", 3);
}
