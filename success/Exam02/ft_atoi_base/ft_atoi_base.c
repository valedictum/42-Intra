#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int result = 0;
    int sign = 1;
    char    c;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] != '\0')
    {
        c = str[i];
        if (c >= '0' && c <= '9')
            result = result * str_base + (c - '0');
        else if (c >= 'A' && c <= 'F')
            result = result * str_base + (c - 'A' + 10);
        else if (c >= 'a' && c <= 'f')
            result = result * str_base  + (c - 'a' + 10);
        else
        {
            i++;
            continue ;
        }
        i++;  
    } 
    return (result * sign);
}

int main(void)
{
    char    str[] = "Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base.";
    int     result = ft_atoi_base(str, 16);
    printf("%d\n", result);
    return (0);    
}
