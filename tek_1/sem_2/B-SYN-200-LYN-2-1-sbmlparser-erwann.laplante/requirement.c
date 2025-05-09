/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
** File description:
** requirement
*/

#include <stdlib.h>

char *complete_array(char *array, char const *str, int save, int count)
{
    int k = 0;

    while (((str[save] >= '0' && str[save] <= '9') || (str[save] >= 'A'
    && str[save] <= 'Z') || (str[save] >= 'a' && str[save] <= 'z'))
    && str[save]) {
        array[k] = str[save];
        k++;
        save++;
    }
    array[count] = '\0';
    return array;
}

char **count_word(char const *str, char **array)
{
    int nbr_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || (str[i] > '9' && str[i] < 'A') || (str[i] > 'Z'
        && str[i] < 'a') || str[i] > 'z') && ((str[i + 1] >= '0'
        && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a'
        && str[i] <= 'z'))) {
            nbr_word++;
        }
    }
    array = malloc(sizeof(char *) * (nbr_word + 2));
    array[nbr_word + 1] = 0;
    return array;
}

int check_end(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i - 1;
}

char **my_str_to_word_array_synthesis(char const *str)
{
    char **array = count_word(str, array);
    int j = 0;

    for (int i = 0, count = 0, save = 0, k = 0; str[i] != '\0'; i++) {
        save = i;
        while (((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A'
        && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))) {
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
    return array;
}
