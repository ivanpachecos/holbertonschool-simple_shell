#include "shell.h"

/**
 * main - pointer to enter of my proyect shimple shell
 *
 * Return: always cero.
 */
int main(/*int argc, char *argv[]*/ void)
{
	char *buffer = NULL;

	for (;;)
	{
		_prompt();
		
		buffer = _getline();

		if (buffer == NULL)
		{
			free(buffer);
			break;
		}

		if (_strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			return (0);
		}
		if (_strcmp(buffer, "env\n") == 0)
		{
			print_environment();
			continue;
		}
		if (buffer[0] == '\n')
			continue;

		buffer[custom_strcspn(buffer, "\n")] = '\0';

		execute_command(buffer);
		free(buffer);
	}
	return (0);
}
