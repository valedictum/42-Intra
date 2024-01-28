/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:24:44 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:24:47 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"
# include "push_swap.h"
# include "push_swap_structs.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_command
{
	int					command;
	struct s_command	*next;
}						t_command;

void					*get_operation(int op);
int						convert_command(char *str);
void					run_commands(t_command *list, t_stack *stack_a,
							t_stack *stack_b);
bool					operation_check(int op);
void					free_list(t_command *list);

#endif
