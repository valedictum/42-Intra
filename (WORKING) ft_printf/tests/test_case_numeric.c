/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_case_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:12:26 by atang             #+#    #+#             */
/*   Updated: 2023/08/13 18:12:56 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Numeric Edge Cases (test_case_numeric.c) */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	test_case_numeric(void)
{
	int	printed_chars;

	printf("Testing %%d and %%i:\n");
	ft_printf("Expected: -42\n");
	printed_chars = ft_printf("%d\n", -42);
	printf("ft_printf returned: %d\n\n", printed_chars);

	printf("Testing %%u:\n");
	ft_printf("Expected: 123456\n");
	printed_chars = ft_printf("%u\n", 123456);
	printf("ft_printf returned: %d\n\n", printed_chars);

	printf("Testing %%x and %%X:\n");
	ft_printf("Expected: 1a3F\n");
	printed_chars = ft_printf("%x\n", 6719);
	printf("ft_printf returned: %d\n", printed_chars);
	ft_printf("Expected: 1A3F\n");
	printed_chars = ft_printf("%X\n", 6719);
	printf("ft_printf returned: %d\n\n", printed_chars);
}
