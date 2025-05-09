/*
** EPITECH PROJECT, 2021
** Task 08 - my_strupcase
** File description:
** This function puts every letter of every word in it in uppercase.
*/

char *my_strupcase(char *str)
{
    int i = 0;
    int val = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}
