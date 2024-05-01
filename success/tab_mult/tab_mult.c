#include <unistd.h>


int atoi(char *str)
{
    int i = 0;
    int result = 0;
    int sign = 1;

    if (str[i] == '-')
        sign = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (sign * result);
}

void putchr(char c)
{
    write (1, &c, 1);
}

void putnum(int num)
{
    if (num < 0)
    {
        putchr('-');
        num = -num;
    }
    if (num > 9)
        putnum(num / 10);
    putchr(num % 10 + '0');
}

int main (int argc, char **argv)
{
    int i;
    int j;
    int k;

    if (argc == 2)
    {
        i = atoi(argv[1]);
        j = 1;
        while (j <= 9)
        {
            putnum(j);
            write (1, " x ", 3);
            putnum(i);
            write (1, " = ", 3);
            k = i * j;
            putnum(k);
            write (1, "\n", 1);
            j++;   
        }
    }
    else
        write (1, "\n", 1);
}