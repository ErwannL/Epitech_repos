/*
** EPITECH PROJECT, 2021
** Task 06 - my_print_comb2
** File description:
** This fill displays all the different combinations of two two-digit numbers
*/

int display_last(int val_one, int val_two)
{
    while (val_two <= 99) {
        my_putchar(val_one/10 +48);
        my_putchar(val_one%10 +48);
        my_putchar(' ');
        my_putchar(val_two/10 +48);
        my_putchar(val_two%10 +48);
        val_two++;
        }
    return(0);
}

int my_print_comb2(void)
{
    int value_one = 0;
    int value_two = 1;

    while (value_one < 98) {
        while( value_two <= 99) {
            my_putchar(value_one/10 +48);
            my_putchar(value_one%10 +48);
            my_putchar(' ');
            my_putchar(value_two/10 +48);
            my_putchar(value_two%10 +48);
            my_putchar(',');
            my_putchar(' ');
            value_two++;
        }
        value_one++;
        value_two=value_one+1;
    }
    display_last(value_one,value_two);
    return(0);
}
