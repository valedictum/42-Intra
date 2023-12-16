/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:17:20 by tluanamn          #+#    #+#             */
/*   Updated: 2023/11/26 10:10:37 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

//sorting
void	push_swap(int **a, int *size_a, int **b, int *size_b);
void	sort_two(int **a, int *size_a);
void	sort_three(int **a, int *size_a);
void	sort_five(int **a, int *size_a, int **b, int *size_b);
void	find_and_push_smallest(int **a, int *size_a, int **b, int *size_b);
int		find_smallest_index(int *array, int size);
void	sort_complex(int **a, int *size_a, int **b, int *size_b);
void	copy_stack(int *copy_a, int *copy_a_ref, int **a, int *size_a);
void	bubble_sort(int *array, int *size);
void	reassign(int **a, int *size_a, int *copy_a, int *copy_a_ref);
void	sort_bit(int **a, int *size_a, int **b, int *size_b);

//push
void	pa(int **a, int *size_a, int **b, int *size_b);
void	pb(int **a, int *size_a, int **b, int *size_b);

//rotate
void	ra(int **a, int *size_a);
void	rb(int **b, int *size_b);
void	rr(int **a, int *size_a, int **b, int *size_b);

//reverse
void	rra(int **a, int *size_a);
void	rrb(int **b, int *size_b);
void	rrr(int **a, int *size_a, int **b, int *size_b);

//swap
void	sa(int **a);
void	sb(int **b);
void	ss(int **a, int **b);

//utility function
long	ft_atoi(const char *str);
void	init_stack(int **stack, int *size, int capacity, char **temp);
char	**ft_split(const char *s, char c);
void	check_if_sort(int *arr, int size);

//check error
void	check_ac(int ac);
int		is_valid_number(const char *str);
void	check_valid_input(char **str, int ac, int *capacity, char ***temp);
void	check_number(long num);
void	check_duplicate(int *arr, int capacity);

#endif
