#ifndef LABEL_MANAGER_H
#define LABEL_MANAGER_H

#include "structures/vector.h"
#include "core/label/label.h"

typedef struct {
    vector labels;
} LabelManager;

void label_manager_init(LabelManager*);
void label_manager_destructor(LabelManager*);
void label_manager_add(LabelManager*, Label*);
Label* label_manager_find(LabelManager*, const string);
size_t label_manager_size(LabelManager*);
void label_manager_print(LabelManager*);

#endif