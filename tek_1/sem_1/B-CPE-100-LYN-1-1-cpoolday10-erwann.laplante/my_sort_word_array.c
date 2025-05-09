/*
** EPITECH PROJECT, 2021
** Task 04 - my_show_param_array
** File description:
** my_params_to_array
*/

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
