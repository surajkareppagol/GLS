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

char *getExtension(char *str, char delimeter)
{
  char *extension = malloc(sizeof(char) * 6);
  int extensionI = 0;

  // Split and get extension
  for (int i = 0; i < strlen(str); i++)
  {
    if (extensionI)
    {
      extension[extensionI - 1] = str[i];
      extensionI++;
      continue;
    }
    else if (str[i] == delimeter && !extensionI)
      extensionI = 1;
  }

  extension[extensionI - 1] = '\0';

  return extension;
}

void render(char *filename)
{
  if (!strcmp(filename, ".") || !strcmp(filename, ".."))
    return;

  char *extension = getExtension(filename, '.');

  int typeIndex = getType(extension);
  printf("%lc %s  ", glyphs[typeIndex], filename);

  free(extension);
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