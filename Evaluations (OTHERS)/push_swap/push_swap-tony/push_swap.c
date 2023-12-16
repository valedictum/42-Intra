/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:22:50 by tluanamn          #+#    #+#             */
/*   Updated: 2023/11/26 10:10:49 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int **a, int *size_a, int **b, int *size_b)
{
	if (*size_a == 2)
		sort_two(a, size_a);
	if (*size_a == 3)
		sort_three(a, size_a);
	if (*size_a > 3 && *size_a <= 5)
		sort_five(a, size_a, b, size_b);
	if (*size_a > 5)
		sort_complex(a, size_a, b, size_b);
}
