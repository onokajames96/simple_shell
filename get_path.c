#include "shell.h"
#include <stdlib.h>

char *get_path(char *Cmd){
char *path, *copy_of_path, *path_token, *path_file;
int Cmd_length, dir_length;
struct stat buff;
    
path = getenv("PATH");

if (path)
{
copy_of_path = strdup(path);
Cmd_length = strlen(Cmd);
path_token = strtok(copy_of_path, ":");

while(path_token != NULL)
{
dir_length = strlen(path_token);
path_file = malloc(Cmd_length + dir_length + 2);
strcpy(path_file, path_token);
strcat(path_file, "/");
strcat(path_file, Cmd);
strcat(path_file, "\0");
if (stat(path_file, &buff) == 0)
{
free(copy_of_path);

return (path_file);
}
else{
free(path_file);
path_token = strtok(NULL, ":");
}        
}
free(copy_of_path);

if (stat(Cmd, &buff) == 0)
{

return (Cmd);
}
return (NULL);
    
}

return (NULL);
}
