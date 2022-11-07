/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** get size of map
*/

#include <my.h>

int count_lines(char *map)
{
    int line_count = -1;
    int line_given = 0;
    int i = 0;

    line_given = my_getnbr(map);
    if (line_given == -1)
        return -1;
    for (i = 0; map[i] != '\0'; i++)
        if (map[i] == '\n')
            line_count++;
    if ((line_count != line_given) || (line_given == 0))
        return -1;
    return line_count;
}

int count_columns(char *map, int line_count)
{
    int temp = 0;
    int check; int j = 0;

    while (*map != '\n')
        ++map;
    ++map;
    for (int i = 0; i < line_count; i++) {
        check = 0;
        while (map[j] != '\n') {
            check++;
            j++;
        }
        if (temp == 0)
            temp = check;
        if ((check != temp) || (check == 0))
            return -1;
        temp = check;
        j++;
    }
    return check;
}
