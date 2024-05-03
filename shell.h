#ifndef _SHELL_H
#define _SHELL_H

/*libraries in use*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/errno.h>


void _prompt(void);
char *_getline(void);
void execute_command(char *buffer);
size_t custom_strcspn(const char *str, const char *reject);
int _strcmp(const char *str1, const char *str2);
void print_environment();

#endif
