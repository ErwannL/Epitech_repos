/*
** EPITECH PROJECT, 2021
** Task 03 - my_revstr
** File description:
** reverses a string
*/

char *my_revstr(char *str)
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
