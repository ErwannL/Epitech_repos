/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** Concate two string based on a given size.
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    char *dest_ptr = dest;

    if ((dest == 0) || (src == 0)) {
        return 0;
    }
    if (nb == 0) {
        return dest_ptr;
    }
    nb -= 1;
    for (; *dest; dest++);
    for (; (*dest++ = *src++) && nb--;);
    return dest_ptr;
}
