#include "app.h"
#include <stdio.h>
#include "structures/vector.h"
#include "structures/string.h"
#include "utils/FileManager.h"
#include "core/label/label_manager.h"

void app_init(App* app) {
    label_manager_init(&app->lm);
}
void app_destructor(App* app) {
    label_manager_destructor(&app->lm);
}
int app_main_menu(App* app) {
    int f = 0, cmd;
    printf("\n");
    printf("-------------------------------------------------\n");
    printf("1. Cargar archivo\n");
    printf("2. Mostrar Labels\n");
    printf("3. Salir\n");
    printf("-------------------------------------------------\n");
    scanf("%d", &cmd);
    printf("\n");
    switch(cmd) {
        case 1:
            app_load_file(app);
            break;
        case 2:
            label_manager_print(&app->lm);
            break;
        case 3:
            f = 1;
            break;
    }
    return f;
}
void app_load_file(App* app) {
    vector lines;
    vector_init(&lines, sizeof(string));
    if (!readFile(&lines, "../files/in.txt", &app->lm)) {
        printf("[ERROR]: Could not read file.\n");
        vector_destructor(&lines);
        label_manager_destructor(&app->lm);
        return;
    }
    printf("=== Lines ===\n");
    for (size_t i = 0; i < lines.size; ++i) {
        const string* line = (string*)vector_at(&lines, i);
        printf("%s\n", string_c_str(line));
    }
    printf("\n=== Labels ===\n");
    label_manager_print(&app->lm);
    for (size_t i = 0; i < lines.size; ++i) {
        string* line = (string*)vector_at(&lines, i);
        string_destructor(line);
    }
    vector_destructor(&lines);
}