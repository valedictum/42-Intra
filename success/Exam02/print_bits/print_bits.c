#include <unistd.h>

void	print_bits(unsigned char octet)
{
    unsigned char bit;
    int           i;

    i = 8;
    while (i > 0)
    {
        bit = (octet >> (i - 1)) & 1;
        if (bit == 0)
            write (1, "0", 1);
        else 
            write (1, "1", 1);
        i--;
    }              
}

/*
int main()
{
    unsigned char octet;
    octet = 2;
    print_bits(octet);
    return (0);
}
*/