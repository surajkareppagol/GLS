#ifndef _ARGS_H_
#define _ARGS_H_

#include <stdio.h>
#include <stdbool.h>

struct options
{
  bool displayAll;
  char *directory;
};

typedef struct options OPTIONS;

OPTIONS *getArgs(int argc, char **argv, OPTIONS *options);

#endif