/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-perry.chouteau
** File description:
** bloc.c
*/

#include "malloc.h"

bloc_t *bag_function(bloc_t *value)
{
    //my_putstr("bag_function\n");
    static bloc_t *save = NULL;
    if (value != NULL) {
        save = value;
    }
    return save;
}

bloc_t *create_bloc(size_t size)
{
    //my_putstr("create_bloc\n");
    bloc_t *tail = sbrk((sizeof(bloc_t))); //alloc

    if (tail == (void *)-1) { //handler error 
        return NULL;
    }
    tail->size = size;
    tail->free = false;
    tail->ptr = sbrk(size); //set_value
    if (tail == (void *)-1) { //handler error 
        return NULL;
    }
    if (bag_function(NULL))
        bag_function(tail);
    //my_putstr("bloc_create\n");
    return tail;
}

bloc_t *find_free_bloc(size_t size)
{
    //my_putstr("find_free_bloc\n");
    bloc_t *head = bag_function(NULL);
    bloc_t *mid = head;
    bloc_t *tail = sbrk(0);
    bloc_t *best = head;

    mid = head;
    while (mid < tail) { //best target size
        if (mid->free == true && mid->size >= size && mid->size < best->size)
            best = mid;
        mid = ((bloc_t*) ((char *) mid) +(sizeof(bloc_t) + mid->size));
    }
    if (best->size >= size && best->free == true) {
        best->free = false;
        return best;
    } else
        return NULL;
}

void delete_bloc(void)
{
    //my_putstr("delete_bloc\n");
    bloc_t *head = bag_function(NULL);
    bloc_t *mid = head;
    bloc_t *tail = sbrk(0);
    size_t len = 0;

    if (mid == NULL)
        return;
    while ((((char *) mid) + sizeof(bloc_t) + mid->size) < (char *)tail) {
        if (mid->free == true) {
            ++len;
        } else {
            len = 0;
        }
        mid = ((bloc_t*) ((char *) mid) +(sizeof(bloc_t) + mid->size));
    }
    for (size_t i = 0; i < len; i++, mid = head) {
        while ((((char *)mid) + sizeof(bloc_t) + mid->size) < (char *)tail) {
                mid = ((bloc_t*) ((char *) mid) +(sizeof(bloc_t) + mid->size));
        }
        tail = sbrk((sizeof(bloc_t) + mid->size) * (-1));
    }
}

