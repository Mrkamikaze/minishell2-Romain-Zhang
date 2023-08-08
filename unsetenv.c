/*
** EPITECH PROJECT, 2023
** unsetenv.c
** File description:
** remove a cell from a tab
*/

#include "my.h"

int env_size(char **env)
{
    int i = 0;
    int j = 0;
    int size = 0;
    while (env[i] != NULL) {
        size = size + my_strlen(env[i]);
        i++;
    }
    return size;
}

char **remove_cell(char **tab, int i)
{
    char **new_tab;
    int lenght = 0;
    int j = 0;
    int row = 0;
    int tab_size = env_size(tab);
    new_tab = malloc(tab_size + 1);
    while (tab[j] != NULL) {
        new_tab[lenght] = malloc(sizeof(char) * (my_strlen(tab[j]) + 1));
        while (tab[j][row] != '\0') {
            new_tab[lenght][row] = tab[j][row];
            row++;
        }
        row = 0;
        lenght++;
        lenght == i ? j++, j++ : j++;
    }
    return new_tab;
}

void do_unsetenv(shell *shell, char **str)
{
    int i = 0;
    int arg = number_tab_cell(str);
    if (arg == 1)
        return my_putstr("unsetenv: Too few arguments.\n");
    if (arg > 3)
        return my_putstr("unsetenv: Too many arguments.\n");
    if (arg == 3)
        str[1] = concat(concat(str[1],"="), str[2]);
    while (shell->environment[i] != NULL) {
        if (cmp_line(shell->environment[i], str[1]) == 0) {
            shell->environment = remove_cell(shell->environment, i);
            return;
        }
        i++;
    }
    return;
}
