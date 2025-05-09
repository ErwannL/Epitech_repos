/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGRUSH2-erwann.laplante
** File description:
** char
*/

#include "new.h"
#include "char.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    Class base;
    char chr;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if ((this == NULL) || args == NULL)
        raise("Null Ptr");
    this->chr = va_arg((*args), int);
}

static void Char_dtor(CharClass *this)
{
    if (this == NULL)
        raise("Null Ptr");
    free(this);
}

static const char *Char_str(CharClass *this)
{
    size_t size = 256;
    char *str = (char *)malloc(sizeof(char) * size);

    if (str == NULL)
        raise("Null Ptr");
    memset(str, 0x0, size);
    snprintf(str, size, "<%s (%c)>", this->base.__name__, this->chr);
    return str;
}

static CharClass *Char_add(CharClass *this, CharClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Char, (this->chr + that->chr));
}

static CharClass *Char_sub(CharClass *this, CharClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Char, (this->chr - that->chr));
}

static CharClass *Char_mul(CharClass *this, CharClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Char, (this->chr * that->chr));
}

static CharClass *Char_div(CharClass *this, CharClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Char, (this->chr / that->chr));
}

static bool Char_eq(CharClass *this, CharClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return (this->chr == that->chr);
}

static bool Char_gt(CharClass *this, CharClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return (this->chr > that->chr);
}

static bool Char_lt(CharClass *this, CharClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return (this->chr < that->chr);
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .chr = 0,
};

const Class *Char = (const Class *)&_description;
