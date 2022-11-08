/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** free if
*/

#include <my.h>

int free_if(char **map, int i)
{
    if (!my_str_is_formatted(map[i])) {
            free_map(map, i);
            return 1;
        }
    return 0;
}
