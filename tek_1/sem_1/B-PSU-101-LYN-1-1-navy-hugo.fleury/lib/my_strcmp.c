/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** Compares two strings.
*/

int my_strcmp(char const *s1, char const *s2)
{
    if ((s1 == 0) || (s2 == 0)) {
        return -1;
    }
    for (; (*s1 == *s2) && *s1; s1++, s2++);
    return *s1 - *s2;
}
