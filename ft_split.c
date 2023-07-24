/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:15:28 by atang             #+#    #+#             */
/*   Updated: 2023/07/24 18:24:13 by atang            ###   ########.fr       */
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

/*
	- count_words used to count the number of words in the input string. 
	The inside_word variable keeps track of whether the current character is 
	inside a word (i.e., not a delimiter). Whenever a delimiter is encountered, 
	inside_word is set to 0, and when it finds the start of a new word 
	(a non-delimiter followed by a delimiter), word_count is incremented.
	- newstrdup for new string of length len + 1 and copies the characters 
	from s1 to the new string
	- count_words, then malloc (+ 1), then iterates through s, and whenever 
	it encounters the delimiter character c, a new substring is created using 
	ft_newstrdup function (if non-delimiter characters before delimiter) and stored
	as substring in the words array at the appropriate index.
	- if there are non-delimiter characters remaining at the end of the string, 
	last substring created and added to the words array.
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

static char	*ft_newstrdup(const char *s1, int len)
{
	char	*str;
	int		i;

	str = (char *)malloc((len + 1) * sizeof(char));
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
/*
int main(void)
{
    char const *s = "Hello,world,this,is,a,test";
    char c = ',';

    char **result = ft_split(s, c);
    if (result == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int i = 0;
    while (result[i] != NULL)
    {
        printf("%s\n", result[i]);
        free(result[i]);
        i++;
    }
    free(result);

    return 0;
}
*/
