/*
** EPITECH PROJECT, 2021
** Task 08 - my_strupcase
** File description:
** This function puts every letter of every word in it in uppercase.
*/

char my_strupcase(char str)
{
    if (str >= 'a' && str <= 'z')
        str = str - 32;
    return (str);
}
