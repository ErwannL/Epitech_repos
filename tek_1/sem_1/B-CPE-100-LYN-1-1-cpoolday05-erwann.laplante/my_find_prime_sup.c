/*
** EPITECH PROJECT, 2021
** Task 07 - my_find_prime_sup
** File description:
** returns smallest prime number greater or equal to number given
*/

int my_find_prime_sup(int nb)
{
    if (nb < 2)
        return (2);
    while (nb < 2147483647) {
        if (my_is_prime(nb) == 1)
            return (nb);
        nb++;
    }
    return (0);
}
