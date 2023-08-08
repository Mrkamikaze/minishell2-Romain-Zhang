/*
** EPITECH PROJECT, 2023
** my_pipe.c
** File description:
** my_pipe
*/

#include "my.h"

void my_pipe(char *line, shell *shell)
{
    char **execute = NULL;
    execute = str_tab(line, '|');
    for (int i = 0; execute[i] != NULL; i++) {
        if (my_strcmp(execute[i], "|") != 0) {
            commands(formatter(execute[i]), str_tab(execute[i], ' '), shell);
        }
    }
    return;
}

int detect_pipe(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '|')
            return 1;
    }
    return 0;
}
