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

	size_t error_num = SIZE_MAX;

	while (1)
	{
		_prompt();
		read_buff = getline(&buffer, &size_buff, stdin);

		if (read_buff == error_num)
		{
			perror("Exiting shell");
			exit(1);
		}

		printf("%s", buffer);
	}
	
	free(buffer);
	return (0);
}
