#include "main.h"

/**
 * tsh_env - prints enviroment variables
 * @args: arguments
 *
 * Return: 1 on success, 0 otherwise
 */
int tsh_env(char **args)
{
int j;
(void)(**args);

for (j = 0; environ[j] != NULL; j++)
{
write(STDOUT_FILENO, environ[j], strlen(environ[j]));
write(STDOUT_FILENO, "\n", 1);
}

return (-1);
}
