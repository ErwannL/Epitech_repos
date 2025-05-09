/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** Concate two string.
*/

char *my_strcat(char *dest, unsigned char *src)
{
    char *dest_ptr = dest;

    if ((dest == 0) || (src == 0)) {
        return 0;
    }
    for (; *dest; dest++);
    for (; (*dest++ = *src++););
    return dest_ptr;
}
