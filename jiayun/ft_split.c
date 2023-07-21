/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jong <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:02:06 by jong              #+#    #+#             */
/*   Updated: 2023/07/20 17:21:07 by jong             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*extract_word(char const **s, char c)
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

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (i < word_count)
	{
		result[i] = extract_word(&s, c);
		if (result[i] == NULL)
		{
			while (i > 0)
				free (result[i--]);
			free (result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
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
