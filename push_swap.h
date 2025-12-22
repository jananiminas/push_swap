/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaa-s <jaa-s@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:19:34 by jaa-s             #+#    #+#             */
/*   Updated: 2025/12/22 12:19:38 by jaa-s            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

t_node				*create_node(int value);
void				free_stack(t_node *stack);
int					stack_size(t_node *a);
int					is_sorted(t_node *a);
int					ft_atoi_custom(const char *str, int *error);
void				print_error_and_exit(void);
void				check_duplicates(t_node *a);
char				*ft_substr(char const *str, unsigned int start, size_t len);
char				**ft_split(const char *s, char c);
char				*ft_strdup(const char *str);
size_t				ft_strlen(const char *s);
char				**ft_clear(char **lst, int i);
void				sa(t_node **a);
void				sb(t_node **b);
void				ra(t_node **a);
void				rra(t_node **a);
void				rb(t_node **b);
void				rrb(t_node **b);
void				pb(t_node **a, t_node **b);
void				pa(t_node **a, t_node **b);
int					find_min_index(t_node *a);
void				sort_two(t_node **a);
void				sort_three(t_node **a);
void				sort_five(t_node **a, t_node **b);
void				normalize_stack(t_node *a);
void				chunk_sort(t_node **a, t_node **b);

#endif
