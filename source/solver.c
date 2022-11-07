/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** bsq
*/

#include <my.h>

static vector_t *get_size_of_map(char *buffer, vector_t *size_of_map)
{
    size_of_map = malloc(sizeof (vector_t) + 1);
    size_of_map->x = 0;
    size_of_map->size = 0;
    size_of_map->y = count_lines(buffer);
    if (size_of_map->y == -1)
        return size_of_map;
    size_of_map->x = count_columns(buffer, size_of_map->y);
    return size_of_map;
}

static char *open_write_map(char const *filepath)
{
    char *buffer; int fd;
    struct stat *structure = malloc(sizeof (struct stat) + 1);

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        free(structure);
        return NULL;
    }
    if (stat(filepath, structure) == -1)
        return NULL;
    buffer = malloc(sizeof (char) * structure->st_size + 1);
    if (!buffer) {
        free(structure);
        return NULL;
    }
    read(fd, buffer, structure->st_size);
    buffer[structure->st_size] = '\0';
    free(structure);
    return buffer;
}

char **buff_to_arr(char **map, char *buffer, vector_t *size_of_map)
{
    int i;
    int j = 0;
    int k = 0;
    map = malloc(sizeof (char *) * (size_of_map->y + 1));

    while (*buffer != '\n')
        ++buffer;
    ++buffer;
    for (i = 0; i != size_of_map->y; i++){
        map[i] = malloc(sizeof (char) * (size_of_map->x + 1));
        for (k = 0; buffer[j] != '\n'; k++, j++)
            map[i][k] = buffer[j];
        map[i][k] = '\0';
        j++;
        k = 0;
    }
    map[i] = NULL;
    return map;
}

int solve_map(const char *filepath)
{
    char *buffer = open_write_map(filepath);
    vector_t *size_of_map = NULL;
    char **map = NULL;

    if (buffer == NULL)
        return -1;
    size_of_map = get_size_of_map(buffer, size_of_map);
    if (size_error(size_of_map)) {
        free(size_of_map);
        free(buffer);
        return -1;
    }
    map = buff_to_arr(map, buffer, size_of_map);
    solve_arr(map, size_of_map);
    free_map(map, size_of_map->y);
    free(size_of_map);
    free(buffer);
    return 0;
}
