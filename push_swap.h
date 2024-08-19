/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilchahbi <ilchahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:59:33 by ilchahbi          #+#    #+#             */
/*   Updated: 2024/06/08 11:21:05 by ilchahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				i;
	int				price;
	int				budget;
	int				price_of_target;
	int				sale;
	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;

char	**read_args(char **av);
int		ft_strlen(const char *s);
int		ft_min_val(t_stack *s);
int		ft_max_val(t_stack *s);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_parsing(char **args);
t_stack	*ft_lstnew(int data);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
long	ft_atoi(const char *str);
void	filling(char **res, t_stack **a);
void	free_func(char **res);
int		ft_nums_sorted(t_stack	**a);
int		ft_argsize(char **res);
int		ft_nmnd(t_stack	*stack);
t_stack	*ft_last_node(t_stack *node);
t_stack	*ft_pre_last_node(t_stack *node);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	swap_a(t_stack **a, int check);
void	swap_b(t_stack **b, int check);
void	swap_s(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a, int check);
void	rotate_b(t_stack **b, int check);
void	rotate_r(t_stack **a, t_stack **b);
void	reverse_rotate_a(t_stack **a, int check);
void	reverse_rotate_b(t_stack **b, int check);
void	reverse_rotate_r(t_stack **a, t_stack **b);
void	ft_node_indx(t_stack **a);
void	sort_func(t_stack **a, t_stack **b);
int		getting_med(t_stack **a);
void	getting_prices(t_stack **stack);
t_stack	*ft_min_node(t_stack *a);
void	ft_lstclear(t_stack **lst);
int		stack_is_sorted(t_stack *stack);
t_stack	*get_biggest_node(t_stack *node);
void	push_process(t_stack **a, t_stack **b, int med, int max);
void	getting_the_target(t_stack *a, t_stack *b);
void	getting_prices(t_stack **stack);
t_stack	*prices_sales(t_stack **stack);
void	initiated(t_stack **a, t_stack **b);
void	rot_case(t_stack **a, t_stack **b, t_stack *tp);
void	best_deal(t_stack **a, t_stack **b);
void	mid_sort(t_stack **a, t_stack **b);
void	three_case(t_stack **a);
#endif