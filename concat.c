/*
** EPITECH PROJECT, 2023
** concat.c
** File description:
** concat
*/

#include "my.h"

char *unconcat(char *remove, char *str)
{
    char *new_str = malloc(sizeof(char) * my_strlen(str));
    int i = 0;
    int j = 0;
    int k = 0;
    while (str[i] != '\0') {
        if (str[i] == remove[j]) {
            i++;
            j++;
        }
        if (str[i] != remove[j]) {
            new_str[k] = str[i];
            i++;
            k++;
        }
    }
    return new_str;
}

char *concat(char *str1, char *str2)
{
    int total = 0;
    int size1 = my_strlen(str1);
    int size2 = my_strlen(str2);
    char *concat = malloc(sizeof(char) * (size1 + size2) + 1);
    for (int i = 0; str1[i] != '\0'; i++) {
        concat[total] = str1[i];
        total++;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        concat[total] = str2[i];
        total++;
    }
    return concat;
}
