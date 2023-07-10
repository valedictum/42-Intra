#include "libft.h"

int ft_isalpha(int i)
{
    if ((i >= 'a' && <= 'z') || (i >= 'A' && <= 'Z'))
        return (1);
    return (0);
}