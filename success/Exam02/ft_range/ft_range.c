#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int i = 0;
    int *result = (int *)malloc(sizeof(int) * (abs(end - start) + 1));
    if (result == NULL)
        return (NULL);
    if (start <= end)
    {
        while (start <= end)
        {
            result[i] = start;
            start++;
            i++;
        }
    }
    else if (end <= start)
    {
        while (end <= start)
        {
            result[i] = start;
            start--;
            i++;
        }
    }
    return (result);
}