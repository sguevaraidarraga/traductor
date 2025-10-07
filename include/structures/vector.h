#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void* data;
    size_t size, capacity, element_size;
} vector;

void vector_init(vector*, const size_t);
void vector_destructor(vector*);

// Capacity
size_t vector_size(const vector*);
void vector_resize(vector*, const size_t);
int vector_empty(const vector*);

// Element access
void* vector_at(const vector*, const size_t);
void* vector_front(const vector*);
void* vector_back(const vector*);

// Modifiers
void vector_push_back(vector*, const void*);
void vector_pop_back(vector*);
void vector_clear(vector*);

#endif