#include <stdio.h>

int	ft_atoi(const char *str)
{
    int     result;
    int     i;
    int     sign;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;    
    }
    return (result * sign);
}

/*
int main(void)
{
    char    str[] = "  -14253";

    printf("%s\n", str);
    printf("%d\n", ft_atoi(str));
    return (0);
}
*/