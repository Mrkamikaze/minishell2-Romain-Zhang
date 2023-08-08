/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my header
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/wait.h>

typedef struct {
    char **environment;
} shell;

char *concat(char *str1, char *str2);
char *unconcat(char *remove, char *str);
void my_putchar(char c);
char **str_tab(char *str, char sep_line);
int my_strlen(char const *str);
int my_put_nbr(int nb);
void my_putstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int cmp_line(char const *s1, char const *s2);
int test(char const *filepath, char **av, char **env);
int ls(int ac, char **av, char **env);
void display_word_array(char **tab);
void display_info(char **tab);
char **segmentation(char **tab);
int env_size(char **env);
char *my_get_env(shell *shell, char *search);
void do_unsetenv(shell *shell, char **str);
void do_setenv(shell *shell, char **str);
void cd_setenv(shell *shell, char *PATH, char *cwd);
char **add_tab(char **tab, char *str);
char **replace_in_tab(char **tab, char *str, int i);
char *replace_cell(char *cell, char *str);
int number_tab_cell(char **tab);
void changedir(char **str, shell *shell);
void change_to_home(shell *shell);
void free_map(char **map, int lenght);
char *native(char *command);
void commands(char *line, char **av, shell *shell);
char *formatter(char *str);
char **remove_n(char **command);
void segfault_prompt(int sig);
void cd_error(char *cwd);
void error_handler(void);
void my_pipe(char *line, shell *shell);
int detect_pipe(char *line);
#endif
