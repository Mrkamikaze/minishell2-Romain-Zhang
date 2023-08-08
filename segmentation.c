/*
** EPITECH PROJECT, 2023
** segmentation.c
** File description:
** segmentation
*/

#include <stdio.h>
#include "my.h"

char **argument_in_tab(char **tab, int limit)
{
    int a = 1;
    int j = 0;
    int i = 1;
    char *buffer = malloc(sizeof(tab));
    while (i < limit) {
        while (tab[i][j] != '\0' && tab[i][j] != '\n') {
            buffer[a] = tab[i][j];
            a++;
            j++;
        }
        buffer[a] = ' ';
        i++;
        j = 0;
        a++;
    }
    return str_tab(buffer, ' ');
}

char **segmentation(char **tab)
{
    int i = 0;
    int j = 0;
    char **argument = NULL;
    int a = 0;
    if (tab[1] == NULL)
        return NULL;
    while (tab[i] != NULL)
        i++;
    argument = argument_in_tab(tab, i);
    return argument;
}
