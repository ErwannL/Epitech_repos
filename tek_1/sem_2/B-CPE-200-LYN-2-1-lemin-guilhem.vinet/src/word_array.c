/*
** EPITECH PROJECT, 2022
** B-PSU-210-LYN-2-1-minishell2-guilhem.vinet
** File description:
** str_to_word_array
*/

#include "lemin.h"

char **fill_array(char **array, char *str, char sep)
{
    int j = 0;
    int k = 0;

    for (int i = 0; i < my_strlen(str); i ++) {
        if (str[i] == sep) {
            j ++;
            k = 0;
            i ++;
        }
        array[j][k] = str[i];
        k ++;
    }
    return (array);
}

char **malloc_array(char **array, int nb_word)
{
    array = malloc(sizeof(char *) * (nb_word + 1));
    array[nb_word] = NULL;
    return (array);
}

char **word_array(char *str, char sep)
{
    int nb_word = 1;
    char **array = NULL;
    int k = 0;
    int j = 0;

    for (int i = 0; i < my_strlen(str); i ++)
        if (str[i] == sep)
            nb_word ++;
    array = malloc_array(array, nb_word);

    for (int i = 0; i < nb_word; i ++) {
        while (str[j] != sep && str[j] != '\0') {
            j ++;
            k ++;
        }
        array[i] = malloc(sizeof(char) * (k + 1));
        array[i][k] = '\0';
        j ++;
        k = 0;
    }
    array = fill_array(array, str, sep);
    return (array);
}
