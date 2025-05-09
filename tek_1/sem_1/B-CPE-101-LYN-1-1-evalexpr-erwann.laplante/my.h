/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** description
*/

#ifndef STRUCT_
    #define  SSTRUCT_
    typedef struct variables
    {
        int nb1;
        int nb2;
        int x;
        int y;
        char op;
        int result;
        char *str;
        int digit_count;
        int digit_c;
    }variables_t;
    typedef struct prioriti
    {
        char *new_str;
        char *str_calc;
        char *tempo;
        int k;
        int count_p;
        int i;
    }prioriti_t;
    void my_putchar(char c);
    void my_putstr(char const *str);
    int my_put_nbr(int nb);
    int my_getnbr(char const *str);
    int my_strlen(char const *str);
    char *my_strcat(char *dest, char const *src);
    int nb_digit(int nb);
    int only_digit(char *str);
    char *if_parenthesis(char *str);
    char *if_minus_before(variables_t variables, char *calcul);
    variables_t eval_expr2(variables_t variables);
    char *val_to_string(int number);
    int diviser(int value1, int value2, int result);
    int calc(int nb1, char operator, int nb2);
    int eval_expr(char *calcul);
    int main(int ac, char **av);
    int if_one (char *calcul);
    prioriti_t sort3(prioriti_t prioriti, char *calcul);
    int parenthesis(prioriti_t prioriti, char *calcul, int i);
    prioriti_t sort2(prioriti_t prioriti, char *calcul);
    char *sort(char *calcul);
    char *reset(char *str);
#endif
