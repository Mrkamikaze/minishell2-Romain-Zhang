/*
** EPITECH PROJECT, 2023
** error_messages.c
** File description:
** error_messages
*/

#include "my.h"

void segfault_prompt(int sig)
{
    pid_t pid;
    int status;
    my_putstr(strsignal(sig));
    my_putstr(" (core dumped)\n");
    exit(1);
}

void ctrl_c(int sig)
{
    write(1, "\n$> ", 4);
    return;
}

void cd_error(char *cwd)
{
    my_putstr(cwd);
    my_putstr(": No such file or directory.\n");
}

void error_handler(void)
{
    signal(SIGSEGV, segfault_prompt);
    signal(SIGINT, ctrl_c);
}
