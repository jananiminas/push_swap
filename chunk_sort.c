/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaa-s <jaa-s@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:14:56 by jaa-s             #+#    #+#             */
/*   Updated: 2025/12/22 12:14:59 by jaa-s            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks_to_b(t_node **a, t_node **b, int chunks)
{
	int	size;
	int	chunk_size;
	int	i;

	size = stack_size(*a);
	chunk_size = size / chunks + 1;
	i = 0;
	while (*a)
	{
		if ((*a)->value < (i + 1) * chunk_size)
		{
			pb(a, b);
			if (*b && (*b)->value < i * chunk_size + chunk_size / 2)
				rb(b);
		}
		else
			ra(a);
		if (stack_size(*b) >= (i + 1) * chunk_size)
			i++;
	}
}

static int	get_max_position(t_node *stack)
{
	int		max_val;
	int		max_pos;
	int		current_pos;
	t_node	*tmp;

	if (!stack)
		return (-1);
	max_val = stack->value;
	max_pos = 0;
	current_pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value > max_val)
		{
			max_val = tmp->value;
			max_pos = current_pos;
		}
		current_pos++;
		tmp = tmp->next;
	}
	return (max_pos);
}

static void	push_back_to_a(t_node **a, t_node **b)
{
	int	pos;
	int	size;
	int	i;

	while (*b)
	{
		pos = get_max_position(*b);
		size = stack_size(*b);
		if (pos <= size / 2)
		{
			i = 0;
			while (i++ < pos)
				rb(b);
		}
		else
		{
			i = 0;
			while (i++ < size - pos)
				rrb(b);
		}
		pa(a, b);
	}
}

void	chunk_sort(t_node **a, t_node **b)
{
	int	size;
	int	chunks;

	size = stack_size(*a);
	if (size <= 100)
		chunks = 5;
	else
		chunks = 10;
	push_chunks_to_b(a, b, chunks);
	push_back_to_a(a, b);
}
