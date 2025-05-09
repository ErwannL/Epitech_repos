/*
** EPITECH PROJECT, 2021
** Task 04 - my_evil_str
** File description:
** This function return a revers string
*/

char *my_evil_str(char *str)
{
    int count = 0;
    int tempo = 0;
    int mid = 0;
    int i = 0;

    while (str[count] != '\0') {
        count++;
    }
    mid = count / 2;
    while (i < mid) {
        tempo = str[i];
        str[i] = str[count - 1];
        str[count - 1] = tempo;
        i++;
        count--;
    }
    return (str);
}
