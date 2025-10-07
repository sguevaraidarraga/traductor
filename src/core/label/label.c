#include "core/label/label.h"

void label_init(Label* label) {
    if(!label) {
        printf("[ERROR]: Null pointer passed to label_init.\n");
        exit(EXIT_FAILURE);
    }
    string_init(&label->name, "");
    label->address = 0;
}
void label_destructor(Label* label) {
    if(!label) {
        printf("[ERROR]: Null pointer passed to label_destructor.\n");
        exit(EXIT_FAILURE);
    }
    string_destructor(&label->name);
    label->address = 0;
}
void label_set(Label* label, const string name, const uint32_t address) {
    if(!label) {
        printf("[ERROR]: Null pointer passed to label_set.\n");
        exit(EXIT_FAILURE);
    }
    string_assign(&label->name, string_c_str(&name));
    label->address = address;
}
int label_compare(const Label* label_a, const Label* label_b) {
    if(!label_a || !label_b) {
        printf("[ERROR]: Null pointer passed to label_compare.\n");
        exit(EXIT_FAILURE);
    }
    if(label_a->address < label_b->address) return -1;
    if(label_a->address > label_b->address) return 1;
    return 0;
}
void print_label(const Label* label) {
    if(!label) {
        printf("[ERROR]: Null pointer passed to print_label.\n");
        exit(EXIT_FAILURE);
    }
    printf("Label: %s, Address: %u\n", string_c_str(&label->name), label->address);
}