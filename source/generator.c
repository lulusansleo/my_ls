/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** generator
*/

#include <my.h>

int manage_index(int index, int len)
{
    if (index >= len)
            index = 0;
    return index;
}

char **generator(int size, char const *pattern)
{
    int i; int j; int index = 0;
    int len = my_strlen(pattern);
    char **map;

    map = malloc(sizeof (char *) * (size + 1));
    for (i = 0; i < size; i++) {
        map[i] = malloc(sizeof (char) * (size + 1));
        for (j = 0; j < size; j++) {
            map[i][j] = pattern[index];
            index += 1;
            index = manage_index(index, len);
            }
        map[i][j] = '\0';
    }
    map[size] = NULL;
    return map;
}

vector_t pattern_for_line(char *map, const char *pattern,
vector_t size_and_index)
{
    int j;
    map = malloc(sizeof (char) * (size_and_index.x + 1));
    for (j = 0; j < size_and_index.x; j++) {
        map[j] = pattern[size_and_index.y];
        size_and_index.y += 1;
        if (size_and_index.y >= size_and_index.size)
            size_and_index.y = 0;
        }
    map[j] = '\0';
    return size_and_index;
}

int generate_map(char const *size, char const *pattern)
{
    int size_int;
    char **map;
    vector_t size_of_map = {0, 0, 0};

    if (!my_str_isnum(size) || !my_str_is_formatted(pattern))
        return -1;
    if ((size_int = my_getnbr_no_err(size)) == 0)
        return -1;
    map = generator(size_int, pattern);
    size_of_map.x = size_int;
    size_of_map.y = size_int;
    size_of_map.size = 0;
    solve_arr(map, &size_of_map);
    free_map(map, size_int);
    return 0;
}
