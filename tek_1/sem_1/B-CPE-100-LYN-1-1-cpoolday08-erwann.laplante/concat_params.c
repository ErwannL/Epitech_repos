/*
** EPITECH PROJECT, 2021
** Task 02 - concat_params
** File description:
** This function allocates memory and copies the string given as argument in it
*/
#include<stdlib.h>

char *my_strcat(char *dest , char const *src);

int my_strlen(char const *str);

char *concat_params(int argc, char **argv)
{
    char *str;
    int size = 0;

    for (int j = 0; j < argc; j++)
        size += my_strlen(argv[j]) + 1;
    str = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i < argc; i++) {
        my_strcat(str, argv[i]);
        if (i != argc - 1)
            my_strcat(str, "\n");
    }
    return (str);
}
