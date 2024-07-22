#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int err(char *str)
{
    while (*str)
        write(2, str++, 1);
    return 1;
}

int cd(char **argv, int i)
{
    if (i != 2)
        return err("Error: cd: Bad arguments\n");
    if (chdir(argv[1]) == -1)
        return err("Error: cd: can't change directory to: ");
    return 0;
}

int exec(char **argv, char **envp, int i)
{
    int fd[2];
    int status = 0;
    int has_pipe = argv[i] && !strcmp(argv[i], "|");

    if (!has_pipe && !strcmp(*argv, "cd"))
        return cd(argv, i);
    
    if (has_pipe && pipe(fd) == -1)
        return err("Error: fatal\n");

    int pid = fork();

    if (!pid)
    {
        argv[i] = 0;

        if(has_pipe && (dup2(fd[1], 1)  == -1 || close (fd[0]) == -1 || close (fd[1]) == -1))
            return err("Error: fatal\n");
        
        if(!strcmp(*argv, "cd"))
            return cd (argv, i);
        
        execve(*argv, argv, envp);
        
        return err("Error: cannot execute ");
    }

    waitpid(pid, &status, 0);

    if (has_pipe && (dup2(fd[0], 0) == -1 || close (fd[0]) == -1 || close (fd[1]) == -1))
        return err("Error: fatal\n");

    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main (int argc, char **argv, char **envp)
{
    int i = 0;
    int status = 0;

    (void)argc;

    while(argv[i] && argv[++i])
    {
        argv += i;
        i = 0;
        while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
            i++;
        if (i)
            status = exec(argv, envp, i);
    }
    return  status;
}