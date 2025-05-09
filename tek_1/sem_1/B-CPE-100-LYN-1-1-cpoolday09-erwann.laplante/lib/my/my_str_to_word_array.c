/*
** EPITECH PROJECT, 2021
** Task 03 - my_show_word_array
** File description:
** function that splits a string into words
*/
#include <stdlib.h>
#include"../../include/my.h"

int alpha_num(char c)
{
    if (c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || c > 'z')
        return (1);
    return (0);
}

int	number_of_word(char *str)
{
    int word = 0;

    for (int i = 0; str != NULL && str[i]; i++) {
        if (alpha_num(str[i]) == 0 && alpha_num(str[i + 1]) == 1)
            word++;
    }
    return (word);
}

char **my_str_to_word_array(char *str)
{
    int j = 0;
    char **result;
    int len = 0;

    result = malloc(sizeof(char *) * (number_of_word(str) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (alpha_num(str[i]) == 0)
            len++;
        if (alpha_num(str[i]) == 0 && alpha_num(str[i + 1]) == 1) {
            result[j] = malloc(sizeof(char) * (len + 1));
            my_strncpy(result[j], &str[i - len + 1], len);
            len = 0;
            j++;;
        }
    }
    result[j] = NULL;
    return (result);
}
