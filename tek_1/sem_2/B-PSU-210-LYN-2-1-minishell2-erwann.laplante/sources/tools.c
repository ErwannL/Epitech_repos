/*
** EPITECH PROJECT, 2022
** B-PSU-101-LYN-1-1-minishell1-erwann.laplante
** File description:
** tools
*/

#include "../include/my.h"

char *del_space(char *str)
{
    while (str[0] == ' ')
        str++;
    for (int i = my_strlen(str); str[i - 1] != ' '; i--) {
        if (str[i] == ' ')
            str[i] = '\0';
    }
    return str;
}

char *get_home(char **env)
{
    char *home = malloc(sizeof(char));

    while (*env) {
        if (my_strncmp(env[0], "HOME=", 5) == 0) {
            home = my_strcpy(home, env[0]);
            break;
        }
        env++;
    }
    return home;
}

char *setup_home(char *home, char **env)
{
    home = get_home(env);
    for (int i = 0; i != 5; i++, home++);
    home = my_strcat(home, "/");
    return home;
}

var_t *setup_here(var_t *var)
{
    int where = 0;

    var->here = getcwd(var->buf, var->size);
    if (my_strcmp(var->here, "/") == 0)
        return var;
    for (int i = 0; var->here[i] != '\0'; i++)
        if (var->here[i] == '/')
            where = i;
    for (int i = where + 1; i != 0; var->here++, i--);
    return var;
}
