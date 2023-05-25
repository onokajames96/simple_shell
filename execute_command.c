#include "shell.h"
/**
 *
 */
void exemycmd(char **argv)
{
char *cmd = NULL;
char *main_cmd = NULL;

if (argv)
{
cmd = argv[0];
main_cmd = get_path(cmd);
if (execve(main_cmd, argv, NULL) == -1)
{
perror("Error:");
}
}

}
