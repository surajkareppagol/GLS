#include <unistd.h>
#include <getopt.h>
#include <string.h>

#include <stdlib.h>

#include "args.h"

OPTIONS *getArgs(int argc, char **argv, OPTIONS *options)
{
  for (int i = 1; i < argc; i++)
  {
    if (!strcmp(argv[i], "-a"))
      options->displayAll = true;
    else
      strcpy(options->directory, argv[i]);
  }

  return options;
}
