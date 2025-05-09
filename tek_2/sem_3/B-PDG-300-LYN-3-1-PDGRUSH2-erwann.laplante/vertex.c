/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGRUSH2-erwann.laplante
** File description:
** vertex
*/

#include "new.h"
#include <stdio.h>
#include <string.h>
#include "vertex.h"

typedef struct {
    Class base;
    int x, y, z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (this == NULL || args == NULL)
        raise("Null Ptr");
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
    this->z = va_arg((*args), int);
}

static void Vertex_dtor(VertexClass *this)
{
    if (this == NULL)
        raise("Null Ptr");
    (void)this;
}

static char *Vertex_str(VertexClass *this)
{
    size_t size = 256;
    char *str = (char *)malloc(sizeof(char) * size);

    if (str == NULL)
        raise("Null Ptr");
    memset(str, 0x0, size);
    snprintf(str, size, "<%s (%d, %d, %d)>",
                            this->base.__name__, this->x, this->y, this->z);
    return str;
}

static const Object *Vertex_add(VertexClass *this, VertexClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Vertex, (this->x + that->x), (this->y + that->y)
                                                        , (this->z + that->z));
}

static const Object *Vertex_sub(VertexClass *this, VertexClass *that)
{
    if ((this == NULL) || (that == NULL))
        raise("Null Ptr");
    return new(Vertex, (this->x - that->x), (this->y - that->y)
                                                        , (this->z - that->z));
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
