#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    int n1;
    int n2;

    if (argc == 3)
    {
        n1 = atoi(argv[1]);
        n2 = atoi(argv[2]);
        if (n1 > 0 && n2 > 0)
        {
            while (n1 != n2)
            {
                if (n1 > n2)
                    n1 -= n2;
                else
                    n2 -= n1;
            }
            printf("%d\n", n1);
        }
    }
    else 
        printf("\n");
    return (0);
}