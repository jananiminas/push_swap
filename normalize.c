/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaa-s <jaa-s@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:17:27 by jaa-s             #+#    #+#             */
/*   Updated: 2025/12/22 12:17:31 by jaa-s            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_stack_to_array(t_node *stack, int *arr, int size)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack;
	while (i < size)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
}

static void	bubble_sort_array(int *arr, int size)
{
	int	j;
	int	k;
	int	temp;

	j = 0;
	while (j < size - 1)
	{
		k = j + 1;
		while (k < size)
		{
			if (arr[j] > arr[k])
			{
				temp = arr[j];
				arr[j] = arr[k];
				arr[k] = temp;
			}
			k++;
		}
		j++;
	}
}

static void	update_stack_values(t_node *stack, int *arr, int size)
{
	int		i;
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->value == arr[i])
			{
				tmp->value = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	normalize_stack(t_node *a)
{
	int	size;
	int	*arr;

	size = stack_size(a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
	{
		free_stack(a);
		exit(1);
	}
	copy_stack_to_array(a, arr, size);
	bubble_sort_array(arr, size);
	update_stack_values(a, arr, size);
	free(arr);
}
