/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** yessir
*/

#include "my.h"

void my_putchar(char c);

unsigned int my_put_unsigned_nbr (unsigned int nb)
{
    if (nb / 10) {
        my_put_unsigned_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}
