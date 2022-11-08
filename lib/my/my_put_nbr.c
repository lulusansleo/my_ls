/*
** EPITECH PROJECT, 2022
** my put nbr
** File description:
** put number
*/

#include "my.h"

int my_put_nbr(int n)
{
    long int nb = n;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    if (nb < 10) {
        my_putchar(nb % 10 + '0');
    }
    return 0;
}
