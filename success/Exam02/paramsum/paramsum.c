#include <unistd.h>




int main(int argc, char **argv)
{
    int num;
    (void)argv;
    char    numChar;

    if (argc >= 2)
    {
        num = argc - 1;
        if (num >= 0 && num <= 9)
        {
            numChar = num + '0';
            write(1, &numChar, 1);
        }
        else 
        {
            while (num >= 0)
            {
                numChar = num % 10 + '0';
                write(1, &numChar, 1);
                num /= 10;
            }
        }
    }
    else if (argc == 1)
        write (1, "0", 1);    
    write (1, "\n", 1); 
    return (0);
}