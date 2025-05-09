/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** my_str_to_word_array
*/

#include "my.h"

char *complete_array(char *array, char *str, int save, int count)
{
    int k = 0;

    while (str[save] != '\n' && str[save]) {
        array[k] = str[save];
        k++;
        save++;
    }
    array[count] = '\0';
    return array;
}

char **count_word(char *str, char **array)
{
    int nbr_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            nbr_word++;
    }
    array = malloc(sizeof(char *) * (nbr_word + 2));
    array[nbr_word + 1] = NULL;
    return array;
}

int check_end(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i - 1;
}

char **my_str_to_word_array(char *str)
{
    char **array = count_word(str, array);
    int j = 0;

    for (int i = 0, count = 0, save = 0, k = 0; str[i] != '\0'; i++) {
        save = i;
        while (str[i] != '\n' && str[i + 1]) {
            count++;
            i++;
        }
        if (count != 0) {
            i == check_end(str) ? count++ : 0;
            array[j] = malloc(sizeof(char) * (count + 1));
            array[j] = complete_array(array[j], str, save, count);
            count = 0;
            j++;
        }
    }
    array[j] = NULL;
    return array;
}
