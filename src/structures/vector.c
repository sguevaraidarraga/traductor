#include "structures/vector.h"

void vector_init(vector *vec, const size_t element_size) {
    if (!vec || element_size == 0) {
        printf("[ERROR]: Invalid arguments to vector_init.\n");
        exit(EXIT_FAILURE);
    }
    vec->size = 0;
    vec->capacity = 10;
    vec->element_size = element_size;
    vec->data = malloc(vec->capacity * vec->element_size);
    if (vec->data == NULL) {
        printf("[ERROR]: Vector memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}
void vector_destructor(vector *vec) {
    if (!vec) {
        printf("[ERROR]: Null pointer passed to vector_destructor.\n");
        exit(EXIT_FAILURE);
    }
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
    vec->element_size = 0;
}
size_t vector_size(const vector *vec) {
    if (!vec) {
        printf("[ERROR]: Null pointer passed to vector_size.\n");
        exit(EXIT_FAILURE);
    }
    return vec->size;
}
void vector_resize(vector* vec, const size_t new_capacity) {
    if (!vec) {
        printf("[ERROR]: Null pointer passed to vector_resize.\n");
        exit(EXIT_FAILURE);
    }
    if (new_capacity == 0) {
        free(vec->data);
        vec->data = NULL;
        vec->capacity = 0;
        vec->size = 0;
        return;
    }
    void* temp = realloc(vec->data, new_capacity * vec->element_size);
    if (temp == NULL) {
        printf("[ERROR]: Vector memory allocation failed in vector_resize.\n");
        free(vec->data);
        exit(EXIT_FAILURE);
    }
    vec->data = temp;
    if (vec->size > new_capacity) {
        vec->size = new_capacity;
    }
    vec->capacity = new_capacity;
}
int vector_empty(const vector* vec) {
    if (!vec) {
        printf("[ERROR]: Null pointer passed to vector_empty.\n");
        exit(EXIT_FAILURE);
    }
    return vec->size == 0;
}
void* vector_at(const vector* vec, const size_t index) {
    if (!vec) {
        printf("[ERROR]: Null pointer passed to vector_at.\n");
        exit(EXIT_FAILURE);
    }
    if (index >= vec->size) {
        printf("[ERROR]: Index %zu is out of bounds in vector_at.\n", index);
        exit(EXIT_FAILURE);
    }
    return (char*)vec->data + (index * vec->element_size);
}
void* vector_front(const vector* vec) {
    if (!vec) {
        printf("[ERROR]: Null pointer passed to vector_front.\n");
        exit(EXIT_FAILURE);
    }
    if (vec->size == 0) {
        printf("[ERROR]: vector_front called on empty vector.\n");
        exit(EXIT_FAILURE);
    }
    return vec->data;
}
void* vector_back(const vector* vec) {
    if (!vec) {
        printf("[ERROR]: Null pointer passed to vector_back.\n");
        exit(EXIT_FAILURE);
    }
    if (vec->size == 0) {
        printf("[ERROR]: vector_back called on empty vector.\n");
        exit(EXIT_FAILURE);
    }
    return (char*)vec->data + ((vec->size - 1) * vec->element_size);
}
void vector_push_back(vector* vec, const void* element) {
    if (!vec || !element) {
        printf("[ERROR]: Null pointer passed to vector_push_back.\n");
        exit(EXIT_FAILURE);
    }
    if (vec->size == vec->capacity) {
        size_t new_capacity = (vec->capacity == 0) ? 2 : vec->capacity * 2;
        vector_resize(vec, new_capacity);
    }
    void* destination = (char*)vec->data + vec->size * vec->element_size;
    memcpy(destination, element, vec->element_size);
    vec->size++;
}
void vector_pop_back(vector* vec) {
    if (!vec) {
        printf("[ERROR]: Null pointer passed to vector_pop_back.\n");
        exit(EXIT_FAILURE);
    }
    if (vec->size == 0) {
        printf("[WARNING]: vector_pop_back called on empty vector.\n");
        return;
    }
    vec->size--;
}
void vector_clear(vector *vec) {
    if (!vec) {
        printf("[ERROR]: Null pointer passed to vector_clear.\n");
        exit(EXIT_FAILURE);
    }
    vec->size = 0;
}