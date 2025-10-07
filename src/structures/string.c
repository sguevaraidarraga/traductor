#include "structures/string.h"

void string_init(string *str, const char *value) {
    if (value == NULL) value = "";
    str->size = strlen(value);
    str->capacity = (str->size > 10) ? str->size : 10;
    str->data = malloc(str->capacity + 1);
    if (str->data == NULL) {
        printf("[ERROR]: String memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    memcpy(str->data, value, str->size);
    str->data[str->size] = '\0';
}
void string_destructor(string *str) {
    free(str->data);
    str->size = 0;
}
size_t string_size(const string *str) {
    return str->size;
}
size_t string_length(const string *str) {
    return str->size;
}
void string_resize(string *str, const size_t new_size) {
    char *temp = realloc(str->data, new_size + 1);
    if (temp == NULL) {
        printf("[ERROR]: String memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    str->data = temp;
    if (new_size > str->size) {
        memset(str->data + str->size, 0, new_size - str->size);
    }
    str->size = new_size;
    str->data[str->size] = '\0';
}
int string_empty(const string *str) {
    return str->size == 0;
}
char string_at(const string *str, const int index) {
    return str->data[index];
}
char* string_back(const string *str) {
    return &str->data[str->size - 1];
}
char* string_front(const string *str) {
    return &str->data[0];
}
void string_append(string *str, const char *value) {
    const size_t value_len = strlen(value);
    const size_t new_size = str->size + value_len;
    if (new_size > str->capacity) {
        string_resize(str, new_size * 2);
    } else {
        string_resize(str, new_size);
    }
    memcpy(str->data + str->size, value, value_len);
    str->size = new_size;
    str->data[str->size] = '\0';
}

void string_push_back(string* str, const void* ch) {
    const char c = *(const char*)ch;
    if (str->size + 1 > str->capacity) {
        string_resize(str, (str->capacity == 0) ? 2 : str->capacity * 2);
    } else {
        string_resize(str, str->size + 1);
    }
    str->data[str->size] = c;
    str->size++;
    str->data[str->size] = '\0';
}

void string_assign(string* str, const char* value) {
    const size_t value_len = strlen(value);
    if (value_len > str->capacity) {
        string_resize(str, value_len * 2);
    } else {
        string_resize(str, value_len);
    }
    memcpy(str->data, value, value_len);
    str->size = value_len;
    str->data[str->size] = '\0';
}

void string_pop_back(string* str) {
    if (str->size > 0) {
        str->size--;
        str->data[str->size] = '\0';
    }
}
void string_clear(string *str) {
    str->size = 0;
}
const char* string_c_str(const string* str) {
    return str->data;
}
int string_find(const string* str, const char* substr) {
    const char* pos = strstr(str->data, substr);
    if (pos) {
        return (int)(pos - str->data);
    }
    return -1;
}
int string_compare(const string* str1, const string* str2) {
    return strcmp(str1->data, str2->data);
}