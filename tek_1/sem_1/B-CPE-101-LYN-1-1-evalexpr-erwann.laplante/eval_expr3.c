/*
** EPITECH PROJECT, 2021
** eval_expr
** File description:
** eval expr
*/
#include"my.h"
#include"stdlib.h"

int if_one(char *calcul)
{
    int count = 0;

    for (int i = 0; calcul[i] != '\0'; i++) {
        if (calcul[i] == '+' || calcul[i] == '-' || calcul[i] == '*' ||
        calcul[i] == '/' ||  calcul[i] == '%')
            count++;
    }
    return count;
}

int parenthesis(prioriti_t prioriti, char *calcul, int i)
{
    if (calcul[i] == '(')
        prioriti.count_p++;
    if (calcul[i] == ')')
        prioriti.count_p--;
    return (prioriti.count_p);
}

prioriti_t sort3(prioriti_t prioriti, char *calcul)
{
    int enter = prioriti.count_p;

    while (calcul[prioriti.i] != ')' && prioriti.count_p != 0) {
        prioriti.count_p = parenthesis(prioriti, calcul, prioriti.i);
        if (prioriti.count_p != enter) {
            prioriti.count_p--;
            break;
        }
        prioriti.i++;
        prioriti.str_calc[prioriti.k] = calcul[prioriti.i];
        prioriti.k++;
    }
    return (prioriti);
}

prioriti_t sort2(prioriti_t prioriti, char *calcul)
{
    prioriti.new_str = malloc(sizeof(calcul));
    prioriti.str_calc = malloc(sizeof(calcul) * 2);
    prioriti.tempo = malloc(sizeof(char) * 10);
    prioriti.k = 0;
    prioriti.count_p = 0;
    prioriti.i = 0;
    return (prioriti);
}

char *sort(char *calcul)
{
    prioriti_t prioriti;

    prioriti = sort2(prioriti, calcul);
    for (; calcul[prioriti.i] != '\0'; prioriti.i++) {
        prioriti.tempo = reset(prioriti.tempo);
        prioriti.tempo[0] = calcul[prioriti.i];
        prioriti.new_str = my_strcat(prioriti.new_str, prioriti.tempo);
        if (calcul[prioriti.i] == '(') {
            prioriti.count_p++;
            prioriti = sort3(prioriti, calcul);
            prioriti.tempo = reset(prioriti.tempo);
            prioriti.tempo = val_to_string(eval_expr(prioriti.str_calc));
            prioriti.new_str = my_strcat(prioriti.new_str, prioriti.tempo);
        }
    }
    return (prioriti.new_str);
}
