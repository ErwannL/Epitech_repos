/*
** EPITECH PROJECT, 2021
** Task 06 - my_strcmp
** File description:
** This function Reproduce the behavior of the strcmp function.
*/

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
