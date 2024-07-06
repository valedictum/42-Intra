#include <stdlib.h>
#include <stdio.h>

int is_prime(int    num)
{
    int i = 2;

    if (num < 2)
        return (0);
    while (i * i <= num)
    {
        if (num % i == 0)
            return (0)
        i++;
        return (1)
    }
}

int main (int argc, char **argv)
{
    int num;
    int divisor;

    if (argc == 2)
    {
        num = atoi(argv[1]);
        divisor = 2;
        while (num > 1)
        {
            if (num % divisor == 0)
                num /= divisor;
            else
                divisor++;
        }
        printf("%d\n", divisor);
    }
}
