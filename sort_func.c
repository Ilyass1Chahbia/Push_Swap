/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:59:55 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/07 17:56:01 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_case(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = get_biggest_node(*a);
	if (*a == biggest_node)
		rotate_a(a, 0);
	else if ((*a)->next == biggest_node)
		reverse_rotate_a(a, 0);
	if ((*a)->data > (*a)->next->data)
		swap_a(a, 0);
}

void	mid_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	n;
	int	min;

	n = ft_nmnd(*a);
	ft_node_indx(a);
	i = n;
	while (i-- > 3)
	{
		min = ft_min_val(*a);
		while (min != 0)
		{
			if (min < n / 2)
				rotate_a(a, 0);
			else
				reverse_rotate_a(a, 0);
			min = ft_min_val(*a);
		}
		push_b(a, b);
	}
	if (ft_nums_sorted(a) > 0)
		three_case(a);
	push_a(a, b);
	push_a(a, b);
}

void	best_deal(t_stack **a, t_stack **b)
{
	int		n_a;
	int		n_b;
	t_stack	*tp;

	tp = prices_sales(b);
	n_a = ft_nmnd(*a);
	n_b = ft_nmnd(*b);
	rot_case(a, b, tp);
	if (*a != tp->target)
	{
		while (*a != tp->target)
		{
			if (tp->target->i < ft_nmnd(*a) / 2)
				rotate_a(a, 0);
			else
				reverse_rotate_a(a, 0);
		}
	}
	push_a(a, b);
}

void	big_sort(t_stack **a, t_stack **b)
{
	int		med;
	int		min;
	int		max;
	t_stack	*smol;

	med = getting_med(a);
	min = ft_min_val(*a);
	max = ft_max_val(*a);
	push_process(a, b, med, max);
	three_case(a);
	ft_node_indx(a);
	ft_node_indx(b);
	while (ft_nmnd(*b) != 0)
		initiated(a, b);
	smol = ft_min_node(*a);
	while (smol->i != 0)
	{
		if (smol->i < ft_nmnd(*a) / 2)
			rotate_a(a, 0);
		else
			reverse_rotate_a(a, 0);
	}
}

void	sort_func(t_stack **a, t_stack **b)
{
	int	n;

	n = ft_nmnd(*a);
	if (n == 2)
		swap_a(a, 0);
	else if (n == 3)
		three_case(a);
	else if (n == 4 || n == 5)
		mid_sort(a, b);
	else if (n >= 6)
		big_sort(a, b);
}
