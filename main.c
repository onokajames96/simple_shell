#include "main.h"

/**
 * main - checks if  shell is called.
 *
 * Return: 0 on success
 *
 */
int main(void)
{
while (1)
{
if (isatty(STDIN_FILENO) == 1)
{
interactive();
}
else
{
non_interactive();
}
}
return (0);
}
