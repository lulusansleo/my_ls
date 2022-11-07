/*
** EPITECH PROJECT, 2022
** myh
** File description:
** myh
*/

#ifndef myh
    #define myh

    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdio.h>

    typedef struct size_struct {
        int line_size;
        int line_count;
        int is_count_wrong;
        int is_size_wrong;
    } size_struct_t;


    typedef struct vector {
        int x;
        int y;
        int size;
    } vector_t;

    int my_reverse_nbr(int nb);
    int my_compute_power_rec(int nb , int p);
    int my_compute_square_root(int nb);
    int my_find_prime_sup(int nb);
    int my_getnbr(char const *str);
    int my_is_prime(int nb);
    int my_isneg(int nb);
    int my_put_nbr(int nb);
    void my_putchar(char c);
    int my_putstr(char const *str);
    char *my_revstr(char *str);
    int my_showmem(char const *str, int size);
    void my_sort_int_array(int *tab, int size);
    int my_showstr(char const *str);
    int my_str_isalpha(char const *str);
    int my_isalpha(char c);
    int my_str_islower(char const *str);
    int my_islower(char c);
    int my_str_isnum(char const *str);
    int my_isnum(char c);
    int my_str_isprintable(char const *str);
    int my_isprintable(char c);
    int my_str_isupper(char const *str);
    int my_isupper(char c);
    char *my_strcapitalize(char *str);
    char *my_strcat(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    int my_strcmp2(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    int my_strlen(char const *str);
    char *my_strlowcase(char *str);
    char *my_strncat(char *dest, char const *src, int n);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strstr(char *str, char const *to_find);
    char *my_strncpy2(char *dest, char const *src, int n);
    char *my_strupcase(char *str);
    void my_swap(int *a, int *b);
    int my_show_word_array(char * const *tab);
    char *my_strdup(char const *src);
    char **my_str_to_word_array(char const *str);
    int count_letter(char *str, char c);
    int error_handle(int argc, char ** argv);
    int get_letter_count(char const *str);
    void print_result(char letter, int frequency, int count);
    char *comparativetable(char *str);
    void print_float(int frequency);
    void print_usage(void);
    int generate_map(char const *size, char const *pattern);
    int solve_map(char const *filepath);
    char **generator(int size, char const *pattern);
    int fs_open_file(char const *filepath);
    void free_map(char **map, int size);
    void free_int_map(int **map, int size);
    int count_lines(char *map);
    int count_columns(char *map, int line_count);
    int size_error(vector_t *size_of_map);
    void print_map(vector_t vector, vector_t *size_of_map, char **map);
    void print_cond(vector_t vector, int i, int j, char **map);
    vector_t find_square(int **arr, vector_t *size_of_map);
    void assign_vector(int **arr, int x, int y, vector_t *vector);
    int find_small(int **arr, int x, int y);
    void solve_arr(char **map, vector_t *size_of_map);
    vector_t pattern_for_line(char *map, const char *pattern,
    vector_t size_and_index);
    int my_getnbr_no_err(char const *str);

#endif /* !myh */
