/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movez.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:59:23 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/07 15:58:09 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*tempo;

	if (!(*a))
		return ;
	tempo = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tempo;
	ft_node_indx(a);
	write(1, "pb\n", 3);
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*tempo;

	if (!(*b))
		return ;
	tempo = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tempo;
	ft_node_indx(b);
	write(1, "pa\n", 3);
}
