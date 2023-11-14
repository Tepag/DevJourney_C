/**
 * @file backup_all_v4.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief update with more choose flexibility
 * @version 0.4
 * @date 2021-12-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define LIMIT 255

/**
 * @brief Function which create malloc space for inserted string
 * @param char* input message
 * @return char* pointer to first malloc cell
 */
char *input_str(char *);

/**
 * @brief
 * @param FILE** puntatore al puntatore del file sorgente
 * @param FILE** puntatore al puntatore del file destinatario
 * struct dirent * struttura della directory con il file
 * char * nome da aggiungere
 * @return void
 */
void frename_between_name_ext(FILE **, FILE **, char *, char *);

/**
 * @brief Funzione che copia pari pari da un file ad un'altro
 * @param FILE* puntatore al file sorgente
 * @param FILE* puntatore al file destinatario
 * @return void
 */
void fcpy(FILE *, FILE *);

typedef enum
{
    found = 1,
    not_found = 2,
    confirm = 4,
} Flag_enum;

int main()
{
    struct dirent *dir_file_struct;   // puntatore a struttura, con la opendir ottengo la struttura per i file contenenti
    FILE *fp_source, *fp_destination; // i due puntatori a file
    Flag_enum flags = 0;
    DIR *dir_p = NULL;
    char *p_wtoadd = input_str("\nnome da aggiungere ai file backup: ");
    char *pathSP = NULL;

    // 0. path selection
    // 0.1. source path selction
    do
    {
        pathSP = input_str("\ninsert to backup folder path (Example: D:/USER/my_name/to_backup_folder_name/): ");
        dir_p = opendir(pathSP);
        if (dir_p != NULL)
        {
            flags += found;
        }
        else
        {
            printf("\nPlease, insert another path");
        }
    } while ((flags & found) == 0);

    // 0.2. destination path
    // char *pathDP = input_str("where do you want to backup (Example: D:/USER/my_name/backuped_folder_name/): ");

    // vado a verificare se il puntatore di dir è stato trovato o meno
    {
        // readdir -> ritorna lo struct della directory; nella riga successiva vado a girare tutti i nomi presenti nella cartella
        while ((dir_file_struct = readdir(dir_p)) != NULL)
        {
            // evito la "." e la ".."
            if ((strcmp(dir_file_struct->d_name, ".") == 0) || (strcmp(dir_file_struct->d_name, "..") == 0))
                continue;

            // creo i file con nomi modificati
            frename_between_name_ext(&fp_source, &fp_destination, dir_file_struct->d_name, p_wtoadd);

            // copio pari pari i contenuti
            fcpy(fp_source, fp_destination);

            // free & close malloc & file
            fclose(fp_destination);
            fclose(fp_source);
        }
    }

    closedir(dir_p);
    free(p_wtoadd);
    return (0);
}

char *input_str(char *text)
{
    char *str = (char *)malloc(sizeof(char));
    int i = 0, flag = 0;
    printf("%s", text);
    for (; flag == 0; i++)
    {
        str = (char *)realloc(str, (sizeof(char) * (i + 2)));
        *(str + i) = getchar();
        if (*(str + i) == '\n')
        {
            *(str + i) = '\0';
            flag++;
        }
    }
    return str;
}

void frename_between_name_ext(FILE **fp_source, FILE **fp_destination, char *file_name, char *word_to_add)
{
    char *tmp_str = (char *)malloc(LIMIT * sizeof(char));
    char *tmp_ext = NULL, *pointer_ext = NULL;

    // TODO: rendere il path variabile
    strcpy(tmp_str, "./to_backup/");
    strcat(tmp_str, file_name);

    pointer_ext = strrchr(file_name, '.');

    tmp_ext = (char *)malloc((strlen(pointer_ext) + 1) * sizeof(char));
    if (pointer_ext != NULL)
    {
        strcpy(tmp_ext, pointer_ext);
        *pointer_ext = '\0';
    }
    pointer_ext = NULL;

    *fp_source = fopen(tmp_str, "rb+");

    // TODO: rendere il path variabile
    strcpy(tmp_str, "./backuped/");

    strcat(tmp_str, file_name);
    strcat(tmp_str, word_to_add);
    strcat(tmp_str, tmp_ext);
    *fp_destination = fopen(tmp_str, "wb+");

    free(tmp_str);
    free(tmp_ext);
}

void frename_between_name_ext_v2(FILE **fp_source, FILE **fp_destination, char *file_name, char *word_to_add)
{
    char *tmp_str = (char *)malloc(LIMIT * sizeof(char));
    char *tmp_ext = NULL, *pointer_ext = NULL;

    // TODO: rendere il path variabile
    strcpy(tmp_str, "./to_backup/");
    strcat(tmp_str, file_name);

    pointer_ext = strrchr(file_name, '.');

    tmp_ext = (char *)malloc((strlen(pointer_ext) + 1) * sizeof(char));
    if (pointer_ext != NULL)
    {
        strcpy(tmp_ext, pointer_ext);
        *pointer_ext = '\0';
    }
    pointer_ext = NULL;

    *fp_source = fopen(tmp_str, "rb+");

    // TODO: rendere il path variabile
    strcpy(tmp_str, "./backuped/");

    strcat(tmp_str, file_name);
    strcat(tmp_str, word_to_add);
    strcat(tmp_str, tmp_ext);
    *fp_destination = fopen(tmp_str, "wb+");

    free(tmp_str);
    free(tmp_ext);
}

// TODO: Fix this
void fcpy(FILE *fp_source, FILE *fp_destination)
{
    char tmp_box;
    while (1)
    {
        if (feof(fp_source) == 1)
            break;
        fread(&tmp_box, sizeof(char), 1, fp_source);
        fwrite(&tmp_box, sizeof(char), 1, fp_destination);
    }
}
