/*
** EPITECH PROJECT, 2022
** my_put_float.c
** File description:
** my_put_float
*/

#include <stdio.h>

void my_putchar (char c);
int my_put_nbr(int nb);

float my_put_float(double nb)
{
    int multiplier = 10;
    int integer = nb;
    int deci;
    my_put_nbr(integer);
    nb = (nb - integer);
    nb = nb * 1000000;
    deci = nb;
    my_putchar('.');
    if (deci < 0)
        deci = deci * (-1);
    my_put_nbr(deci);
}
