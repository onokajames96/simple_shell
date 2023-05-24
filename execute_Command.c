#include "shell.h"
void execute_command(char **argv) __attribute__((unused));
void execute_command(char **argv)
{
    char *Cmd = NULL, *Cmd_path = NULL;

    if (argv){
        /* get the command */
        Cmd = argv[0];

        /* generate the path to this command before passing it to execve */
        Cmd_path = get_path(Cmd);

        /* execute the actual command with execve */
        if (execve(Cmd_path, argv, NULL) == -1){
            perror("Error:");
        }
    }
    
}
