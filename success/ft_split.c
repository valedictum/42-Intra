#include <stdlib.h>

static int countwords(char *str)
{
    int count = 0;
    int in = 0;

    while (*str)
    {
        if (*str != ' ' && !in)
        {
            in = 1;
            count ++;
        }
        else if (*str == ' ')
            in = 0;
        str++;
    }
    return (count);
}

static char *worddup(char *str)
{
    char    *word;
    int len = 0;

    while (str[len] && str[len] != ' ')
        len++;
    word = (char *)malloc(sizeof(char) * (len + 1));
    if (word == NULL)
        return (NULL);
    word[len] = '\0';
    while (len-- >= 0)
        word [len] = str[len];
    return (word);
} 

char    **ft_split(char *str)
{
    char **result;
    int count;
    int i;

    count = countwords(str);
    result = (char **)malloc(sizeof(char *) * (count + 1));
    if (result == NULL)
        return (NULL);
    i = 0;
    while (i < count)
    {
        while (*str == ' ')
            str++;
        if (*str)
            result[i++] = worddup(str);
        while (*str && *str != ' ')
            str++; 
    }
    result[i] = NULL;
    return (result);
}