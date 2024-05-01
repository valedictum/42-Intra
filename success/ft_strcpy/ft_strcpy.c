//#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}
/*
int main(void)
{
    char str[] = "Hello";
    char str2[] = "World";
    printf("%s\n", str);
    ft_strcpy(str, str2);
    printf("%s\n", str);
    return (0);
}
*/