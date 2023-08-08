/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** my_strcmp s1 = the string s2 = the string you are looking for
*/

#include "my.h"

int func_return(int nb)
{
    if (nb < 0)
        return -1;
    if (nb > 0)
        return 1;
    if (nb == 0)
        return 0;
}

int my_strcmp(char const *s1,char const *s2)
{
    int j = 0;
    int res = 0;
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);
    if (len_s1 != len_s2)
        return 1;
    while (s1[j] != '\0') {
        if (s1[j] == s2[j]) {
            j++;
            len_s1--;
            len_s2--;
        } else
            return 1;
        res = len_s1 - len_s2;
    }
    return func_return(res);
}

int cmp_line(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (s2[j] != '\0')
        j++;
    while (s1[i] != 0) {
        if (s1[i] == s2[k]) {
            k++;
            i++;
            j--;
        } else
            return j;
    }
    return j;
}

/* int cmp_line(char const *s1, char const *s2) */
/* { */
/*     int i = 0; */
/*     int j = 0; */
/*     while (s1[i] != '\0' && s2[j] != '\0') { */
/*         if (s1[i] == s2[j]) { */
/*             j++; */
/*         } else { */
/*             j = 0; */
/*         } */
/*         i++; */
/*     } */
/*     if (s2[j] == '\0') { */
/*         return 0; */
/*     } else { */
/*         return 1; */
/*     } */
/* } */
