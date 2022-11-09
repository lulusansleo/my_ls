/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** algorithm (reverse demineur)
*/

#include <my.h>

short find_small(short **arr, short x, short y)
{
    short nb;

    nb = arr[x - 1][y - 1];
    if (arr[x][y] == 0)
        return 0;
    if (nb > arr[x][y - 1])
        nb = arr[x][y - 1];
    if (nb > arr[x - 1][y])
        nb = arr[x - 1][y];
    nb += 1;
    return nb;
}

void assign_vector(short **arr, short x, short y, vector_t *vector)
{
    if (arr[x][y] > vector->size) {
        vector->size = arr[x][y];
        vector->x = x;
        vector->y = y;
    }
}

vector_t find_square(short **arr, vector_t *size_of_map)
{
    vector_t vector = {0, 0, 0};

    for (int i = 1; i != size_of_map->y; i++) {
        for (int j = 1; j != size_of_map->x; j++) {
            arr[i][j] = find_small(arr, i, j);
        }
    }
    for (int i = 0; i != size_of_map->y; i++) {
        for (int j = 0; j != size_of_map->x; j++) {
            assign_vector(arr, i, j, &vector);
        }
    }
    return vector;
}

void print_cond(vector_t vector, short i, short j, char **map)
{
    if (vector.x - vector.size < i && vector.x >= i
    && vector.y - vector.size < j && vector.y >= j)
        map[i][j] = 'x';
}

void print_map(vector_t vector, vector_t *size_of_map, char **map)
{
    for (int i = 0; i != size_of_map->y; i++) {
        for (int j = 0; j != size_of_map->x; j++)
            print_cond(vector, i, j, map);
        write(1, map[i], size_of_map->x);
        write(1, "\n", 1);
    }
}
