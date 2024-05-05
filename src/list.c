#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"
#include "glyphs.h"

int getType(char *extension)
{
  // Check for extensions and render it
  if (!strcmp(extension, "c"))
    return C;

  else if (!strcmp(extension, "py"))
    return PYTHON;

  else if (!strcmp(extension, "cpp"))
    return CPP;

  else if (!strcmp(extension, "cs"))
    return CSHARP;

  else if (!strcmp(extension, "css"))
    return CSS;

  else if (!strcmp(extension, "html"))
    return HTML;

  else if (!strcmp(extension, "js"))
    return JAVASCRIPT;

  else if (!strcmp(extension, "md"))
    return MARKDOWN;

  else if (!strcmp(extension, "txt"))
    return TEXT;

  else
    return UNKNOWN;
}

void render(char *filename)
{
  if (!strcmp(filename, ".") || !strcmp(filename, ".."))
    return;

  char extension[10];
  int index = 0;
  int extensionStart = 0;

  // Split and get extension
  for (int i = 0; i < strlen(filename); i++)
  {
    if (extensionStart)
    {
      extension[index++] = filename[i];
      continue;
    }
    else if (filename[i] == '.' && !extensionStart)
      extensionStart = 1;
  }

  extension[index] = '\0';

  int typeIndex = getType(extension);
  printf("%lc %s  ", glyphs[typeIndex], filename);

  memset(extension, 0, sizeof(extension));
}

void listDirectory(char *path)
{
  DIR *dp = opendir(path);
  struct dirent *ep;

  if (dp == NULL)
  {
    perror("Error ");
    exit(EXIT_FAILURE);
  }

  while ((ep = readdir(dp)) != NULL)
    render(ep->d_name);

  closedir(dp);

  printf("\n");
}