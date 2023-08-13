/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:01:46 by atang             #+#    #+#             */
/*   Updated: 2023/08/13 18:07:56 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	test_case_basic(void);
void	test_case_numeric(void);
void	test_case_string(void);


int	main(void)
{
	int	printed_chars;

	printed_chars = 0;
	printf("Testing %%c:\n");
	ft_printf("Expected: Hello, World!\n");
	printed_chars = ft_printf("Hello, W%c!\n", 'c');
	printf("ft_printf returned: %d\n\n", printed_chars);
	printf("Testing %%s:\n");
	ft_printf("Expected: Testing newline:\nnew\nline\n");
	printed_chars = ft_printf("Testing newline:\n%s\n%s\n", "new", "line");
	printf("ft_printf returned: %d\n\n", printed_chars);
	printf("Testing %%p:\n");
	ft_printf("Expected: Pointer address: (nil)\n");
	printed_chars = ft_printf("Pointer address: %p\n", NULL);
	printf("ft_printf returned: %d\n\n", printed_chars);
	printf("All tests completed.\n");
	return (0);
}



