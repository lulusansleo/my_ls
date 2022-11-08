/*
** EPITECH PROJECT, 2022
** Luan BOURBIEr
** File description:
** my compute power rec
*/

int my_compute_power_rec(int nb , int p)
{
    int result;

    if (p == 0) {
        return 1;
    } else if (p < 0) {
        return 0;
    } else {
        result = my_compute_power_rec(nb, p - 1) * nb;
        return result;
    }
}
