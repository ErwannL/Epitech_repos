/*
** EPITECH PROJECT, 2021
** EvalExpr
** File description:
** description
*/

#ifndef STRUCT_H
    #define  STRUCT_H
    #define SYNTAX_ERROR_MSG "syntax error"
    #define ERROR_MSG "error"
    typedef struct var
    {
        char *new_str;
        char *str_calc;
        int j;
        int k;
        int nbr_p;
        int i;
        int l;
        char *calcul;
        int tempo;
        char *base;
        char *operators;
        char *size_read;
        int val;
        int val_return;
        char *nbr1;
        char *nbr2;
        char op;
        int count;
        int cc;
        char *res;
    }var_t;
    typedef struct mult
    {
        int a;
        int b;
        int c;
        int j;
        char *result;
        int car;
        int o;
        int count;
    }mult_t;
    typedef struct divi
    {
        int a;
        int b;
        int c;
        int count;
        int op;
        int o;
        int opera;
        int car;
        char *res;
        int resu;
    }divi_t;
    typedef struct add
    {
        int len1;
        int len2;
        int len;
        char *new_str;
        int i;
        int nb;
        char *str;
        char *str2;
    }add_t;
    typedef struct modulo
    {
        char *res;
        char *res2;
        char *res3;
        int i;
    }modulo_t;
    typedef struct sous
    {
        char *str;
        char *str2;
        char *temp;
        char *real_str;
        int len1;
        int len2;
        int len;
        int bit;
        char *new_str;
        int i;
        int nbr;
        int nb;
    }sous_t;
    typedef struct calc
    {
        int j;
        int isneg1;
        int isneg2;
        int k;
    }calc_t;
    char *modulo(char *nbr1, char *nbr2);
    char *calc(var_t var);
    int my_getnbr(char const *str);
    int is_neg(char *number);
    int my_put_nbr(int nb);
    void my_putchar(char c);
    int my_putstr(char const *str);
    char *my_rev_str(char *str);
    char *my_strcat(char *dest, char const *src);
    int my_strcmp(char const *s1 , char const *s2);
    char *my_strdup(char const *src);
    int my_strlen(char const *str);
    add_t add5(add_t var);
    add_t add4(add_t var);
    add_t add3(add_t var);
    char *add2(add_t var);
    char *add(char *str, char *str2);
    char *sous2(char *str);
    char *following_minus(char *new_str, int bit);
    sous_t minus4(sous_t var);
    sous_t minus3(sous_t var);
    char *minus2(sous_t var);
    char *minus(char *str, char *str2);
    mult_t declar_var(mult_t var, char *nbr2, char *nbr1);
    mult_t next(mult_t var, char *nbr1);
    char *mult(char *nbr1, char *nbr2);
    var_t parenthis2(var_t var);
    var_t parenthis(var_t var);
    int my_char_in_op(var_t var, char c, int d);
    char *calc2(char *res);
    char *calc(var_t var);
    var_t signe_calc(var_t var);
    calc_t dec_var(calc_t var_calc);
    int my_char_in_base(var_t var, char c);
    int my_str_only_base(var_t var);
    char *dec_calc(var_t var);
    char *calculus(var_t var, calc_t var_calc);
    var_t parenthis3(var_t var);
    var_t declaration_var2(var_t var, char *size_read);
    var_t declaration_var(var_t var, char *calcul, char *base, \
    char *operators);
    int eval_expr(char *calcul, char *base, char *operators, char *size_read);
    int erro2_3(char **av, int i);
    int erro2_2(char **av, int i);
    int erro2_1(char **av, int i);
    int error2(char **av);
    int error(int ac, char **av);
    int main(int ac, char **av);
    char *division(char *nbr1, char *nbr2);
    void exit_function(void);
    char *reset_num(char *num);
    var_t reset_calc(var_t var);
    var_t calculus2(var_t var);
    char *calc3(var_t var);
#endif
