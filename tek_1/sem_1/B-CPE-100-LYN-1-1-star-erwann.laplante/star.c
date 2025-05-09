/*
** EPITECH PROJECT, 2021
** star
** File description:
** function that displays a star, based on its given size
*/

int star_one(void);
void make_first_last_line(unsigned int size);
void make_first_last_line(unsigned int size);
void make_cor_one(unsigned int size);
void make_cor_two(unsigned int size);
void make_conne(unsigned int size);
void make_conne_revers(unsigned int size);

void make_star(unsigned int size)
{
    make_first_last_line(size);
    make_conne(size);
    make_bra(size);
    make_cor_one(size);
    make_cor_two(size);
    make_bra(size);
    make_conne_revers(size);
    make_first_last_line(size);
}

void star(unsigned int size)
{
    if (size == 1) {
        star_one();
    }
    if (size > 1) {
        make_star(size);
    }
}
