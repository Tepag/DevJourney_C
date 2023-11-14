/**
 * @file backup_all_v2.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief introduzione della aggiunta del nome backup non dopo l'estensione
 * @version 0.2
 * @date 2021-12-20
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define LIMIT 255

int main()
{
    char *tmp_str = NULL, *pointer = NULL; // puntatore ad una stringa malloc
    char *tmp_ext;                         // puntatore sringa malloc per la estensione
    char tmp_box;                          // cella di transito da sorgente a destinatario
    DIR *dir_p = opendir("./to_backup");   // serve SOLO a PUNTARE LA CARTELLA
    struct dirent *dir_file_struct;        // puntatore a struttura, con la opendir ottengo la struttura per i file contenenti

    if (dir_p != NULL) // vado a verificare se il puntatore di dir è stato trovato o meno
    {
        // readdir -> ritorna lo struct della directory; nella riga successiva vado a girare tutti i nomi presenti nella cartella
        while ((dir_file_struct = readdir(dir_p)) != NULL)
        {
            // evito la "." e la ".."
            if ((strcmp(dir_file_struct->d_name, ".") == 0) || (strcmp(dir_file_struct->d_name, "..") == 0))
                continue;

            // per ogni file vado a creare un puntatore al file sorgente, dalla quale devo copiare il codice
            tmp_str = (char *)malloc(LIMIT * sizeof(char));
            tmp_ext = (char *)malloc(LIMIT * sizeof(char));
            strcpy(tmp_str, "./to_backup/");
            strcat(tmp_str, dir_file_struct->d_name);

            // controllo che sia l'estensione
            pointer = strrchr(dir_file_struct->d_name, '.');
            if (pointer != NULL)
            {
                strcpy(tmp_ext, pointer);
                *pointer = '\0';
            }
            pointer = NULL;

            // puts(&tmp_ext[0]);
            FILE *fp_source = fopen(tmp_str, "rb+");

            // per ogni file vado a creare un nuovo file per scrivere i dati e aggiornando il nome
            strcpy(tmp_str, "./backuped/");
            strcat(tmp_str, dir_file_struct->d_name);
            strcat(tmp_str, "_backup");
            strcat(tmp_str, tmp_ext);
            FILE *fp_destination = fopen(tmp_str, "wb+");
            free(tmp_str);
            free(tmp_ext);

            // copiare tutto il contenuto ad uno a uno
            while (1)
            {
                if (feof(fp_source) == 1)
                    break;
                fread(&tmp_box, 1, 1, fp_source);
                fwrite(&tmp_box, 1, 1, fp_destination);
            }

            // free & close malloc & file
            fclose(fp_destination);
            fclose(fp_source);
        }
        closedir(dir_p);
    }
    return (0);
}
