#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"
#include "glyphs.h"

int getType(char *extension)
{
  for (int i = 0; i < extensions; i++)
    if (!strcmp(extension, types[i]))
      return i;

  return extensions;
}

char *getExtension(char *str, char delimeter)
{
  char *extension = malloc(sizeof(char) * 6);
  int eIndex = 0;

  // Split and get extension
  for (int i = 0; i < strlen(str); i++)
  {
    if (eIndex)
    {
      extension[(eIndex++) - 1] = str[i];
      continue;
    }
    else if (str[i] == delimeter && !eIndex)
      eIndex = 1;
  }

  extension[eIndex - 1] = '\0';

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