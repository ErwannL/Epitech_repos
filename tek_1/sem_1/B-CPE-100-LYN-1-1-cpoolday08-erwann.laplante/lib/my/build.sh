/*
** EPITECH PROJECT, 2021
** Task 0
** File description:
** when executed, build your own library in lib/my/ and name it libmy.a.
*/

#!/bin/bash
gcc -c *.c
ar rc libmy.a *.o
