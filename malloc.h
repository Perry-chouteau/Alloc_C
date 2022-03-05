/*
** EPITECH PROJECT, 2021
** 2epi_github
** File description:
** malloc.h
*/

#ifndef MALLOC_H
#define MALLOC_H

#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bloc_s bloc_t;

struct bloc_s {
    void *ptr;
    size_t size;
    bool free;
};

void my_putstr(char *str);
void my_putnbr(int nb);

//function *alloc
bloc_t *bag_function(bloc_t *value);

//malloc
void *malloc(size_t size);
bloc_t *create_bloc(size_t size);
bloc_t *find_free_bloc(const size_t size);

//free
void free (void *ptr);
void find_alloc_bloc(const void *ptr);
void delete_bloc(void);

//calloc
void *calloc(size_t nmemb, size_t size);

//realloc
void *realloc(void *ptr, size_t size);
//void *copy_block(void *dest, void *src, size_t src_size, size_t size);

//reallocarray
void *reallocarray(void *ptr, size_t nmemb, size_t size);

//function *bloc

#endif
