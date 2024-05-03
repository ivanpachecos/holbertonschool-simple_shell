#include "shell.h"

/**
 * get_line - Reads a line from stdin.
 *
 * Return: A pointer to the read line.
 */
char *_getline()
{
    char *buff = NULL;
    size_t size_buff = 0;
    ssize_t read_buff;

    /* Get bytes */
    read_buff = getline(&buff, &size_buff, stdin);

    if (read_buff == -1)
    {
        free(buff);
        exit(EXIT_SUCCESS);
    }

    return (buff);
}
