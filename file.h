#ifndef FILE_H
#define FILE_H 

#include <stdio.h>
#include <string.h>
#include "menu.h"

FILE *checkFileExistence(char *fileName, char *fileHandling_method, int createFileIfNotExist);

#endif