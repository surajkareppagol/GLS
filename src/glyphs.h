#ifndef _GLYPHS_H_
#define _GLYPHS_H_

#include <wchar.h>
#define MAX 100

/* GLYPHS */

char *types[] = {
    "js", "c", "cpp", "cs", "html", "css", "txt", "md", "py"};

int extensions = 9;

wchar_t glyphs[MAX] = {0xe781, 0xf0671, 0xf0672, 0xf031b, 0xe736, 0xe749, 0xf09a8, 0xe73e, 0xe73c, 0xf15b};

#endif