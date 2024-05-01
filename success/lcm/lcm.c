//#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int    n;

    n = 0;
    if (a == 0 || b == 0)
        return (0);
    if (n > a)
        n = a;
    else
        n = b;
    while (1)
    {
        if (n % a == 0 && n % b == 0)
            return (n);
        n++;
    }
}

/*
int main (void)
{
    unsigned int a = 3;
    unsigned int b = 5;

    printf("%d\n", lcm(a, b));
    return (0);
}
*/