/*
** EPITECH PROJECT, 2021
** Task 04 - my_compute_power_rec
** File description:
** iterative function returns first argument raised to the power of the second
*/

int my_compute_power_rec(int nb , int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    return (nb * my_compute_power_rec(nb, p - 1));
}
