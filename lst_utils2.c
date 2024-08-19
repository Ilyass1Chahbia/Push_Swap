/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:58:45 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/09 10:23:25 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_last_node(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_stack	*ft_pre_last_node(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next && node->next->next)
		node = node->next;
	return (node);
}

void	ft_lstclear(t_stack **stack)
{
	t_stack	*tempo;
	t_stack	*node;

	if (!stack)
		return ;
	node = *stack;
	while (node != NULL)
	{
		tempo = node->next;
		free(node);
		node = tempo;
	}
	*stack = NULL;
}

void	initiated(t_stack **a, t_stack **b)
{
	getting_prices(b);
	getting_prices(a);
	getting_the_target(*a, *b);
	best_deal(a, b);
}

void	rot_case(t_stack **a, t_stack **b, t_stack *tp)
{
	if (tp->i < ft_nmnd(*b) / 2 && tp->target->i < ft_nmnd(*a) / 2)
	{
		while (*a != tp->target && *b != tp)
			rotate_r(a, b);
	}
	else if (tp->i >= ft_nmnd(*b) / 2 && tp->target->i >= ft_nmnd(*a) / 2)
	{
		while (*a != tp->target && *b != tp)
			reverse_rotate_r(a, b);
	}
	if (*b != tp)
	{
		while (*b != tp)
		{
			if (tp->i < ft_nmnd(*b) / 2)
				rotate_b(b, 0);
			else
				reverse_rotate_b(b, 0);
		}
	}
}
