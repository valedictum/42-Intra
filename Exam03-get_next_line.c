#include "get_next_line.h"

char *get_next_line(int fd)
{
    int i = 0;
    int rd = 0;
    char    character;
    char    *buffer;

    if (BUFFER_SIZE <= 0)
        return (NULL);
    buffer = malloc(100000);
    if (!buffer)
        return (NULL);
    while ((rd = read(fd, &character, 1)) > 0)
    {
        buffer [i++] = character;
        if (character == '\n')
            break;
    }
    buffer[i] = '\0';
    if (rd == -1 || i == 0)
    {
        free(buffer);
        return (NULL);
    }
    return (buffer);
}

/*
int main (void)
{
    return (0);
}
*/
