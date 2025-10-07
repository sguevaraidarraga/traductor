#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size, capacity;
} string;

void string_init(string*, const char*);
void string_destructor(string*);

// Capacity
size_t string_size(const string*);
size_t string_length(const string*);
void string_resize(string* str, const size_t);
int string_empty(const string*);

// Element access
char string_at(const string*, int);
char* string_back(const string*);
char* string_front(const string*);

// Modifiers
void string_append(string*, const char*);
void string_push_back(string*, const void*);
void string_assign(string*, const char*);
void string_pop_back(string*);
void string_clear(string*);

// Operations
const char* string_c_str(const string*);
int string_find(const string*, const char*);
int string_compare(const string*, const string*);

#endif