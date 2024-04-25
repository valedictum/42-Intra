/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:27:09 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:27:10 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libpush_swap.h"

void	add_command_to_list(t_command **list, int command)
{
	t_command	*new;
	t_command	*current;

	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->command = command;
	new->next = NULL;
	if (*list == NULL)
		*list = new;
	else
	{
		current = *list;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

t_command	*read_commands(int *numbers)
{
	t_command	*list;
	char		*line;
	int			command;

	command = 0;
	list = NULL;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strlen(line) > 0)
			line[ft_strlen(line) - 1] = '\0';
		command = convert_command(line);
		if (command < 0)
		{
			free_list(list);
			free(line);
			free(numbers);
			print_error();
		}
		add_command_to_list(&list, command);
		free(line);
		line = get_next_line(0);
	}
	return (list);
}

void	run_check(t_command *list, int *numbers, int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (list == NULL && size == 0)
	{
		free(numbers);
		return ;
	}
	initialise_stacks(&stack_a, &stack_b, numbers, size);
	run_commands(list, stack_a, stack_b);
	if (is_it_sorted(stack_a) == true && stack_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(list);
	free_stacks(stack_a, stack_b);
}

void	checker(int argc, char **argv)
{
	int			*numbers;
	int			size;
	t_command	*list;

	if (argc == 2)
		parse_argument(argv[1], &numbers, &size);
	else
		parse_multi_arguments(argv, &numbers, &size);
	list = read_commands(numbers);
	run_check(list, numbers, size);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		checker(argc, argv);
	return (0);
}
