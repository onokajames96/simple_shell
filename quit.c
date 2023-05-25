#include "main.h"
/**
 *tsh_exit - process termination.
 *
 * Return: 0 process termination.
 */
int tsh_exit(char **args)
{
if (args[1])
{
return (atoi(args[1]));
}
else
{
return (0);
}
}
