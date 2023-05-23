#ifndef SHELL_H
#define SHELL_H
#define MAX_INPUT_SIZE 1024
#define TOKEN_DELIM " \t\r\n\a"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
char *get_path(char *command);

#endif /* SHELL_H*/
