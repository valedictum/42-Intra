/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:15:44 by atang             #+#    #+#             */
/*   Updated: 2023/07/21 17:56:06 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Function name
	ft_split

Prototype
	char **ft_split(char const *s, char c);

Parameters
	s: The string to be split.
	c: The delimiter character.

Return value
	The array of new strings resulting from the split.
	NULL if the allocation fails.

External functs.
	malloc, free

Description
	Allocates (with malloc(3)) and returns an array of strings obtained by 
	splitting ’s’ using the character ’c’ as a delimiter. The array must end 
	with a NULL pointer.
*/

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	word_count;
	int	inside_word;

	word_count = 0;
	inside_word = 0;
	while (*str)
	{
		if (*str == c)
			inside_word = 0;
		else if (!inside_word)
		{
			inside_word = 1;
			word_count++;
		}
		str++;
	}
	return (word_count);
}

static char	**ft_malloc_str(size_t size)
{
	char	**str;

	str = (char **)malloc(size * sizeof(char *));
	if (!str)
		return (NULL);
	return (str);
}

static char	*ft_newstrdup(const char *s1, size_t len)
{
	char	*str;
	int		i;

	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	int			word_count; 
	int			letter_index;
	char		**words;
	const char	*start;

	word_count = count_words(s, c);
	words = ft_malloc_str(word_count + 1);
	if (!words)
		return (NULL);
	letter_index = 0;
	start = s;
	while (*s)
	{
		if (*s == c)
		{
			if (s > start)
				words[letter_index++] = ft_newstrdup(start, s - start);
			start = s + 1;
		}
		s++;
	}
	if (s > start)
		words[letter_index++] = ft_newstrdup(start, s - start);
	words[letter_index] = (NULL);
	return (words);
}

int	main(void)
{
	char		str[] = "Testing,with,this,test,string";
	char		delimiter;
	int			word_count;
	int			i;
	char		**words;

	i = 0;
	word_count = 0;
	delimiter = ',';
	words = ft_split(str, delimiter);
	if (words != NULL)
	{
		word_count = count_words(str, delimiter);
		printf("Number of words: %d\n", word_count);
		while (i < word_count)
		{
			printf("Word %d: %s\n", i + 1, words[i]);
			free(words[i]);
			i++;
		}
		free(words);
	}
	else
		printf("Memory allocation failed.\n");
	return (0);
}
