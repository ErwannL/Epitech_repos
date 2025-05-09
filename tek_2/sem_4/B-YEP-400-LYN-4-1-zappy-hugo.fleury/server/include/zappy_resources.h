/*
** EPITECH PROJECT, 2023
** antoine
** File description:
** zappy_resources
*/

#ifndef ZAPPY_RESOURCES_H_
    #define ZAPPY_RESOURCES_H_

    #include <stdlib.h>

    enum res_type_s {
        FOOD,
        LINEMATE,
        DERAUMERE,
        SIBUR,
        MENDIANE,
        PHIRAS,
        THYSTAME,
    };

    typedef enum res_type_s res_type_t;

    typedef struct resources_s {
        res_type_t key;
        int amount;
        struct resources_s *next;
    } resources_t;

    /* @param resources_t **resource => resources_t chained
    ** list adress (&myftp->tiles)
    ** @param res_type_t key => enum {FOOD,  LINEMATE, DERAUMERE, SIBUR,
    ** MENDIANE, PHIRAS, THYSTAME} OR unsigned int matching with enum index
    */
    int new_resource(resources_t **, res_type_t);

    /* @param resources_t *resource => resources_t chained
    ** list (myftp->tiles)
    ** @param res_type_t key => enum {FOOD,  LINEMATE, DERAUMERE, SIBUR,
    ** MENDIANE, PHIRAS, THYSTAME} OR unsigned int matching with enum index
    ** @retval specified resource amount
    */
    int get_resource(resources_t *, res_type_t);

    /* @param resources_t *resource => resources_t chained
    ** list (myftp->tiles)
    ** @param res_type_t key => enum {FOOD,  LINEMATE, DERAUMERE, SIBUR,
    ** MENDIANE, PHIRAS, THYSTAME} OR unsigned int matching with enum index
    ** @param amount => resource amount to change with
    */
    int change_resource_amount(resources_t *, res_type_t, int);
    int init_resources(resources_t **);

#endif /* !ZAPPY_RESOURCES_H_ */
