/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:29:47 by atang             #+#    #+#             */
/*   Updated: 2023/09/24 18:56:55 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_two_elements(t_stack_node **stack_a)
{
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
		{
			sa(stack_a);
		}
	}
}

void	sort_three_elements(t_stack_node **stack_a)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*c;

	a = *stack_a;
	b = (*stack_a)->next;
	c = (*stack_a)->next->next;
	if (a->value > b->value && b->value < c->value && a->value < c->value)
		sa(stack_a);
	else if (a->value > b->value && b->value > c->value && a->value > c->value)
		sa(stack_a);
	if (b->value > a->value && b->value > c->value && a->value > c->value)
		rra(stack_a);
	else if (a->value < b->value && b->value > c->value && a->value < c->value)
		sa(stack_a);
	if (a->value > b->value && b->value < c->value && a->value > c->value)
		ra(stack_a);
}

/* void	sort_five_elements(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*c;
	t_stack_node	*d;
	t_stack_node	*e;

	a = *stack_a;
	b = (*stack_a)->next;
	c = (*stack_a)->next->next;
	d = (*stack_a)->next->next->next;
	e = (*stack_a)->next->next->next->next;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_two_elements(stack_a);
	while (stack_b != NULL && c->value > b->value)
		pa(stack_b, stack_a);
	if (stack_b != NULL && a->value > b->value)
	{
		sb(stack_a);
		pa(stack_b, stack_a);
	}
	if (stack_b != NULL)
		pa(stack_b, stack_a);
	if (a->value > b->value)
		ra(stack_a);
} */

void	free_linked_list(t_stack_node **head)
{
	t_stack_node	*current;
	t_stack_node	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

/* void	merge(t_stack_node **stack_a, t_stack_node **stack_b, int left_size,
	int right_size)
{
	t_stack_node	*temp;
	t_stack_node	*next;

	temp = NULL;
	next = NULL;
	while (left_size > 0 && right_size > 0)
	{
		if ((*stack_a)->value < (*stack_b)->value)
		{
			pa(stack_a, &temp);
			left_size--;
		}
		else
		{
			pa(stack_b, &temp);
			right_size--;
		}
	}
	while (left_size > 0)
		pa(stack_a, &temp);
	while (*stack_b)
		pa(stack_b, &temp);
	while (temp)
		free_linked_list(&temp);
} */

/* int	stack_size(t_stack_node *stack)
{

	t_stack_node	*slow;

	size = 0;
	current = stack;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}
 */

void	merge_sort(t_stack_node **stack_a)
{
	t_stack_node	*a;
	t_stack_node	*b;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	find_middle(*stack_a, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*stack_a = sorted_merge(a, b);
}

t_stack_node	*sorted_merge(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*result;

	result = NULL;
	if (stack_a == NULL)
		return (stack_b);
	else if (stack_b == NULL)
		return (stack_a);
	if (stack_a->value <= stack_b->value)
	{
		result = stack_a;
		result->next = sorted_merge(stack_a->next, stack_b);
	}
	else
	{
		result = stack_b;
		result->next = sorted_merge(stack_a, stack_b->next);
	}
	return (result);
}

void	find_middle(t_stack_node *stack_a, t_stack_node **front_ref,
			t_stack_node **back_ref)
{
	t_stack_node	*slow;
	t_stack_node	*fast;

	slow = stack_a;
	fast = stack_a;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast ->next->next;
	}
	*front_ref = stack_a;
	*back_ref = slow->next;
	slow->next = NULL;
}

void push(t_stack_node **head_ref, int new_data)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		return ;
	new_node->value = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}









/* void	merge_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*slow;
	t_stack_node	*fast;
	t_stack_node	*prev;

	slow = *stack_a;
	fast = *stack_a;
	prev = NULL;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		return ;
	}
	while (fast != NULL && fast->next != NULL)
	{
		prev = slow;
		slow = slow->next;
		fast = fast ->next->next;
	}
	if (prev != NULL)
		prev->next = NULL;
	merge_sort(stack_a, stack_b);
	merge_sort(&slow, stack_b);
	while (*stack_b != NULL)
	{
		if (*stack_a != NULL && (*stack_b)->value < (*stack_a)->value)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else
		{
			sa(stack_a);
			ra(stack_a);
		}
	}
} */

/* void	sort_five_elements(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*c;
	t_stack_node	*d;
	t_stack_node	*e;

	a = *stack_a;
	b = (*stack_a)->next;
	c = (*stack_a)->next->next;
	d = (*stack_a)->next->next->next;
	e = (*stack_a)->next->next->next->next;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_three_elements(stack_a);
	if (stack_b != NULL)
	{
		if (b->value > c->value)
			sb(stack_b);
		pa(stack_b, stack_a);
	}
	if (a->value > b->value)
		ra(stack_a);
	if (stack_b != NULL)
		pa(stack_b, stack_a);
	if (a->value > b->value)
		ra(stack_a);
}
 */





