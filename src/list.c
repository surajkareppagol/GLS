#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#include "list.h"
#include "glyphs.h"

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

  // Check for extensions and render it
  if (!strcmp(extension, "c"))
    printf("%lc %s  ", glyphs[C], filename);

  else if (!strcmp(extension, "py"))
    printf("%lc %s  ", glyphs[PYTHON], filename);

  else if (!strcmp(extension, "cpp"))
    printf("%lc %s  ", glyphs[CPP], filename);

  else if (!strcmp(extension, "cs"))
    printf("%lc %s  ", glyphs[CSHARP], filename);

  else if (!strcmp(extension, "css"))
    printf("%lc %s  ", glyphs[CSS], filename);

  else if (!strcmp(extension, "html"))
    printf("%lc %s  ", glyphs[HTML], filename);

  else if (!strcmp(extension, "js"))
    printf("%lc %s  ", glyphs[JAVASCRIPT], filename);

  else if (!strcmp(extension, "md"))
    printf("%lc %s  ", glyphs[MARKDOWN], filename);

  else if (!strcmp(extension, "txt"))
    printf("%lc %s  ", glyphs[TEXT], filename);

  memset(extension, 0, sizeof(extension));
}

void listDirectory(char *path)
{
  DIR *dp = opendir(path);
  struct dirent *ep;

  while ((ep = readdir(dp)) != NULL)
    render(ep->d_name);

  closedir(dp);

  printf("\n");
}