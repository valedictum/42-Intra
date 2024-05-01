#include <stdlib.h>

char	*ft_itoa(int nbr)
{
    int num;
    int len;
    char *result;

    num = nbr;
    len = 0;
    if (num < 0)
    {
        len++;
        num = -num;
    }
    while (num)
    {
        num /= 10;
        len++;
    }
    num = nbr;
    result = (char *)malloc (sizeof(char) * (len + 1));
    if (result == NULL)
        return (NULL);
    if (num == 0)
    {
        result [0] = '0';
    }
    else if (num < 0)
    {
        result [0] = '-';
        num = -num;
    }
    len--;
    while (num)
    {
        result[len] = num % 10 + '0';
        num /= 10;
        len--;
    }
    return (result);
}