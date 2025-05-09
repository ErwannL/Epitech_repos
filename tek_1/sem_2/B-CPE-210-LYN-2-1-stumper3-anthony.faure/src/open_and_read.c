/*
** EPITECH PROJECT, 2022
** B-CPE-210-LYN-2-1-stumper3-anthony.faure
** File description:
** open_and_read
*/

#include "../include/my.h"

char *check_size_and_fd(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat file;
    char *buff;

    if (fd == -1)
        return NULL;
    if (stat(filepath, &file) == -1) {
        close(fd);
        return NULL;
    }
    buff = malloc(sizeof(char) * (file.st_size + 1));
    buff[file.st_size] = '\0';
    read(fd, buff, file.st_size);
    close(fd);
    return buff;
}

char **read_numbers(char *filepath)
{
    char **number;
    char *buff = check_size_and_fd(filepath);

    if (buff == NULL)
        return NULL;
    number = malloc(sizeof(char *) * 6);
    number[5] = NULL;
    for (int i = 0, j = 0; i != 5; i += 1) {
        number[i] = malloc(sizeof(char) * 6);
        number[i][5] = '\0';
        for (int a = 0; buff[j] != '\n' && buff[j] != '\0'; j += 1, a += 1)
            number[i][a] = buff[j];
        if (buff[j] != '\0')
            j += 1;
    }
    free(buff);
    return number;
}

numbers_t *free_numbers_part2(numbers_t *numbers)
{
    if (numbers->eight != NULL)
        free(numbers->eight);
    if (numbers->nine != NULL)
        free(numbers->nine);
    free(numbers);
    return NULL;
}

numbers_t *free_numbers(numbers_t *numbers)
{
    if (numbers->zero != NULL)
        free(numbers->zero);
    if (numbers->one != NULL)
        free(numbers->one);
    if (numbers->two != NULL)
        free(numbers->two);
    if (numbers->three != NULL)
        free(numbers->three);
    if (numbers->four != NULL)
        free(numbers->four);
    if (numbers->five != NULL)
        free(numbers->five);
    if (numbers->six != NULL)
        free(numbers->six);
    if (numbers->seven != NULL)
        free(numbers->seven);
    return free_numbers_part2(numbers);
}

numbers_t *fill_numbers(void)
{
    numbers_t *new = malloc(sizeof(numbers_t));

    new->zero = read_numbers("number/0.txt");
    new->one = read_numbers("number/1.txt");
    new->two = read_numbers("number/2.txt");
    new->three = read_numbers("number/3.txt");
    new->four = read_numbers("number/4.txt");
    new->five = read_numbers("number/5.txt");
    new->six = read_numbers("number/6.txt");
    new->seven = read_numbers("number/7.txt");
    new->eight = read_numbers("number/8.txt");
    new->nine = read_numbers("number/9.txt");
    if (new->zero == NULL || new->two == NULL || new->three == NULL
        || new->four == NULL || new->five == NULL || new->six == NULL
        || new->seven == NULL || new->eight == NULL || new->nine == NULL
        || new->one == NULL)
        return free_numbers(new);
    new->string = NULL;
    new->to_print = NULL;
    return new;
}
