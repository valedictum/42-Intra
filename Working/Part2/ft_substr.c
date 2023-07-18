/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:15:24 by atang             #+#    #+#             */
/*   Updated: 2023/07/18 16:31:06 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
char *ft_substr(char const *s, unsigned int start, size_t len);

Parameters
s: The string from which to create the substring. 
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.

Return value 
The substring.
NULL if the allocation fails.
 
Description
Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.
*/

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)