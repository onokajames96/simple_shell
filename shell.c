#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * interactive_mode - UNIX command line interpreter
 *
 * Return: void
 */
void interactive_mode(void)
{
char *line;
char **args;
int status = -1;

while (1) {
printf("$");
line = read_line();
args = tokenize_line(line);
status = execute_args(args);
free(line);
free(args);
if (status >= 0) {
exit(status);
}
if (status != 0)
{
break;
}
}
}
