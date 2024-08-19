/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:14:13 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/07 18:04:41 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_biggest_node(t_stack *node)
{
	int		biggest_value;
	t_stack	*biggest_node;

	if (!node)
		return (NULL);
	biggest_value = INT_MIN;
	while (node)
	{
		if (node->data > biggest_value)
		{
			biggest_value = node->data;
			biggest_node = node;
		}
		node = node->next;
	}
	return (biggest_node);
}

void	push_process(t_stack **a, t_stack **b, int med, int max)
{
	int	i;
	int	p;
	int	n;

	i = 0;
	p = 0;
	n = ft_nmnd(*a);
	while (*a && n > 3)
	{
		if ((*a)->data != max)
		{
			push_b(a, b);
			if ((*b)->data >= med)
				rotate_b(b, 0);
		}
		else
			rotate_a(a, 0);
		n = ft_nmnd(*a);
	}
}

void	getting_the_target(t_stack *a, t_stack *b)
{
	int		b_s;
	t_stack	*tempo;
	t_stack	*res;

	while (b)
	{
		res = NULL;
		b_s = INT_MAX;
		tempo = a;
		while (tempo)
		{
			if (tempo->data > b->data && tempo->data < b_s)
			{
				b_s = tempo->data;
				res = tempo;
			}
			tempo = tempo->next;
		}
		b->target = res;
		b->budget = b->price + b->target->price;
		b = b->next;
	}
}

void	getting_prices(t_stack **stack)
{
	int		n;
	t_stack	*t1mpo;

	t1mpo = *stack;
	n = ft_nmnd(t1mpo);
	while (t1mpo)
	{
		t1mpo->price = t1mpo->i;
		if (t1mpo->i < n / 2)
			t1mpo->price = t1mpo->i;
		else
			t1mpo->price = n - t1mpo->i;
		t1mpo = t1mpo->next;
	}
}

t_stack	*prices_sales(t_stack **stack)
{
	int		res;
	t_stack	*tempo;
	t_stack	*tmp;

	tmp = *stack;
	res = INT_MAX;
	tempo = *stack;
	while (tempo)
	{
		if (tempo->budget < res)
		{
			res = tempo->budget;
			tmp = tempo;
		}
		tempo = tempo->next;
	}
	return (tmp);
}
