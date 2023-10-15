/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:32:31 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/10 14:03:53 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_linklist
{
	struct s_stack	*header;
	int				rear_value;
	int				size;
}	t_linklist;

t_stack		*initial_stack(void);
t_linklist	*initial_linklist(void);
void		free_linklist(t_linklist *linklist);

void		swap(t_stack *node, char c);
void		rotate(t_linklist *linklist, char c);
void		rrotate(t_linklist *linklist, char c);
void		push(t_linklist *linklist, t_linklist *sourcelist);

void		push_swap(char **data);
void		ps_sort(t_linklist *linka);

void		ps_sort_big(t_linklist *origin, t_linklist *helper, int chunks);
void		ps_sort_big_util(t_linklist *origin, t_linklist *helper,
				int *contain, int *memo);

int			sorted(t_linklist *linklist);
int			get_extrem(t_linklist *origin, int flag);
int			get_extrem_index(t_linklist *origin, int flag);
void		move_top_utils(t_linklist *origin, int index, char c);
int			get_index(t_linklist *origin, int flag);
void		push_back(t_linklist *origin, t_linklist *helper);
void		push_back_big(t_linklist *origin, t_linklist *helper);

#endif
