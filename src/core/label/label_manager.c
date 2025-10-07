#include "core/label/label_manager.h"

void label_manager_init(LabelManager* manager) {
    if(!manager) {
        printf("[ERROR]: Null pointer passed to label_manager_init.\n");
        exit(EXIT_FAILURE);
    }
    vector_init(&manager->labels, sizeof(Label));
}
void label_manager_destructor(LabelManager* manager) {
    if(!manager) {
        printf("[ERROR]: Null pointer passed to label_manager_destructor.\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < manager->labels.size; i++) {
        Label* label = (Label*)vector_at(&manager->labels, i);
        label_destructor(label);
    }
    vector_destructor(&manager->labels);
}
void label_manager_add(LabelManager* manager, Label* label) {
    if(!manager || !label) {
        printf("[ERROR]: Null pointer passed to label_manager_add.\n");
        exit(EXIT_FAILURE);
    }
    Label temp;
    label_init(&temp);
    label_set(&temp, label->name, label->address);
    vector_push_back(&manager->labels, &temp);
}
Label* label_manager_find(LabelManager* manager, const string name) {
    if(!manager) {
        printf("[ERROR]: Null pointer passed to label_manager_find.\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < manager->labels.size; i++) {
        Label* label = (Label*)vector_at(&manager->labels, i);
        if(string_compare(&label->name, &name) == 0) {
            return label;
        }
    }
    return NULL;
}
size_t label_manager_size(LabelManager* manager) {
    if(!manager) {
        printf("[ERROR]: Null pointer passed to label_manager_size.\n");
        exit(EXIT_FAILURE);
    }
    return manager->labels.size;
}
void label_manager_print(LabelManager* manager) {
    if(!manager) {
        printf("[ERROR]: Null pointer passed to label_manager_print.\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < manager->labels.size; i++) {
        const Label* label = (Label*)vector_at(&manager->labels, i);
        print_label(label);
    }
}