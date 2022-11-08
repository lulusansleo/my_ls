/*
** EPITECH PROJECT, 2022
** my getnbr
** File description:
** get nbr
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int res = 0;
    int i = 0;

    if (!my_isnum(str[i]))
        return -1;
    for (i = 0; my_isnum(str[i]); i++) {
        res = res * 10;
        res += str[i] - '0';
    }
    if (str[i] != '\n')
        return -1;
    return res;
}

int my_getnbr_no_err(char const *str)
{
    int res = 0;
    int i = 0;

    if (!my_isnum(str[i]))
        return -1;
    for (i = 0; my_isnum(str[i]); i++) {
        res = res * 10;
        res += str[i] - '0';
    }
    return res;
}
