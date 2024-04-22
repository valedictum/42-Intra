/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:25:27 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:25:30 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STRUCTS_H
# define PUSH_SWAP_STRUCTS_H

# include <stdbool.h>

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef enum e_ouroboros
{
	BODY,
	HEAD,
}						t_ouroboros;

typedef struct s_number
{
	int					index;
	int					value;
	int					cost;
	struct s_number		*target;
	bool				above_median;
	enum e_ouroboros	position;
	struct s_number		*prev;
	struct s_number		*next;
}						t_number;

typedef struct s_stack
{
	t_number			*number;
	int					size;
	int					max_int;
	int					min_int;
}						t_stack;

#endif
