#include "utils/FileManager.h"
#include "core/label/label_manager.h"

int readFile(vector* lines, const char* path, label_manager* label_manager) {
    FILE* file = fopen(path, "r");
    if (!file) {
        printf("[ERROR]: Unable to open file at %s\n", path);
        return 0;
    }
    int c;
    string line;
    string_init(&line, "");
    uint32_t address = 0;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            if (line.size > 0) {
                const char* str = string_c_str(&line);
                size_t len = line.size;
                if (len > 1 && str[len - 1] == ':') {
                    Label label;
                    label_init(&label);
                    string temp_name;
                    string_init(&temp_name, "");
                    for (size_t i = 0; i < len - 1; ++i) {
                        string_push_back(&temp_name, &str[i]);
                    }
                    label_set(&label, temp_name, address);
                    label_manager_add(label_manager, &label);
                    string_destructor(&temp_name);
                    label_destructor(&label);
                } else {
                    string copy;
                    string_init(&copy, str);
                    vector_push_back(lines, &copy);
                    address++;
                }
                string_clear(&line);
            }
        } else {
            char ch = (char)c;
            string_push_back(&line, &ch);
        }
    }
    if (line.size > 0) {
        const char* str = string_c_str(&line);
        size_t len = line.size;
        if (len > 1 && str[len - 1] == ':') {
            Label label;
            label_init(&label);
            string temp_name;
            string_init(&temp_name, "");
            for (size_t i = 0; i < len - 1; ++i) {
                string_push_back(&temp_name, &str[i]);
            }
            label_set(&label, temp_name, address);
            label_manager_add(label_manager, &label);
            string_destructor(&temp_name);
            label_destructor(&label);
        } else {
            string copy;
            string_init(&copy, str);
            vector_push_back(lines, &copy);
        }
    }
    string_destructor(&line);
    fclose(file);
    return 1;
}