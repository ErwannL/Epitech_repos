/*
** EPITECH PROJECT, 2021
** Task 09 - my_strlowcase
** File description:
** This function puts every letter of every word in it in lowercase.
*/

char my_strlowcase(char str)
{
    if (str >= 'A' && str <= 'Z')
        str = str + 32;
    return (str);
}
