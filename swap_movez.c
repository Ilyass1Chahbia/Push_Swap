/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_movez.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:00:02 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/07 16:33:24 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a, int check)
{
	int	tempo;

	if (ft_nmnd(*a) <= 1)
		return ;
	tempo = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tempo;
	tempo = (*a)->i;
	(*a)->i = (*a)->next->i;
	(*a)->next->i = tempo;
	ft_node_indx(a);
	if (check != 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack **b, int check)
{
	int	tempo;

	if (ft_nmnd(*b) <= 1)
		return ;
	tempo = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = tempo;
	tempo = (*b)->i;
	(*b)->i = (*b)->next->i;
	(*b)->next->i = tempo;
	ft_node_indx(b);
	if (check != 1)
		write(1, "sb\n", 3);
}

void	swap_s(t_stack **a, t_stack **b)
{
	swap_a(a, 1);
	swap_b(b, 1);
	write(1, "ss\n", 3);
}
