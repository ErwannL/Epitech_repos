/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGRUSH2-erwann.laplante
** File description:
** float
*/

#include "new.h"
#include "float.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    Class base;
    float flt;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if ((this == NULL) || args == NULL)
        raise("Null Ptr");
    this->flt = va_arg((*args), double);
}

static void Float_dtor(FloatClass *this)
{
    if (this == NULL)
        raise("Null Ptr");
    free(this);
}

static const char *Float_str(FloatClass *this)
{
    size_t size = 256;
    char *str = (char *)malloc(sizeof(char) * size);

    if (str == NULL)
        raise("Null Ptr");
    memset(str, 0x0, size);
    snprintf(str, size, "<%s (%f)>", this->base.__name__, this->flt);
    return str;
}

static FloatClass *Float_add(FloatClass *this, FloatClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Float, (this->flt + that->flt));
}

static FloatClass *Float_sub(FloatClass *this, FloatClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Float, (this->flt - that->flt));
}

static FloatClass *Float_mul(FloatClass *this, FloatClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Float, (this->flt * that->flt));
}

static FloatClass *Float_div(FloatClass *this, FloatClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Float, (this->flt / that->flt));
}

static bool Float_eq(FloatClass *this, FloatClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return (this->flt == that->flt);
}

static bool Float_gt(FloatClass *this, FloatClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return (this->flt > that->flt);
}

static bool Float_lt(FloatClass *this, FloatClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return (this->flt < that->flt);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .flt = 0,
};

const Class *Float = (const Class *)&_description;
