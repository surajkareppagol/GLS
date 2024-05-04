#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#include "list.h"

#define MAX 100

int main()
{
  setlocale(LC_CTYPE, "");
  listDirectory("../tests/");

  return 0;
}