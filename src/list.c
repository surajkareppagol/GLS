#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"
#include "glyphs.h"
#include "args.h"

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

void render(char **list, int count)
{
  for (int i = 0; i < count; i++)
  {
    char *extension = getExtension(list[i], '.');

    char *filename = malloc(sizeof(char) * 1000);

    int typeIndex = getType(extension);
    sprintf(filename, "%lc %s", glyphs[typeIndex], list[i]);

    printf("%s\n", filename);

    free(extension);
    free(filename);
  }
}

void sort(char **list, int count)
{
  int last = count - 1;

  for (int i = 0; i < count; i++)
  {
    char *temporary = malloc(sizeof(char) * 1000);
    char *max = malloc(sizeof(char) * 1000);
    strcpy(max, list[0]);
    int maxI = 0;

    for (int j = 1; j < last + 1; j++)
    {
      if (list[j][0] > max[0])
      {
        strcpy(max, list[j]);
        maxI = j;
      }
    }

    strcpy(temporary, list[last]);
    strcpy(list[last], max);
    strcpy(list[maxI], temporary);
    last -= 1;

    free(temporary);
    free(max);
  }
}

void listDirectory(OPTIONS *options)
{

  char **list = (char **)malloc(sizeof(char *) * 10000);
  int files = 0;

  DIR *dp = opendir(options->directory);
  struct dirent *ep;

  if (dp == NULL)
  {
    perror("Error ");
    exit(EXIT_FAILURE);
  }

  while ((ep = readdir(dp)) != NULL)
  {
    if (strcmp(ep->d_name, ".") && strcmp(ep->d_name, "..") && ep->d_name[0] != '.' || options->displayAll)
    {
      list[files] = (char *)malloc(sizeof(char) * (strlen(ep->d_name) + 1));
      strcpy(list[files], ep->d_name);
      files++;
    }
  }

  closedir(dp);

  sort(list, files);

  render(list, files);

  free(list);

  printf("\n");
}