/*
** EPITECH PROJECT, 2023
** B-PDG-300-LYN-3-1-PDGRUSH2-erwann.laplante
** File description:
** new
*/

#include "new.h"
#include "raise.h"
#include "object.h"
#include "player.h"

Object *new(const Class *class, ...)
{
    va_list list;

    va_start(list, class);
    return va_new(class, &list);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *object;

    if (class == NULL || ap == NULL)
        raise("Null Ptr");
    if ((object = (Object *)malloc(class->__size__)) == NULL)
        raise("Malloc failed.");
    memcpy(object, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(object, ap);
    va_end(*ap);
    if (object == NULL)
        raise("Malloc failed.");
    return object;
}

void delete(Object *ptr)
{
    if (ptr == NULL)
        raise("Null Ptr");
    if (((Class *)ptr)->__dtor__)
        ((Class *)ptr)->__dtor__(ptr);
    free(ptr);
}
