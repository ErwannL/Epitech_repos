/*
** EPITECH PROJECT, 2021
** Task 01 - my_swap
** File description:
** This fonction swaps the content of two integers
*/

void my_swap(int *a, int *b)
{
    int tempo = 0;
    int *temp = &tempo;

    *temp = *a;
    *a = *b;
    *b = *temp;
}
