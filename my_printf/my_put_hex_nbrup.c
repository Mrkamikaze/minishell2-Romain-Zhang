/*
** EPITECH PROJECT, 2022
** my_put_hex_nbrup.c
** File description:
** my_put_hex_nbrup
*/

#include "my.h"

unsigned int my_put_hex_nbrup(unsigned int nb)
{
    int div;
    int i = 1;
    int k, temp;
    char hexnbr[100];
    div = nb;
    while (div != 0){
        temp = div % 16;
        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;
        hexnbr[i++] = temp;
        div = div / 16;
    }
    for (k = i - 1; k > 0; k--){
        my_putchar(hexnbr[k]);
    }
}
