#ifndef MAIN_H
#define MAIN_H
#define MAX_INPUT_SIZE 1024
#define TOKEN_DELIM " \t\r\n\a"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
void interactive(void);
void non_interactive(void);
int hsh_cd(char **args);
int hsh_exit(char **args);
int hsh_env(char **args);
int hsh_help(char **args);
int new_fork(char **args);
char *read_line(void);
char **tokenize_line(char *line);
int execute_args(char **args);
extern char **environ;
#endif /* MAIN_H*/
