/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:40:48 by atang             #+#    #+#             */
/*   Updated: 2023/08/13 15:56:44 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Program name 
	libftprintf.a
Turn in files 
	Makefile, *.h, star/star.h, *.c, star/star.c
Makefile 
	NAME, all, clean, fclean, re
External functs.
	malloc, free, write, va_start, va_arg, va_copy, va_end
Libft authorized
	Yes
Description
	Write a library that contains ft_printf(), a function that will mimic the 
	original printf().
	
You have to recode the printf() function from libc. The prototype of ft_printf()
is:
int ft_printf(const char *, ...);

Here are the requirements:
• Don’t implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Your function will be compared against the original printf().
• You must use the command ar to create your library.
Using the libtool command is forbidden.
• Your libftprintf.a has to be created at the root of your repository.
You have to implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format. 
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

Bonus list:
• Manage any combination of the following flags: ’-0.’ and the field minimum 
width under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space) */

#include "../includes/ft_printf.h"

static int	ft_format_type(char fs, va_list *args_ptr)
{
	int	char_count;

	char_count = 0;
	if (fs == 'c')
		ft_character(va_arg(*args_ptr, int), &char_count);
	else if (fs == 's')
		ft_string(va_arg(*args_ptr, char *), &char_count);
	else if (fs == 'p')
		ft_pointer((void *)va_arg(*args_ptr, unsigned long), &char_count);
	else if (fs == 'd' || fs == 'i')
		ft_integer(va_arg(*args_ptr, int), &char_count);
	else if (fs == 'u')
		ft_unsigned_decimal(va_arg(*args_ptr, unsigned int), &char_count);
	else if (fs == 'x')
		ft_hexadecimal(va_arg(*args_ptr, unsigned int), 0, &char_count);
	else if (fs == 'X')
		ft_hexadecimal(va_arg(*args_ptr, unsigned int), 1, &char_count);
	else if (fs == '%')
		ft_character ('%', &char_count);
	else
		ft_character (fs, &char_count);
	return (char_count);
}

int	ft_printf(const char *string, ...)
{
	va_list	args_ptr;
	int		printed_chars;
	int		i;

	va_start(args_ptr, string);
	printed_chars = 0;
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			printed_chars += ft_format_type(string[i], &args_ptr);
		}
		else
		{
			ft_character((char)string[i], &printed_chars);
			i++;
		}
	}
	va_end(args_ptr);
	return (printed_chars);
}

int	main(void)
{
	int	printed_chars;

	printf("Expected: Hello, World!\n");
	printed_chars = ft_printf("Hello, %c!\n", 'W');
	printf("ft_printf returned: %d\n\n", printed_chars);
	printf("Expected: Testing newline:\nnew\nline\n");
	printed_chars = ft_printf("Testing newline:\n%c\n%c\n", 'n', 'l');
	printf("ft_printf returned: %d\n\n", printed_chars);
	return (0);
}
