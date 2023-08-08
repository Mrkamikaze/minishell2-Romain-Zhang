/*
** EPITECH PROJECT, 2023
** env_functions.c
** File description:
** env_functions
*/

#include "my.h"

int count_sep(char *str)
{
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        if (str[i] == ':')
            j++;
        i++;
    }
    return j;
}

char **sep_path(char *path)
{
    int i = 0;
    int lenght = 0;
    int row = 0;
    int limit = count_sep(path);
    char **map;
    map = malloc(sizeof(char *) * (my_strlen(path) + 1));
    while (lenght <= limit) {
        map[lenght] = malloc(sizeof(char) * (my_strlen(path) + 1));
        while (path[i] != ':') {
            map[lenght][row] = path[i];
            i++;
            row++;
        }
        map[lenght][row] = '\0';
        row = 0;
        lenght++;
        i++;
    }
    return map;
}

char *my_get_env(shell *shell, char *search)
{
    int i = 0;
    char *path;
    char *sep;
    while (my_strcmp(shell->environment[i], search) != 0)
        i++;
    sep = strtok(shell->environment[i], "=");
    path = strtok(NULL, "");
    sep_path(path);
    return path;
}
