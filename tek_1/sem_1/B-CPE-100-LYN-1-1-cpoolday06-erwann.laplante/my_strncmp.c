/*
** EPITECH PROJECT, 2021
** Task 07 - my_strncmp
** File description:
** This function Reproduce the behavior of the strncmp function.
*/

int my_strncmp(char const *s1 , char const *s2 , int n)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && n >= 0){
        i++;
        n--;
    }
    if ((s1[i] == '\0' && s2[i] == '\0') || (s1[i] == s2[i] && n == 0))
        return (0);
    else
        return(s1[i] - s2[i]);
}
