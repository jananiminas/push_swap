/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaa-s <jaa-s@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:18:48 by jaa-s             #+#    #+#             */
/*   Updated: 2025/12/22 12:18:52 by jaa-s            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_custom(const char *str, int *error)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	*error = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (*error = 1, 0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i++] - '0');
		if (num * sign > 2147483647 || num * sign < -2147483648)
			return (*error = 1, 0);
	}
	if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		return (*error = 1, 0);
	return ((int)(num * sign));
}

int	find_min_index(t_node *a)
{
	int	min;
	int	min_index;
	int	current_index;

	if (!a)
		return (-1);
	min = a->value;
	min_index = 0;
	current_index = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			min_index = current_index;
		}
		current_index++;
		a = a->next;
	}
	return (min_index);
}

void	check_duplicates(t_node *a)
{
	t_node	*i;
	t_node	*j;

	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				(free_stack(a), print_error_and_exit());
			j = j->next;
		}
		i = i->next;
	}
}
