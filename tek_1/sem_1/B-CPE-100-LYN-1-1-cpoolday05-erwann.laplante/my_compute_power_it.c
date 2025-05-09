/*
** EPITECH PROJECT, 2021
** Task 03 - my_compute_power_it
** File description:
** iterative function returns first argument raised to the power of the second
*/

int my_compute_power_it(int nb, int p)
{
    int number = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    while(p > 1) {
        number *= nb;
        p--;
    }
    return (number);
}
