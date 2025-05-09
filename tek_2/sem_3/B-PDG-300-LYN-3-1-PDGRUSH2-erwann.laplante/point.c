/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGRUSH2-erwann.laplante
** File description:
** point
*/

#include <stdio.h>
#include <string.h>
#include "object.h"
#include "point.h"
#include "new.h"

typedef struct {
    Class base;
    int x, y;
} PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (this == NULL || args == NULL)
        raise("Null Ptr");
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
}

static void Point_dtor(PointClass *this)
{
    if (this == NULL)
        raise("Null Ptr");
    (void)this;
}

static char *Point_str(PointClass *this)
{
    size_t size = 256;
    char *str = (char *)malloc(sizeof(char) * size);

    if (str == NULL)
        raise("Null Ptr");
    memset(str, 0x0, size);
    snprintf(str, size, "<%s (%d, %d)>"
                                    , this->base.__name__, this->x, this->y);
    return str;
}

static PointClass *Point_add(PointClass *this, PointClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Point, this->x + that->x, this->y + that->y);
}

static PointClass *Point_sub(PointClass *this, PointClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Point, (this->x - that->x), (this->y - that->y));
}

static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
