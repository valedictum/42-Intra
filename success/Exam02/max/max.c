//#include <unistd.h>
//#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    int             max;
    unsigned int    i = 0;

    if (len == 0)
        return (0);
    max = tab[0];
    while (i < len)
    {
        if (tab[i] > max)
        {
            max = tab[i];
        }
        i++;
    }
    return (max);
}

/*
int main(void)
{
    int array[4] = {10, 20, 30, 40};
    int maxm = max(array, 4);

    printf("%d\n", maxm);
    return (0);
}
*/