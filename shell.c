#include "shell.h"

/**
 * main - pointer to enter of my proyect shimple shell
 *
 * Return: always cero.
 */
int main(/*int argc, char *argv[]*/ void)
{
	char *buffer = NULL;
	size_t size_buff = 0;
	size_t read_buff;

	pid_t child_id;
	int status;

	char *token;
	char **array;
	int i;

	size_t error_num = SIZE_MAX;

	for (;;)
	{
		_prompt();
		read_buff = getline(&buffer, &size_buff, stdin);

		if (read_buff == error_num)
		{
			perror("Exiting shell");
			exit(1);
		}

		token = strtok(buffer, " \n");
		array = malloc(sizeof(char *) * 1024);
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
			perror("Failed to create.");
			exit(41);
		}

		if (child_id == 0)
		{
			if (execve(array[0], array, NULL) == -1)
			{
				perror("Failed to execute");
				exit(97);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(buffer);
	return (0);
}
