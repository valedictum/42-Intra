/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:39:58 by mickim            #+#    #+#             */
/*   Updated: 2023/04/03 18:37:33 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static int	_ft_wordcount(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	return (count);
}

static char	*_get_next_word(const char **s, char c)
{
	const char	*start = *s;
	char		*word;
	size_t		len;

	while (**s && **s != c)
	{
		(*s)++;
	}
	len = *s - start;
	word = ft_strndup(start, len);
	if (!word)
	{
		return (NULL);
	}
	if (**s)
	{
		(*s)++;
	}
	return (word);
}

static void	_ft_free_strarr(char **arr, size_t len)
{
	size_t	i;

	if (!arr)
	{
		return ;
	}
	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		count;
	int		i;

	count = _ft_wordcount(s, c);
	str = (char **)malloc((count + 1) * sizeof(char *));
	if (!str || !s)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			str[i] = _get_next_word(&s, c);
			if (!str[i++])
			{
				_ft_free_strarr(str, i);
				return (NULL);
			}
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}
