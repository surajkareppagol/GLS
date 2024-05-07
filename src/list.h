#ifndef _UTIL_H
#define _UTIL_H

int getType(char *extension);
char *getExtension(char *str, char delimeter);
void render(char **list, int count);
void sort(char **list, int count);
void listDirectory(char *path);

#endif