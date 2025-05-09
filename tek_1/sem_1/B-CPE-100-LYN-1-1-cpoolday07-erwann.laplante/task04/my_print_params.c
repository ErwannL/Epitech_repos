/*
** EPITECH PROJECT, 2021
** Task 04 - my_print_params
** File description:
** print char
*/

int main(int argc, char **argv)
{
    int i = 0;

    while (i < argc) {
        my_putstr(argv[i]);
        my_putstr("\n");
        i++;
    }
    return (0);
}
