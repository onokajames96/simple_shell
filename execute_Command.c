#include "shell.h"
void execute_command(char **argv)
{
    char *command = NULL, *command_path = NULL;

    if (argv){
        /* get the command */
        command = argv[0];

        /* generate the path to this command before passing it to execve */
        command_path = get_path(command);

        /* execute the actual command with execve */
        if (execve(command_path, argv, NULL) == -1){
            perror("Error:");
        }
    }
    
}
