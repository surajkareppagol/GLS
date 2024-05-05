#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#include "list.h"

int main(int argc, char *argv[])
{
  setlocale(LC_CTYPE, "");

  if (argc == 1)
    listDirectory(".");
  else
    listDirectory(argv[1]);

  return 0;
}