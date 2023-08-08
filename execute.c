/*
** EPITECH PROJECT, 2022
** display_word_array.c
** File description:
** display_word_array
*/

#include "my.h"
#include <stddef.h>
#include <unistd.h>

int tab_len(char **tab)
{
    int lenght = 0;
    while (tab[lenght] != NULL)
        lenght++;
    lenght--;
    return lenght;
}

void pid(void)
{
    my_putstr("PID: ");
    my_put_nbr(getpid());
    my_putchar('\n');
}

void childpid(void)
{
    pid_t child_pid = fork();
    my_putstr("Child PID: ");
    my_put_nbr(child_pid);
    my_putchar('\n');
}

void display_info(char **tab)
{
    int row = 0;
    int lenght = 0;
    pid_t child_pid = fork();
    my_putstr("Program name:");
    my_putstr(tab[lenght]);
    my_putchar('\n');
    pid();
    childpid();
    my_putstr("Nb args: ");
    my_put_nbr(tab_len(tab));
    my_putchar('\n');
}
