/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** error handle
*/

#include <my.h>

int size_error(vector_t *size_of_map)
{
    if (size_of_map->x == -1 || size_of_map->y == -1)
        return 1;
    return 0;
}

int is_incorrect_character(char c)
{
    if (c != '.' || c != 'o')
        return 1;
    return 0;
}
