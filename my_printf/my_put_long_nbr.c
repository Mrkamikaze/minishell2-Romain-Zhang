/*
** EPITECH PROJECT, 2022
** my_put_long_nbr.c
** File description:
** display long int
*/

#include "my.h"

long int my_put_long_nbr(long int nb)
{
    if ( nb < 0 ){
        my_putchar('-');
        nb = -nb;
    }
    if (nb / 10){
        my_put_long_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0' );
}
