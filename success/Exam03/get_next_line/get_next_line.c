#include "get_next_line.h"

char*get_next_line(int fd)
{
/* declare variables */
int i = 0;
int rd = 0;
char character;

/* check BUFFER_SIZE error */
if (BUFFER_SIZE <= 0)
return (NULL);

/* malloc buffer 100k */
char*buffer = malloc(100000);

/* while loop */
/* read parameters: file descriptor (fd), pointer to buffer where read data will be stored (&character), how many bytes to read (BUFFER_SIZE - BUFFER_SIZE + 1) */
while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
{
buffer[i++] = character;
if (character == '\n')
break;
}

/* terminate string after '\n' or end of file */
buffer[i] = '\0';

/* check errors */
/* read error: read will return -1 so rd == -1, no characters read: i == 0, end of file: buffer[i - 1] will be '\0' so buffer[i - 1] == '\0' of !buffer[i - 1] and rd will be 0 so rd == 0 or !rd */
if (rd == -1 || i == 0 || (!buffer[i-1] && !rd))
return (free(buffer), NULL);

/* return buffer */
return (buffer);
}