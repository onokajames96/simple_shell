#include "main.h"

/**
 * tokenize_line - split string into multiple strings
 * @line: splited string
 *
 * Return: pointer to the new array
 */
char **tokenize_line(char *line)
{
int buffersize = 64;
int j = 0;
char **tokens = malloc(buffersize * sizeof(char *));
char *token;

if (!tokens)
{
fprintf(stderr, "allocation error: tokens\n");
exit(EXIT_FAILURE);
}
token = strtok(line, TOKEN_DELIM);
while (token != NULL)
{
if (token[0] == '#')
{
break;
}
tokens[j] = token;
j++;
if (j >= buffersize)
{
buffersize += buffersize;
tokens = realloc(tokens, buffersize * sizeof(char *));
if (!tokens)
{
fprintf(stderr, "reallocation error: tokens");
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, TOKEN_DELIM);
}
tokens[j] = NULL;
return (tokens);
}
