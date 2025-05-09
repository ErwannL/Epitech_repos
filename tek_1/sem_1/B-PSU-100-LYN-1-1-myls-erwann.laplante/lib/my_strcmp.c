/*
** EPITECH PROJECT, 2021
** Task 06 - my_strcmp
** File description:
** This function Reproduce the behavior of the strcmp function.
*/

#include"../includes/my.h"

int my_strcmp(char const *s1 , char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0')
        i++;
    if (s1[i] == '\0' && s2[i] == '\0')
        return (0);
    else
        return(s1[i] - s2[i]);
}

int my_strcmp_bis(char const *s1 , char const *s2)
{
    int i = 0;
    char a = s1[i];
    char b = s2[i];

    ((a >= 65 && a <= 90) ? a += 32 : 0);
    ((a >= 91 && a <= 96 || a == 46) ? a = 110 : 0);
    ((b >= 65 && b <= 90) ? b += 32 : 0);
    ((b >= 91 && b <= 96 || b == 46) ? b = 110 : 0);
    for (; a == b && a != '\0'; ++i) {
        a = s1[i];
        b = s2[i];
        ((a >= 65 && a <= 90) ? a += 32 : 0);
        ((a >= 91 && a <= 96 || a == 46) ? a = 110 : 0);
        ((b >= 65 && b <= 90) ? b += 32 : 0);
        ((b >= 91 && b <= 96 || b == 46) ? b = 110 : 0);
    }
    if (a == '\0' && b == '\0')
        return (0);
    else
        return(a - b);
}
