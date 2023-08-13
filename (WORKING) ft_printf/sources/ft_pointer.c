/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:04:44 by atang             #+#    #+#             */
/*   Updated: 2023/08/13 13:55:57 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_pointer(void *ptr, int *char_count)
{
	ft_character('0', char_count);
	ft_character('x', char_count);
	ft_hexadecimal((unsigned long long)ptr, 0, char_count);
}
