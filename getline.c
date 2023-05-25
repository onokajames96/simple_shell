#include "main.h"

/**
 * Read_line - line read from stdin
 *
 * Return: pointer that points to a str with the line content
 */
char *rd_line(void)
{
char *line = NULL;
size_t bufsize = 0;
ssize_t chars_read;

chars_read = getline(&line, &bufsize, stdin);
if (chars_read == -1)
{
if (feof(stdin))
{
free(line);
exit(EXIT_SUCCESS);
}
 else
{
free(line);
perror("error ");
exit(EXIT_FAILURE);
}
}
return (line);
}
