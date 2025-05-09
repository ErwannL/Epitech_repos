##
## EPITECH PROJECT, 2021
## Task 01 - libmy.a
## File description:
## when executed, build your own library in lib/my/ and name it libmy.a.
##

#!/bin/bash
gcc -c *.c
ar rc libmy.a *.o
