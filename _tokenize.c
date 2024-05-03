#include "shell.h"

/**
 * execute_command - Tokenizes and executes the command
 * @buffer: The input string to be tokenized and executed
 */
void execute_command(char *buffer)
{
    char *token;
    char **array;
    int i;
    pid_t child_id;
    int status;

    token = strtok(buffer, " \n");
    array = malloc(sizeof(char *) * 1024);
    if (array == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    i = 0;

    while (token)
    {
        array[i] = token;
        token = strtok(NULL, " \n");
        i++;
    }

    array[i] = NULL;

    child_id = fork();
    if (child_id == -1)
    {
        perror("Failed to create child process");
        free(array);
        exit(EXIT_FAILURE);
    }

    if (child_id == 0)
    {
        if (execve(array[0], array, NULL) == -1)
        {
            fprintf(stderr, "%s: command not found\n", array[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        wait(&status);
    }

    free(array);
}
