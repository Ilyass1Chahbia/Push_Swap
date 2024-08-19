/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:59:28 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/07 16:11:28 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_duplicated(t_stack **a)
{
	t_stack	*tempo1;
	t_stack	*tempo2;

	tempo1 = *a;
	while (tempo1)
	{
		tempo2 = tempo1->next;
		while (tempo2)
		{
			if (tempo1->data == tempo2->data)
				return (0);
			tempo2 = tempo2->next;
		}
		tempo1 = tempo1->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**res;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		res = read_args(av);
		ft_parsing(res);
		filling(res, &a);
		free_func(res);
		if (a != NULL && a->next == NULL)
			return (ft_lstclear(&a), 0);
		if (!ft_duplicated(&a))
			return (write(2, "Error\n", 6), ft_lstclear(&a), 0);
		if (!ft_nums_sorted(&a))
			return (ft_lstclear(&a), 0);
		sort_func(&a, &b);
		ft_lstclear(&a);
	}
	else
		return (0);
}
