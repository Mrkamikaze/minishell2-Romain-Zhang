/*
** EPITECH PROJECT, 2023
** cd.c
** File description:
** changedir
*/

#include "my.h"

void cd_setenv(shell *shell, char *PATH, char *pwd)
{
    char **new_tab;
    int i = 0;
    char *replace = concat(PATH, pwd);
    while (shell->environment[i] != NULL) {
        if (cmp_line(shell->environment[i], PATH) == 0) {
            shell->environment = replace_in_tab(shell->environment, replace, i);
            return;
        }
        i++;
    }
    shell->environment = add_tab(shell->environment, replace);
    return;
}

void to_old_pwd(shell *shell)
{
    int i = 0;
    char cwd[3000];
    char pwd[3000];
    getcwd(pwd, sizeof(pwd));
    while (cmp_line(shell->environment[i], "OLDPWD") != 0)
        i++;
    chdir(unconcat("OLDPWD=",shell->environment[i]));
    cd_setenv(shell, "OLDPWD=", pwd);
    getcwd(cwd, sizeof(cwd));
    cd_setenv(shell, "PWD=", cwd);
    return;
}

void change_to_home(shell *shell)
{
    int i = 0;
    char pwd[3000];
    char cwd[3000];
    getcwd(pwd, sizeof(pwd));
    cd_setenv(shell, "OLDPWD=", pwd);
    while (cmp_line(shell->environment[i], "HOME") != 0)
        i++;
    chdir(unconcat("HOME=",shell->environment[i]));
    getcwd(cwd, sizeof(cwd));
    cd_setenv(shell, "PWD=", cwd);
    return;
}

void changedir(char **str, shell *shell)
{
    char cwd[3000];
    char pwd[3000];
    int arg = number_tab_cell(str);
    if (arg == 1 || (arg > 1 && str[1] == NULL) || my_strcmp(str[1], "") == 0)
        return change_to_home(shell);
    getcwd(pwd, sizeof(pwd));
    if (my_strcmp(str[1], "~") == 0)
        return;
    if (my_strcmp(str[1], "-") == 0)
        return to_old_pwd(shell);
    if (access(str[1], X_OK) == 0) {
        chdir(str[1]);
        getcwd(cwd, sizeof(cwd));
        cd_setenv(shell, "PWD=", cwd);
        return cd_setenv(shell, "OLDPWD=", pwd);
    } else
        return cd_error(str[1]);
}
