#ifndef LABEL_H
#define LABEL_H

#include <stdint.h>
#include "structures/string.h"

typedef struct {
    string name;
    uint32_t address;
} Label;

void label_init(Label*);
void label_destructor(Label*);
void label_set(Label*, string, uint32_t);
int label_compare(const Label*, const Label*);
void print_label(const Label*);

#endif