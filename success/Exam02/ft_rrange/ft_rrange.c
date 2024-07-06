#include <stdlib.h>

char	*ft_itoa(int nbr)
{
    int num;
    int len;
    int i;

    num = nbr;
    len = 0;
    if (nbr == -2147483648)
        return ("-2147483648");
    if (num <= 0)
        len++;
    while (num)
    {
        num/= 10;
        len++;
    }
    char *result= (char *)malloc(sizeof(char) * (len  + 1));
    if (result == NULL)
        return (NULL);
    num = nbr;
    if (num == 0)
    {
        result[0] = '0';
        result[1] = '\0';
        return(result);
    }
    if (num < 0)
    {
        result[0] = '-';
        num = -num;
    }
    result[len] = '\0';
    len--;
    while (num)
    {
        result[len] = num % 10 + '0';
        num /= 10;
        len--;
    }
    return(result);
}

/*
int main()
{
    return(0);
}
*/