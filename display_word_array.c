/*
** EPITECH PROJECT, 2022
** display_word_array.c
** File description:
** display_word_array
*/

#include "my.h"
#include <stddef.h>
#include <unistd.h>

void display_word_array(char **tab)
{
    int row = 0;
    int lenght = 0;
    while (tab[lenght] != NULL) {
        write(1, tab[lenght], my_strlen(tab[lenght]));
        if (tab[lenght + 1] != NULL)
            my_putchar('\n');
        lenght++;
    }
    my_putchar('\n');
}
