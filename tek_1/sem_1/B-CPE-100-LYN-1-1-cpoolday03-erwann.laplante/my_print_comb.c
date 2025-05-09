/*
** EPITECH PROJECT, 2021
** Task 05 - my_print_comb
** File description:
** This fill displays all the numbers composed by three different digits
*/

int result(hundreds, tens, unity)
{
    for (unity = tens + 1 ; unity <=9 ; unity++) {
        my_putchar(hundreds + 48);
        my_putchar(tens + 48);
        my_putchar(unity + 48);
        if (hundreds == 7 & tens == 8 & unity == 9) {
            return(0);
        }
        my_putchar(',');
        my_putchar(' ');
    }
    return(0);
}

int my_print_comb(void)
{
    char hundreds;
    char tens;
    char unity;

    for (hundreds = 0 ; hundreds <= 7 ; hundreds++) {
        for (tens = hundreds + 1 ; tens <=8 ; tens++) {
            result(hundreds, tens, unity);
        }
    }
    return(0);
}
