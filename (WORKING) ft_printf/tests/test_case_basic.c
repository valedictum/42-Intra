/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_case_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:12:07 by atang             #+#    #+#             */
/*   Updated: 2023/08/13 18:12:58 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Basic Test Cases (test_case_basic.c) */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	test_case_basic(void)
{
	int	printed_chars;

	printf("Testing %%c:\n");
	ft_printf("Expected: Hello, World!\n");
	printed_chars = ft_printf("Hello, World!");
	printf("ft_printf returned: %d\n", printed_chars);
}
