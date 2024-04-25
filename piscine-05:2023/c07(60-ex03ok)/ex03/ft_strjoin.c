/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:25:52 by atang             #+#    #+#             */
/*   Updated: 2023/06/06 20:40:11 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*original_dest;

	original_dest = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}

int	ft_tot_len(int size, char **strs, char *sep)
{
	int	tot_len;
	int	i;

	tot_len = 0;
	i = 0;
	while (i < size)
	{
		tot_len += ft_strlen(strs[i]);
		if (i < size - 1)
			tot_len += ft_strlen(sep);
		i++;
	}
	return (tot_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		i;

	result = 0;
	if (size <= 0)
	{
		result = malloc(1);
		*result = '\0';
		return (result);
	}
	result = malloc(ft_tot_len(size, strs, sep) + 1);
	result[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
/*
int	main(void)
{
	char	*strs[] = {"Hi", "there", ",", "it", "is", "me", "."};
	char	sep[] = "***";
	int		size = 0;
	char	*result;

	result = ft_strjoin(size, strs, sep);
	printf("%s", result);
	free(result);
	return (0);
}
*/
