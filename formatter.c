/*
** EPITECH PROJECT, 2023
** formatter.c
** File description:
** formatter
*/

#include "my.h"

char *formatter(char *str)
{
    int i = 0;
    int j = 0;
    int limit = my_strlen(str);
    char *form = malloc(sizeof(str) + 1);
    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t') {
            form[j] = str[i];
            j++;
            (str[i + 1] == ' ' || str[i + 1] == '\t') &&
                str[i + 1] != '\0' ? form[j] = ' ', j++ : 0;
        }
        i++;
    }
    return form;
}
