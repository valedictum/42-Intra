/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:05:11 by jlyu              #+#    #+#             */
/*   Updated: 2023/07/29 15:12:33 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_conversion(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_chr(va_arg(args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (c == 'p')
		return (ft_print_point(va_arg(args, unsigned long long)));
	if (c == 'd' || c == 'i')
		return (ft_print_dec(va_arg(args, int)));
	if (c == 'u')
		return (ft_print_undec(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (print_long_hexa(va_arg(args, unsigned int), c));
	if (c == '%')
		return (ft_print_chr('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		num_char;

	num_char = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			num_char += ft_print_conversion(*format, args);
		}
		else
		{
			ft_print_chr(*format);
			num_char++;
		}
		format++;
	}
	va_end(args);
	return (num_char);
}

// #include <limits.h>
// # include <stdio.h>
// int main() {
// 	// int x = 42;
// 	// int *ptr = &x;
// 	printf("printf: %d\n", printf("%c %c %c", '0', 0, '1'));
// 	printf("ft: %d\n", ft_printf("%c %c %c", '0', 0, '1'));
// }