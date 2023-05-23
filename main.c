#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - main function.
 * @argc : argument count.
 * @argv : argument vector.
 *
 * Return: 0 on success
 */
int main(int argc __attribute__((unused)), char **argv)
{
char *prompt = ("$");
char *line = NULL;
size_t buffsize = 0;
ssize_t input_length;
int i;
while(1)
{
printf("%s", prompt);
input_length = (getline(&line, &buffsize, stdin) == -1);
if (feof(stdin))
{
free(line); /* avoid memory leaks when ctrl + d */
exit(EXIT_SUCCESS);
}
else
{
free(line);
perror("error while reading the line from stdin");
exit(EXIT_FAILURE);
}
}
return (0);
}
