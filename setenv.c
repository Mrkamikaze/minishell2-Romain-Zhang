/*
** EPITECH PROJECT, 2023
** setenv.c
** File description:
** add a cell in a tab
*/

#include "my.h"

int number_tab_cell(char **tab)
{
    int i = 0;
    while (tab[i] != NULL)
        i++;
    return i;
}

char *replace_cell(char *cell, char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        cell[i] = str[i];
        i++;
    }
    return cell;
}

char **replace_in_tab(char **tab, char *str, int i)
{
    char **new_tab = malloc(sizeof(char *) * number_tab_cell(tab) + 2);
    int len = 0;
    int row = 0;
    while (tab[len] != NULL) {
        new_tab[len] = malloc(sizeof(char) * my_strlen(tab[len]) + 1);
        while (tab[len][row] != '\0' && len != i) {
            new_tab[len][row] = tab[len][row];
            row++;
        }
        if (len == i) {
            new_tab[len] = malloc(sizeof(char) * my_strlen(str) + 1);
            new_tab[len] = replace_cell(new_tab[len], str);
        }
        row = 0;
        len++;
    }
    return new_tab;
}

char **add_tab(char **tab, char *str)
{
    char **new_tab;
    int lenght = 0;
    int row = 0;
    new_tab = malloc(sizeof(char *) * (number_tab_cell(tab) + 2));
    while (tab[lenght] != NULL) {
        new_tab[lenght] = malloc(sizeof(char) * (my_strlen(tab[lenght]) + 1));
        while (tab[lenght][row] != '\0') {
            new_tab[lenght][row] = tab[lenght][row];
            row++;
        }
        row = 0;
        lenght++;
    }
    new_tab[lenght] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        new_tab[lenght][i] = str[i];
    }
    return new_tab;
}

void do_setenv(shell *shell, char **str)
{
    str = remove_n(str);
    int arg = number_tab_cell(str);
    if (arg == 1)
        return display_word_array(shell->environment);
    if (arg == 2)
        str[1] = concat(str[1], "=");
    if (arg > 3)
        return my_putstr("setenv: Too many arguments.\n");
    if (arg == 3)
        str[1] = concat(concat(str[1],"="), str[2]);
    for (int i = 0; shell->environment[i] != NULL; i++) {
        if (cmp_line(shell->environment[i], str[1]) == 0) {
            shell->environment = replace_in_tab(shell->environment, str[1], i);
            return;
        }
    }
    shell->environment = add_tab(shell->environment, str[1]);
    return;
}
