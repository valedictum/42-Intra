/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:40:48 by atang             #+#    #+#             */
/*   Updated: 2023/08/07 15:32:13 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Program name 
	libftprintf.a
Turn in files 
	Makefile, *.h, */*.h, *.c, */*.c
Makefile 
	NAME, all, clean, fclean, re
External functs.
	malloc, free, write, va_start, va_arg, va_copy, va_end
Libft authorized
	Yes
Description
	Write a library that contains ft_printf(), a function that will mimic the 
	original printf().
	
You have to recode the printf() function from libc. The prototype of ft_printf() is:
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
• Manage any combination of the following flags: ’-0.’ and the field minimum width under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space)

#include "libftprintf.h"

static void	ft_format_type(char fs)
{
	if (fs == 'c')
		ft_character();
	else if (fs == 's')
		ft_string();
	else if (fs =='p')
		ft_pointer();
	else if (fs =='d' || fs =='i')
		ft_integer();
	else if (fs =='u')
		ft_unsigned_integer();
	else if (fs =='x' || fs =='X')
		ft_hexadecimal();
	else if (fs =='%')
		write (1, "%", 1);
	else
		write (1, &fs, 1);
}

int	ft_printf(const char *input, ...)
{
	va_list	args_ptr;
	va_start(args_ptr, input)

	int	i;	
	int	total_characters;

	i = 0;
	total_characters = 0;

	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			i++;
			ft_format_type(input[i]);
		}
		else
		{
			write (1, &input[i],1);
			total_characters++;
		}
		i++;
	}
	va_end(args_ptr);
	return (total_characters);
}

int main(void)
{
    ft_printf("Hello, %s! The number is %d.\n", "world", 42);
    return (0);
}
