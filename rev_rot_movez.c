/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_movez.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:59:43 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/07 16:30:17 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **a, int check)
{
	t_stack	*tempo;
	t_stack	*pre_final;

	if (ft_nmnd(*a) >= 2)
	{
		tempo = ft_last_node(*a);
		pre_final = ft_pre_last_node(*a);
		pre_final->next = NULL;
		tempo->next = *a;
		*a = tempo;
		ft_node_indx(a);
		if (check != 1)
			write(1, "rra\n", 4);
	}
	else
		return ;
}

void	reverse_rotate_b(t_stack **b, int check)
{
	t_stack	*tempo;
	t_stack	*pre_final;

	if (ft_nmnd(*b) >= 2)
	{
		tempo = ft_last_node(*b);
		pre_final = ft_pre_last_node(*b);
		pre_final->next = NULL;
		tempo->next = *b;
		*b = tempo;
		ft_node_indx(b);
		if (check != 1)
			write(1, "rrb\n", 4);
	}
	else
		return ;
}

void	reverse_rotate_r(t_stack **a, t_stack **b)
{
	reverse_rotate_a(a, 1);
	reverse_rotate_b(b, 1);
	write(1, "rrr\n", 4);
}
