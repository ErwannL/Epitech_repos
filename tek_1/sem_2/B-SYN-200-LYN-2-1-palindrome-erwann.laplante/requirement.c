/*
** EPITECH PROJECT, 2022
** private_palindrome
** File description:
** requirement
*/

int my_factrec_synthesis(int nb)
{
    if (nb < 0 || nb > 12)
        return 0;
    if (nb == 0)
        return 1;
    else
        return nb * my_factrec_synthesis(nb - 1);
}

int my_squareroot_synthesis(int nb)
{
    if (nb <= 1)
        return (nb < 0 ? -1 : nb);
    if (nb > 2147395600)
        return -1;
    for (int root = 2; root < 46341 && root <= nb; root++) {
        if (root * root == nb)
            return root;
        if (root * root > nb)
            break;
    }
    return -1;
}
