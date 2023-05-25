#include "main.h"

/**
 * execute_args - checks command is a builtin or a process.
 * @args: command and its flags
 *
 * Return: 1 on sucess, 0 otherwise
 */
int execute_args(char **args)
{
char *list_funcs_builtin[] = 
{
"cd",
"env",
"help",
"exit"
};
int (*builtin_func[])(char **) = 
{
&hsh_cd,
&hsh_env,
&hsh_help,
&hsh_exit
};
long unsigned int j = 0;

if (args[0] == NULL)
{

return (-1);
}
for (; j < sizeof(list_funcs_builtin) / sizeof(char *); j++)
{

if (strcmp(args[0], list_funcs_builtin[j]) == 0)
{
return ((*builtin_func[j])(args));
}
}
return (new_fork(args));
}
