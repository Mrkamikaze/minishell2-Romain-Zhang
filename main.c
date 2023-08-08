/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main
*/

#include "my.h"

int free_all(char **argument, char **env)
{
    free(argument);
    free(env);
    return 0;
}

char **remove_n(char **command)
{
    int lenght = number_tab_cell(command) - 1;
    while (my_strcmp(command[lenght], "") == 0 ||
my_strcmp(command[lenght], "\0") == 0 ||
my_strcmp(command[lenght], "\n") == 0 ||
my_strcmp(command[lenght], " ") == 0) {
        lenght--;
    }
    command[lenght + 1] = NULL;
    return command;
}

void commands(char *line, char **av, shell *shell)
{
    int status;
    pid_t pid = fork();
    if (pid == 0) {
        if (cmp_line(line, "env") == 0)
            return display_word_array(shell->environment);
        if (cmp_line(line, "unsetenv") == 0)
            return do_unsetenv(shell, av);
        if (cmp_line(line, "setenv") == 0)
            return do_setenv(shell, av);
        if (cmp_line(line, "cd") == 0)
            return changedir(av, shell);
        if (execve(native(line), remove_n(av), shell->environment) == -1) {
            execve(av[0], av, shell->environment);
            my_putstr(av[0]);
            my_putstr(": Command not found.\n");
        }
    } else
        waitpid(pid, &status, 0);
    return;
}

void execute_commands(char **argument, shell *shell, char *line)
{
    line = formatter(line);
    if (detect_pipe(line) == 1)
        return my_pipe(line, shell);
    argument = str_tab(line, ' ');
    commands(line, argument, shell);
    line = NULL;
    return;
}

int main(int ac, char **av, char **env)
{
    char *line = NULL;
    size_t len = 0;
    char **argument = NULL;
    shell shell = {env};
    error_handler();
    while (1) {
        if (isatty(STDIN_FILENO))
            write(1, "$> ", 3);
        if (getline(&line, &len, stdin) >= 0 && cmp_line(line, "exit") != 0)
            execute_commands(argument, &shell, line);
        else
            exit(EXIT_SUCCESS);
    }
    return free_all(argument, shell.environment);
}
