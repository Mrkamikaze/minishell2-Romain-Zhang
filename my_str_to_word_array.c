/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void free_map(char **map, int length)
{
    for (int i = 0; i < length; i++) {
        free(map[i]);
    }
    free(map);
}

char **move(char const *str, char sep_line, int limit)
{
    int lenght = 0;
    int row = 0;
    char **map;
    map = malloc(sizeof(char *) * (my_strlen(str) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        map[lenght] = malloc(sizeof(char) * (my_strlen(str) + 1));
        while (str[i] != sep_line && str[i] != '\0' && str[i] != '\n') {
            map[lenght][row] = str[i];
            i++;
            row++;
        }
        row = 0;
        lenght++;
    }
    map[lenght] = NULL;
    return map;
}

char **str_tab(char *str, char sep_line)
{
    char **map;
    int limit = my_strlen(str);
    map = move(str, sep_line, limit);
    return map;
}
