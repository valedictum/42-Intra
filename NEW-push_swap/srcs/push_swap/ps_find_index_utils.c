/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_index_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:02:00 by atang             #+#    #+#             */
/*   Updated: 2023/09/29 15:44:41 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ps_find_index(t_stack_node *stack, int number)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == number)
		{
			stack->index = i;
			return (i);
		}
		i++;
		stack = stack->next;
	}
	return (-1);
}

int	ps_sort_onto_stack_b(t_stack node **stack_a)
{
	t_stack_node	*stack_b;

	stack_b = NULL;
	if (ps_find_stack_size(*stack_a) > 3 && !ps_check_if_sorted(*stack_a))
		pb(stack_a);
	if (ps_find_stack_size(*stack_a) > 3 && !ps_check_if_sorted(*stack_a))
		pb(stack_a);
	if (ps_find_stack_size(*stack_a) > 3 && !ps_check_if_sorted(*stack_a))
		ps_sort_b_until_3_elements(stack_a, &stack_b);
	if (!ps_check_if_sorted(*stack_a))
		ps_sort_three_elements(stack_a);
	return (stack_b);
}


/*
// This function finds the correct place of the number in stack_b.
// In other words, it check what index number nbr_push will get 
// after it is being pushed to the stack_b.
int	ft_find_place_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < ft_lstlast(stack_b)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->nbr < nbr_push || tmp->nbr > nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

// This function finds the correct place of the number in stack_a.
// In other words, it check what index number nbr_push will get 
// after it is being pushed to the stack_a.
int	ft_find_place_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_lstlast(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
*/