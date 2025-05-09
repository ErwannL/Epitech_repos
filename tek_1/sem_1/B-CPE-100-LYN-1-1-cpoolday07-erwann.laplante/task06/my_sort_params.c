/*
** EPITECH PROJECT, 2021
** Task 06 - my_sort_params
** File description:
** print char
*/

int my_strcmp(char const *s1 , char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0')
        i++;
    if (s1[i] == '\0' && s2[i] == '\0')
        return (0);
    else
        return (s1[i] - s2[i]);
}

char **condition(char **argv, int i, int j)
{
    char *temp;

    if (my_strcmp(argv[i], argv[j]) > 0) {
        temp = argv[i];
        argv[i] = argv[j];
        argv[j] = temp;
    }
    return (argv);
}

int main(int argc, char **argv)
{
    int count = 0;

    for (int i = 0; i < argc - 1; i++) {
        for (int j = i + 1; j < argc; j++)
            condition(argv, i, j);
    }
    while (count < argc) {
        my_putstr(argv[count]);
        my_putstr("\n");
        count++;
    }
    return (0);
}
