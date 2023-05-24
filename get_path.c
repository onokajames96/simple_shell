#include "shell.h"
#include<unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
/**
 *get_path - Locate the full path of a command in the directories
 *           in listed in the PATH environment variable.
 *@cmd: name command  to locate.
 *
 * Return : On success, returns a pointer to the full path of the command
 *         if found, or a pointer to the command itself if it exists in the
 *         current working directory. Returns NULL if the command is not found.
 */
char *get_path(char *cmd)
{
char *path, *copy_of_path, *path_token, *path_file;
int cmd_length, dir_length;
struct stat buff;

path = getenv("PATH");

if (path)
{
copy_of_path = strdup(path);
cmd_length = strlen(cmd);
path_token = strtok(copy_of_path, ":");

while (path_token != NULL)
{
dir_length = strlen(path_token);
path_file = malloc(cmd_length + dir_length + 2);
strcpy(path_file, path_token);
strcat(path_file, "/");
strcat(path_file, cmd);
strcat(path_file, "\0");
if (stat(path_file, &buff) == 0)
{
free(copy_of_path);

return (path_file);
}
else
{
free(path_file);
path_token = strtok(NULL, ":");
}
}
free(copy_of_path);

if (stat(cmd, &buff) == 0)
{
return (cmd);
}
return (NULL);

}
return (NULL);
}
