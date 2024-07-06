#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/*
int main(void)
{
    int a = 2;
    int b = 9;

    printf("%d\n", a);
    ft_swap(&a, &b);
    printf("%d\n", a);
    return (0);
}
*/