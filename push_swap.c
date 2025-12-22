/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaa-s <jaa-s@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:19:24 by jaa-s             #+#    #+#             */
/*   Updated: 2025/12/22 12:19:26 by jaa-s            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_node(t_node **a, t_node **tail, int value)
{
	t_node	*new;

	new = create_node(value);
	if (!*a)
		*a = new;
	else
		(*tail)->next = new;
	*tail = new;
}

static void	process_tokens(char **tokens, t_node **a, t_node **tail)
{
	int	j;
	int	value;
	int	error;
	int	k;

	j = 0;
	k = 0;
	while (tokens[j])
	{
		error = 0;
		value = ft_atoi_custom(tokens[j], &error);
		if (error)
		{
			free_stack(*a);
			while (tokens[k])
				free(tokens[k++]);
			free(tokens);
			print_error_and_exit();
		}
		add_node(a, tail, value);
		j++;
	}
	ft_clear(tokens, j);
}

static void	process_arg(char *argv, t_node **a, t_node **tail)
{
	char	**tokens;

	tokens = ft_split(argv, ' ');
	if (!tokens)
		(free_stack(*a), print_error_and_exit());
	if (tokens[0] == NULL)
	{
		free(tokens);
		free_stack(*a);
		print_error_and_exit();
	}
	process_tokens(tokens, a, tail);
}

t_node	*parse_args(int argc, char **argv)
{
	t_node	*a;
	t_node	*tail;
	int		i;

	a = NULL;
	tail = NULL;
	i = 1;
	if (argc == 1)
		exit(0);
	while (i < argc)
		process_arg(argv[i++], &a, &tail);
	check_duplicates(a);
	return (a);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	b = NULL;
	a = parse_args(argc, argv);
	if (is_sorted(a))
		(free_stack(a), exit(0));
	normalize_stack(a);
	if (stack_size(a) == 2)
		sort_two(&a);
	else if (stack_size(a) == 3)
		sort_three(&a);
	else if (stack_size(a) == 5)
		sort_five(&a, &b);
	else
		chunk_sort(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
