/*
** EPITECH PROJECT, 2023
** native
** File description:
** native
*/

#include "my.h"

char *native(char *command)
{
    char *bin = "/bin/";
    int i = 0;
    int h = 0;
    char *str = malloc((sizeof(char) * my_strlen("bin/")) +
(sizeof(char) * my_strlen(command)) + 1);
    while (bin[i] != '\0') {
        str[i] = bin[i];
        i++;
    }
    while (command[h] != '\n' && command[h] != ' ' && command[h] != '\n') {
        str[i] = command[h];
        i++;
        h++;
    }
    str[i] = '\0';
    return str;
}
