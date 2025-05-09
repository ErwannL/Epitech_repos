/*
** EPITECH PROJECT, 2023
** B-NWP-400-LYN-4-1-myftp-ilhan.neuville
** File description:
** str_to_array
*/

#include "../include/my_teams.h"

int is_alpha(char character)
{
    return ((character >= 'A' && character <= 'Z')
        || (character >= 'a' && character <= 'z'));
}

int count_separator(char const *str)
{
    int count = 0;
    for (int index = 0; *(str + index) != '\0'; index++)
        if (!is_alpha(*(str + index)))
            count++;
    return count;
}

int count_to_next_separator(char const *str, int index)
{
    int count = 0;
    while (*(str + index) != '\0') {
        if (!is_alpha(*(str + index)))
            return count;
        count++;
        index++;
    }
    return count;
}

void copy_to_array(char **array, char const *str)
{
    int word_count = 0;
    int char_count = 0;
    for (int index = 0; *(str + index) != '\0'; index++) {
        if (is_alpha(*(str + index))) {
            array[word_count][char_count] = *(str + index);
            char_count++;
        } else {
            char_count = 0;
            word_count++;
        }
    }
}

char **str_to_array(char *str)
{
    int const word_number = count_separator(str) + 1;
    char **result = malloc(sizeof(char *) * word_number);
    int word_count = 0;
    unsigned int char_count = 0;

    while (char_count <= (strlen(str) - word_count)) {
        int next_separator = count_to_next_separator(str, char_count);
        result[word_count] = malloc(sizeof(char *) * (next_separator + 1));
        char_count += next_separator + 1;
        word_count++;
    }

    copy_to_array(result, str);
    return result;
}