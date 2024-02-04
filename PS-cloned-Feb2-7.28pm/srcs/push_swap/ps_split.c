/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:35:02 by atang             #+#    #+#             */
/*   Updated: 2024/01/28 16:23:20 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
// TAKEN FROM LIBFT
int	count_words(char const *s, char c)
{
	int	count;
	int	in_word_flag;

	count = 0;
	in_word_flag = 0;
	while (*s)
	{
		if (*s == c)
			in_word_flag = 0;
		else if (in_word_flag == 0)
		{
			in_word_flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	*extract_word(char const **s, char c)
{
	char	*word;
	int		word_len;
	int		i;

	word_len = 0;
	while (**s && **s == c)
		(*s)++;
	while ((*s)[word_len] && (*s)[word_len] != c)
		word_len++;
	word = (char *)malloc((word_len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < word_len)
	{
		word[i] = (*s)[i];
		i++;
	}
	word[word_len] = '\0';
	*s += word_len;
	return (word);
}

void	free_words(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	ft_printf("Word count: %d\n", word_count);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		result[i] = extract_word(&s, c);
		if (!result[i])
		{
			free_words(result);
			free(result);
			return (NULL);
		}
		ft_printf("Extracted word %d: %s\n", i, result[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}
*/

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;
	int		i;
	int		start;
	int		word_len;

	word_count = 0;
	i = 0;
	start = 0;
	if (s == NULL)
		return (NULL);
	while (s[start])
	{
		if (s[start] != c)
		{
			word_count++;
			while (s[start] && s[start] != c)
				start++;
		}
		else
			start++;
	}
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	start = 0;
	i = 0;
	while (s[start])
	{
		if (s[start] != c)
		{
			word_len = 0;
			while (s[start + word_len] && s[start + word_len] != c)
				word_len++;
			result[i] = (char *)malloc((word_len + 1) * sizeof(char));
			if (result[i] == NULL)
			{
				while (i > 0)
					free(result[--i]);
				free(result);
				return (NULL);
			}
			ft_strlcpy(result[i], &s[start], word_len);
			result[i][word_len] = '\0';
			i++;
			start += word_len;
		}
		else
			start++;
	}
	result[i] = NULL;
	return (result);
}
