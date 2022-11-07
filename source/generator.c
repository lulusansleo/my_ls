/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** generator
*/

#include <my.h>

char **generator(int size, char const *pattern)
{
    vector_t size_and_index = {0, 0, 0};
    int i;
    char **map;

    size_and_index.x = size;
    map = malloc(sizeof (char *) * (size_and_index.x + 1));
    for (i = 0; i < size_and_index.x; i++) {
        size_and_index = pattern_for_line(&map[i], pattern, size_and_index);
        printf("%s\n", map[i]);
    }
    map[size_and_index.x] = NULL;
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
        if (pattern[size_and_index.y] == '\0')
            size_and_index.y = 0;
        }
    map[size_and_index.x] = '\0';
    return size_and_index;
}

int generate_map(char const *size, char const *pattern)
{
    int size_int = my_getnbr_no_err(size);
    char **map = generator(size_int, pattern);
    vector_t size_of_map = {0, 0, 0};

    size_of_map.x = size_int;
    size_of_map.y = size_int;
    solve_arr(map, &size_of_map);
    return 0;
}
