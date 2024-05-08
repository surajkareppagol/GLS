#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "args.h"

int main(int argc, char *argv[])
{
  setlocale(LC_CTYPE, "");

  OPTIONS options;

  options.displayAll = false;
  options.directory = malloc(sizeof(argc) * 1000);

  strcpy(options.directory, ".");

  if (argc == 1)
    listDirectory(&options);
  else
  {
    getArgs(argc, argv, &options);
    listDirectory(&options);
  }

  return 0;
}