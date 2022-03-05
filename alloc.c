/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-perry.chouteau
** File description:
** alloc.c
*/

#include "malloc.h"
#include <pthread.h>


//realloc

void *malloc(size_t size);
void free (void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

void *malloc(size_t size)
{
    bloc_t *head = bag_function(NULL);
    bloc_t *new = NULL;
    if (size == 0)
        return NULL;
    if (head != NULL) { //2
        new = find_free_bloc(size);
        if (new != NULL) {
            return new->ptr;
        }
    }
    new = create_bloc(size); //3
    if (new != NULL) {
        return new->ptr;
    }
    return NULL;
}

void free (void *ptr)
{
    if (ptr == NULL)
		return;
    bloc_t *to_free = (void *)(((char *)ptr) - sizeof(bloc_t));
    to_free->free = true;
    delete_bloc();
}

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(size * nmemb);
    void *save = ptr;
    if (ptr == NULL)
        return NULL;
    for (size_t i = 0 ; i < nmemb; ++i) {
        ptr = 0;
        ptr++;
    }
    return save;
}


void *realloc(void *ptr, size_t size)
{
    bloc_t *bloc;
    void *new_ptr;

    bloc = ptr - sizeof(bloc_t);
    if (size == 0) {
        free(ptr);
        return NULL;
    } else if (ptr == NULL || bloc->size >= size) {
        return (ptr == NULL) ? malloc(size) : ptr;
    } else {
        new_ptr = malloc(size);
        new_ptr = memcpy(new_ptr, ptr, bloc->size > size ? size : bloc->size);
        free(ptr);
        return (new_ptr);
    }
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return realloc(ptr, nmemb * size);
}