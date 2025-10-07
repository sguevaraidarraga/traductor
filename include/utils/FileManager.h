#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core/label/label_manager.h"
#include "structures/string.h"
#include "structures/vector.h"

int readFile(vector*, const char*, label_manager*);

#endif