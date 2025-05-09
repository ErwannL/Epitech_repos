/*
** EPITECH PROJECT, 2021
** count_island
** File description:
** count island in world
*/
#include<stdio.h>

int my_strlarg(char **str);

int my_strhau(char **str);

char **find_x(char **world, int i, int j, int number);

char **fin_x_2(char **world, int i, int j, int number)
{
    if (i != 0 && world[i - 1][j] == 'X')
        find_x(world, i - 1, j, number);
    if (j != 0 && world[i][j - 1] == 'X')
        find_x(world, i, j - 1, number);
    return (world);
}

char **find_x(char **world, int i, int j, int number)
{
    int largeur = my_strlarg(world);
    int hauteur = my_strhau(world);

    if (world[i][j] == 'X') {
        world[i][j] = number + 48;
        world = fin_x_2(world, i, j, number);
        if ((i + 1) <= (hauteur - 1) && world[i + 1][j] == 'X')
            find_x(world, i + 1, j, number);
        if ((j + 1) <= (largeur - 1) && world[i][j + 1] == 'X')
            find_x(world, i, j + 1, number);
    }
    return (world);
}

int count_island(char **world)
{
    int number = - 1;
    int i = 0;
    int largeur = my_strlarg(world);
    int hauteur = my_strhau(world);

    while (i < hauteur) {
        for (int j = 0; j < largeur; j++) {
            (world[i][j] == 'X' ? number++ : "");
            world = find_x(world, i, j, number);
        }
        i++;
    }
    return (number + 1);
}
