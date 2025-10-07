#ifndef APP_H
#define APP_H

#include <stdio.h>
#include "core/label/label_manager.h"

typedef struct {
    label_manager lm;
} App;

void app_init(App*);
void app_destructor(App*);
int app_main_menu(App*);
void app_load_file(App*);

#endif