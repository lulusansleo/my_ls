/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** array solver
*/

#include <my.h>

static int check_value(char ch)
{
    if (ch == '.')
        return 1;
    else if (ch == 'o')
        return 0;
    else
        return -1;
}

static int **array_to_int_array(char **map, vector_t *size_of_map)
{
    int **int_map = malloc(sizeof(int *) * (size_of_map->y + 1));

    for (int i = 0; i != size_of_map->y; i++) {
        int_map[i] = malloc(sizeof (int) * (size_of_map->x + 1));
        for (int j = 0; j != size_of_map->x; j++) {
            int_map[i][j] = check_value(map[i][j]);
        }
    }
    return int_map;
}

void solve_arr(char **map, vector_t *size_of_map)
{
    int **int_arr = array_to_int_array(map, size_of_map);
    vector_t vector = find_square(int_arr, size_of_map);

    print_map(vector, size_of_map, map);
    free_int_map(int_arr, size_of_map->y);
}
