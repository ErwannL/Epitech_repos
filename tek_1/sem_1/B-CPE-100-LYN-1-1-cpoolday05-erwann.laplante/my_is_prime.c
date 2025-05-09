/*
** EPITECH PROJECT, 2021
** Task 06 - my_is_prime
** File description:
** This function returns 1 if the number is prime and 0 if not
*/

int my_is_prime(int nb)
{
    int i = 2;

    if (nb == 0 || nb == 1 || nb < 0)
        return (0);
    while (i < nb && i <= 46341) {
        if (nb % i == 0) {
            return (0);
        }
        i++;
    }
    return (1);
}
