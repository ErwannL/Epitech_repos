/*
** EPITECH PROJECT, 2021
** Task 05 - my_compute_square_root
** File description:
** The function that returns the square root of the number
*/

int my_compute_square_root(int nb)
{
    int temp = 0;

    if (nb == 1)
        return (1);
    for (int i = 1; i < nb; i++) {
        temp = i * i;
        if (temp == nb)
            return (i);
        if (i > nb / 2)
            return (0);
    }
    return (0);
}
