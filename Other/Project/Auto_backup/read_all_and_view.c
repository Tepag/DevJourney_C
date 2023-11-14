/**
 * This program displays the names of all files in the current directory.
 */

#include <dirent.h>
#include <stdio.h>

int main(void)
{
  // puntatore con una struttura contenente i file all'interno di un folder
  DIR *d = opendir("./to_backup");
  struct dirent *dir;

  // vado a verificare se d esiste o meno
  if (d != NULL)
  {

    // giro per ogni nome dei file
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }

  return (0);
}
