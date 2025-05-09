/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGRUSH2-erwann.laplante
** File description:
** Int
*/

#include "new.h"
#include "int.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    Class base;
    int i;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if ((this == NULL) || args == NULL)
        raise("Null Ptr");
    this->i = va_arg((*args), int);
}

static void Int_dtor(IntClass *this)
{
    if (this == NULL)
        raise("Null Ptr");
    free(this);
}

static const char *Int_str(IntClass *this)
{
    size_t size = 256;
    char *str = (char *)malloc(sizeof(char) * size);

    if (str == NULL)
        raise("Null Ptr");
    memset(str, 0x0, size);
    snprintf(str, size, "<%s (%i)>"
                                    , this->base.__name__, this->i);
    return str;
}

static IntClass *Int_add(IntClass *this, IntClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Int, (this->i + that->i));
}

static IntClass *Int_sub(IntClass *this, IntClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Int, (this->i - that->i));
}

static IntClass *Int_mul(IntClass *this, IntClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Int, (this->i * that->i));
}

static IntClass *Int_div(IntClass *this, IntClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Int, (this->i / that->i));
}

static bool Int_eq(IntClass *this, IntClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return (this->i == that->i);
}

static bool Int_gt(IntClass *this, IntClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return (this->i > that->i);
}

static bool Int_lt(IntClass *this, IntClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return (this->i < that->i);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .i = 0,
};

const Class *Int = (const Class *)&_description;
