#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        int i;
        int j;
        
        i = 0;
        j = 0;
        while (argv[1][i] != '\0')
        {
            if (argv[2][1])
                break ;
            if (argv[1][i] == argv[2][j])
            {
                argv[1][i] = argv[3][j];
                write(1, &argv[1][i], 1);
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);    
    return (0);
}
