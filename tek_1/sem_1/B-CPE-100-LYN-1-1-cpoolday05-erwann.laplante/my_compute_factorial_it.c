/*
** EPITECH PROJECT, 2021
** Task 01 - my_compute_factorial_it
** File description:
** This iterative function that returns the factorial of the number
*/

int my_compute_factorial_it(int nb)
{
    int rep = 1;

    if (nb < 0 || nb > 12)
        return (0);
    while (nb > 0) {
        rep *= nb;
        nb--;
    }
    return (rep);
}
