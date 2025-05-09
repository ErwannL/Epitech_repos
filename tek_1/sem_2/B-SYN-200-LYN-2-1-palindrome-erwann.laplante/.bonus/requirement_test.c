/*
** EPITECH PROJECT, 2022
** B-SYN-200-LYN-2-1-palindrome-erwann.laplante
** File description:
** requirement_test
*/

#include <stdio.h>

int my_factrec_synthesis(int nb);
int my_squareroot_synthesis(int nb);

int my_factrec_synthesis_test(int nb)
{
    if (nb < 0 || nb > 12)
        return 0;
    if (nb == 0)
        return 1;
    else
        return nb * my_factrec_synthesis(nb - 1);
}

int my_squareroot_synthesis_test(int nb)
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

void test_my_factrec_synthesis(int calc, int good, int valid)
{
    printf("\n");
    printf("test my_factrec_synthesis\n");
    for (int i = -2; i != 15; i++) {
        calc = my_factrec_synthesis(i);
        good = my_factrec_synthesis_test(i);
        if (good != calc) {
            valid = 1;
            printf("%i -> error : got %i expected %i\n", i, calc, good);
        }
    }
    if (valid == 0)
        printf("my_factrec_synthesis is valid\n");
    else
        printf("error in my_factrec_synthesis\n");
}

void test_my_squareroot_synthesis(int calc, int good, int valid)
{
    printf("\n");
    printf("\ntest my_squareroot_synthesis\n");
    for (int i = -2; i != 999999; i++) {
        calc = my_squareroot_synthesis(i);
        good = my_squareroot_synthesis_test(i);
        if (good != calc) {
            valid = 1;
            printf("%i -> error : got %i expected %i\n", i, calc, good);
        }
    }
    if (valid == 0)
        printf("my_squareroot_synthesis is valid\n");
    else
        printf("error in my_squareroot_synthesis\n");
}

int main(void)
{
    int good = 0;
    int calc = 0;
    int valid = 0;

    test_my_factrec_synthesis(calc, good, valid);
    test_my_squareroot_synthesis(calc, good, valid);
    printf("\n");
}
