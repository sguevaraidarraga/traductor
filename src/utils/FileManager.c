#include "utils/FileManager.h"
#include "structures/string.h"
#include "structures/vector.h"
#include <stdio.h>
#include <stdlib.h>

void readFile(vector* lines, const char* path) {
    FILE* file = fopen(path, "r");
    if (!file) {
        printf("[ERROR]: Unable to open file at %s\n", path);
        exit(EXIT_FAILURE);
    }

    int c;
    string line;
    string_init(&line, "");

    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            string copy;
            string_init(&copy, string_c_str(&line));
            vector_push_back(lines, &copy);
            string_clear(&line);
        } else {
            string_push_back(&line, (char*)&c);
        }
    }

    if (!string_empty(&line)) {
        string copy;
        string_init(&copy, string_c_str(&line));
        vector_push_back(lines, &copy);
    }

    string_destructor(&line);  // liberar buffer temporal
    fclose(file);
}