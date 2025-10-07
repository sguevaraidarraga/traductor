#include "app.h"

int main() {
    App a;
    app_init(&a);
    while(!app_main_menu(&a));
    app_destructor(&a);
    return 0;
}