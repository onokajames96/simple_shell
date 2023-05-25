#include "shell.h"

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
char *line = NULL, *line_copy = NULL;
char *token;
size_t buffsize = 0;
ssize_t input_length;
int i;
int count_tokens = 0;
while (1)
{
printf("%s", prompt);
input_length = getline(&line, &buffsize, stdin);

if (input_length == -1)
{
printf("exit shell...\n");
return (-1);
}
line_copy = malloc(sizeof(char) * input_length);
if (line_copy == NULL)
{
perror("memory allocation error");
return (-1);
}
strcpy(line_copy, line);
token = strtok(line, TOKEN_DELIM);
while (token != NULL)
{
count_tokens++;
token = strtok(NULL, TOKEN_DELIM);
}
count_tokens++;
argv = malloc(sizeof(char *) * count_tokens);
token = strtok(line_copy, TOKEN_DELIM);
for (i = 0; token != NULL; i++)
{
argv[i] = malloc(sizeof(char) * strlen(token));
strcpy(argv[i], token);
token = strtok(NULL, TOKEN_DELIM);
}
free(line_copy);
free(line);
}
return (0);
}
