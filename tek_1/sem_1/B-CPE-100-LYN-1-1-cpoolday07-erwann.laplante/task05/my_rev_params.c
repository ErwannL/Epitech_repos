/*
** EPITECH PROJECT, 2021
** Task 05 - my_rev_params
** File description:
** print char
*/

int main(int argc, char **argv)
{
    int i = (argc - 1);

    while (i >= 0) {
        my_putstr(argv[i]);
        my_putstr("\n");
        i--;
    }
    return (0);
}
