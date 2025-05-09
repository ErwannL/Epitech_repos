/*
** EPITECH PROJECT, 2021
** Task 10 - my_strcapitalize
** File description:
** This function capitalizes the first letter of each word
*/

char *my_strupcase2(char *str)
{
    int i = 0;
    int val = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    int i = 1;
    int val = 0;

    str = my_strupcase2(str);
    if (str[0] >= 'a' && str[0] <= 'z' )
        str[0] = str[0] - 32;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z' && (str[i - 1] < '0'
        || str[i - 1] > '9' && str[i - 1] < 'A' || str[i - 1] > 'Z'
        && str[i - 1] < 'a' || str[i - 1] > 'z'))
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}
