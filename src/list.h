#ifndef _UTIL_H
#define _UTIL_H

#include "args.h"

int getType(char *extension);

char *getExtension(char *str, char delimeter);

void render(char **list, int count);

void sort(char **list, int count);

void listDirectory(OPTIONS *options);

#endif