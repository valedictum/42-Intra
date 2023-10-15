/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:28:03 by fsalimba          #+#    #+#             */
/*   Updated: 2023/04/29 11:28:05 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_int(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len += ft_put_str(num);
	free(num);
	return (len);
}

int	ft_put_uint(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_uitoa(n);
	len += ft_put_str(num);
	free(num);
	return (len);
}
