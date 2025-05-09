/*
** EPITECH PROJECT, 2022
** B-CPE-200-LYN-2-1-dante-guilhem.vinet
** File description:
** my_str_to_word_array
*/

#include "../include/my.h"

char **put_in_word_array(char *str, char **array)
{
    int index = 0;
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            nb = 0;
            index++;
        } else {
            array[index][nb] = str[i];
            nb++;
        }
    }
    return array;
}

char **my_str_to_word_array(char *str, char **array)
{
    int line = 0;
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            line++;
    array = malloc(sizeof(char *) * (line + 2));
    array[line + 1] = NULL;
    for (int i = 0; i != line + 1; i++) {
        array[i] = malloc(sizeof(char) * (count + 2));
        array[i][count + 2] = '\0';
    }
    array = put_in_word_array(str, array);
    return array;
}
