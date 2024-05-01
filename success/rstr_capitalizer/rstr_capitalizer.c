#include <unistd.h>

/*
int main(int argc, char **argv)
{
    int i = 0;
    int h = 1;

    if (argc >= 2)  
    {
        while (argv[h])
        {
            while (argv[h][i] != '\0')
            {
                while (argv[h][i] == ' ' || argv[h][i] == '\t')
                    i++;
                if (argv[h][i] >= 'A' && argv[h][i] <= 'Z')
                    argv[h][i] += 32;
                if ((argv[h][i] >= 'a' && argv[1][i] <= 'z') && (argv[h][i + 1] == ' ' || argv[h][i + 1] == '\t'))
                {
                    if (argv[h][i + 1] == ' ')
                    {
                        argv[1][i] -= 32;
                        write (1, &argv[1][i], 1);
                        write(1, " ", 1);
                        i++;
                        i++;
                    }
                    else
                    {
                        argv[1][i] -= 32;
                        i++;
                    }
                }
                write (1, &argv[1][i], 1);
                i++;
            }
            write(1, "\n", 1);
            h++;
        }
    }
    write (1, "\n", 1);
    return (0);
}
*/

void rstr_capitalizer(char*str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if ((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
            str[i] -= 32;
        write (1, &str[i], 1);
        i++;
    }
}

int main (int argc, char **argv)
{
    int i;

    if (argc == 1)
        write (1, "\n", 1);
    else if (argc >= 2)
    {
        i = 1;
        while (i < argc)
        {
            rstr_capitalizer(argv[i]);
            write (1, "\n", 1);
            i++;
        }
    }
    return (0);
}