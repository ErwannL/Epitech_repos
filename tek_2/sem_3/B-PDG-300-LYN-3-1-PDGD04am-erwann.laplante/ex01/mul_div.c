/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGD04am-erwann.laplante
** File description:
** mul_div
*/

void mul_div_long (int a, int b, int *mul, int *div)
{
    *mul = a * b;
    *div = b == 0 ? 42 : a / b;
    return;
}

void mul_div_short (int *a, int *b)
{
    int tmp = *a;

    *a = *a * *b;
    *b = *b == 0 ? 42 : tmp / *b;
    return;
}
