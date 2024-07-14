#include <unistd.h>  // Needed for system calls such as write, chdir, fork, etc.
#include <sys/wait.h>  // Needed for waitpid
#include <string.h>  // Needed for strcmp

// Function to print an error message to the standard error stream
int err(char *str)
{
    // Print each character of the error message to the standard error stream
    while (*str)
        write(2, str++, 1);
    return 1;
}

// Function to change the current working directory
int cd(char **argv, int i)
{
    // If the number of arguments is not 2, print an error message and return 1
    if (i != 2)
        return err("error: cd: bad arguments\n");
    
    // Attempt to change the current working directory to the directory specified by the argument
    if (chdir(argv[1]) == -1)
        return err("error: cd: cannot change directory to "), err(argv[1]), err("\n");
    
    // If the directory was successfully changed, return 0
    return 0;
}

// Function to execute a command or sequence of commands
int exec(char **argv, char **envp, int i)
{
    int fd[2];  // Array to hold file descriptors for pipes
    int status;  // Variable to hold the exit status of the executed command
    int has_pipe = argv[i] && !strcmp(argv[i], "|");  // Flag to indicate if a pipe is used

    // If the command does not use a pipe and is not a "cd" command, call the "cd" function and return its result
    if (!has_pipe && !strcmp(*argv, "cd"))
        return cd(argv, i);

    // If a pipe is used and attempting to create a pipe fails, print an error message and return 1
    if (has_pipe && pipe(fd) == -1)
        return err("error: fatal\n");

    int pid = fork();  // Create a new child process
    
    // If the child process could not be created, print an error message and return 1
    if (!pid)
    {
        argv[i] = 0;  // Set the argument after the pipe symbol to NULL
        
        // If a pipe is used, redirect the output of the child process to the write end of the pipe and close the read and write ends of the pipe
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return err("error: fatal\n");
        
        // If the command is a "cd" command, call the "cd" function and return its result
        if (!strcmp(*argv, "cd"))
            return cd(argv, i);
        
        // Execute the command with the specified arguments and environment variables
        execve(*argv, argv, envp);
        
        // If the command could not be executed, print an error message and return 1
        return err("error: cannot execute "), err(*argv), err("\n");
    }

    waitpid(pid, &status, 0);  // Wait for the child process to exit and store its exit status in the "status" variable
    
    // If a pipe is used, redirect the input of the parent process to the read end of the pipe and close the read and write ends of the pipe
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return err("error: fatal\n");
    
    // If the command executed successfully, return the exit status of the command
    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char **argv, char **envp)
{
    int    i = 0;  // Variable to hold the current index in the argument array
    int    status = 0;  // Variable to hold the exit status of the executed commands

    (void)argc;  // Ignore the value of argc (the number of command-line arguments)
    
    // Loop through the arguments until the end of the argument array is reached
    while (argv[i] && argv[++i])
    {
        argv += i;  // Move the argument pointer to the current argument
        i = 0;  // Reset the index to 0
        
        // Loop through the arguments until a pipe symbol or a semicolon is reached
        while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
            i++;
        
        // If a non-zero number of arguments was found, call the "exec" function and store its result in the "status" variable
        if (i)
            status = exec(argv, envp, i);
    }
    
    // Return the exit status of the executed commands
    return status;
}
