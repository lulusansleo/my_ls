/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** useful
*/

#include <my.h>

char **alloc_map(char **arr, int nb_rows, int nb_cols)
{
    arr = malloc(sizeof (char *) * (nb_rows + 1));
    for (int i = 0; i < nb_rows; i++)
        arr[i] = malloc(sizeof (char) * (nb_cols + 1));
    return arr;
}

void free_map(char **arr, int nb_rows)
{
    for (int i = 0; i <= nb_rows; i++)
        free(arr[i]);
    free(arr);
}

void free_both(vector_t *size_of_map, char *buffer)
{
    free(size_of_map);
    free(buffer);
}

void free_int_map(short **arr, int nb_rows)
{
    for (int i = 0; i < nb_rows; i++)
        free(arr[i]);
    free(arr);
}

int get_number_from_first_line(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[1000];

    if (fd < 0)
        return -1;
    read(fd, buff, 1000);
    return my_getnbr(buff);
}
