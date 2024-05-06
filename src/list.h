#ifndef _UTIL_H
#define _UTIL_H

int getType(char *extension);
char *getExtension(char *str, char delimeter);
void render(char *filename);
void listDirectory(char *path);

#endif