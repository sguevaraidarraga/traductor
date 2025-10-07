#include "utils/FileManager.h"
#include "structures/string.h"
#include "structures/vector.h"
#include <stdio.h>

int main() {
    vector lines;
    vector_init(&lines, sizeof(string));

    readFile(&lines, "../files/in.txt");

    for (size_t i = 0; i < vector_size(&lines); i++) {
        const string* line = vector_at(&lines, i);
        printf("Line %zu: %s\n", i + 1, string_c_str(line));
    }

    // Liberar memoria
    for (size_t i = 0; i < vector_size(&lines); i++) {
        string* line = vector_at(&lines, i);
        string_destructor(line);
    }
    vector_destructor(&lines);

    return 0;
}