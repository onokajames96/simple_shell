#include "main.h"

/**
 * new_fork - creation of  a new process.
 * @args: is an array of strings representing command and its flags.
 *
 * Return: 1 on  success, otherwise 0.
 */
int new_fork(char **args)
{
pid_t pid;
int status;

pid = fork();
if (pid ==  0)
{

if (execvp(args[0], args) == -1)
{
perror("error");
}
exit(EXIT_FAILURE);
}
else if (pid <0)
{
perror("error");
}
else
{
do 
{
waitpid(pid, &status, WUNTRACED);
}
while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (-1);
}
