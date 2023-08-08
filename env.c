/*
** EPITECH PROJECT, 2023
** env.c
** File description:
** env
*/

int display_env(shell shell)
{
    display_word_arrray(shell->environment);
    return 0;
}
