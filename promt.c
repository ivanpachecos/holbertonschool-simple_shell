#include "shell.h"

/**
 * _prompt - Prints the shell prompt
 *
*/
void _prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$: ", 11);
}

