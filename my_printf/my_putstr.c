/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** my_putstr
*/

void my_putchar (char c);

void my_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return;
}
