/*
** EPITECH PROJECT, 2021
** B-PSU-101-LYN-1-1-navy-hugo.fleury
** File description:
** letter_to_int
*/

#include "navy.h"

int get_pos_int(char what)
{
    switch (what) {
        case 'A' : return 2;
        case 'B' : return 4;
        case 'C' : return 6;
        case 'D' : return 8;
        case 'E' : return 10;
        case 'F' : return 12;
        case 'G' : return 14;
        case 'H' : return 16;
    }
    return 0;
}
