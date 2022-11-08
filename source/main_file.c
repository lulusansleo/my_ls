/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** main file for main
*/

#include <my.h>

int main(int ac, char **av)
{
    if (error_handle(ac, av))
        return 84;
    if (ac == 2) {
        if (solve_map(av[1]) == -1)
            return 84;
    }
    if (ac == 3) {
        if (generate_map(av[1], av[2]) == 84)
            return 84;
    }
    return 0;
}

int error_handle(int ac, char **av)
{
    if (ac > 3)
        return 1;
    if (ac == 1) {
        print_usage();
        return 1;
    }
    if (av[1] == NULL)
        return 1;
    return 0;
}

void print_usage(void)
{
    write(2, "USAGE:\n", 8);
    write(2, "./bsq [FILEPATH]\n", 18);
    write(2, "      [SIZE] [PATTERN]\n", 24);
}
