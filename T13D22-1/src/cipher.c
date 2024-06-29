#include <dirent.h>
#include <stdlib.h>

#include "logger.h"

void read_from_file(FILE *file, char *filename);
void write_in_file(FILE *file, char *string, char *filename);
void work_in_directory(char *dir_name, int shift);
void caesar_cipher(FILE *file, int shift);

int main(void) {
    int n = 0, shift = 0;
    char filename[100], input_data[100], dir_path[100];
    while (scanf("%d", &n) == 1 && (n == 1 || n == 2 || n == 3)) {
        FILE *f;
        switch (n) {
            case 1:
                scanf("%s", filename);
                f = fopen(filename, "r");
                read_from_file(f, filename);
                break;
            case 2:
                f = fopen(filename, "r+");
                scanf("%s", input_data);
                write_in_file(f, input_data, filename);
                break;
            case 3:
                scanf("%s", dir_path);
                if (scanf("%d", &shift) == 1) {
                    work_in_directory(dir_path, shift);
                } else {
                    printf("n/a");
                }
        }
        fclose(f);
    }
    if (n != -1) {
        printf("n/a");
    }
    return 0;
}

void read_from_file(FILE *file, char *filename) {
    strcat(filename, "");
    char sym = ' ';
    if (file && getc(file) != EOF) {
#ifdef LOG
        char mes[256];
        FILE *log = log_init("logs.log");
        snprintf(mes, sizeof(mes), "Файл \"%s\" открыт", filename);
        logcat(log, mes, info);
        log_close(log);
#endif
        rewind(file);
        while ((sym = getc(file)) != EOF) {
            printf("%c", sym);
        }
        printf("\n");
    } else {
#ifdef LOG
        char mes[256];
        FILE *log = log_init("logs.log");
        snprintf(mes, sizeof(mes), "Файл \"%s\" не был открыт", filename);
        logcat(log, mes, error);
        log_close(log);
#endif
        printf("n/a\n");
    }
}

void write_in_file(FILE *file, char *string, char *filename) {
    if (file) {
        fseek(file, 0, SEEK_END);
        fputs(string, file);
        rewind(file);
        read_from_file(file, filename);
#ifdef LOG
        char mes[256];
        FILE *log = log_init("logs.log");
        snprintf(mes, sizeof(mes), "В файл \"%s\" записана строка", filename);
        logcat(log, mes, info);
        log_close(log);
#endif
    } else {
#ifdef LOG
        char mes[256];
        FILE *log = log_init("logs.log");
        snprintf(mes, sizeof(mes), "Файл \"%s\" не был открыт", filename);
        logcat(log, mes, error);
        log_close(log);
#endif
        printf("n/a\n");
    }
}

void work_in_directory(char *dir_name, int shift) {
    FILE *f;
    DIR *d;
    struct dirent *dir;
    d = opendir(dir_name);
    if (d) {
#ifdef LOG
        char mes[256];
        FILE *log = log_init("logs.log");
        snprintf(mes, sizeof(mes), "Директория \"%s\" открыта", dir_name);
        logcat(log, mes, info);
        log_close(log);
#endif
        while ((dir = readdir(d)) != NULL) {
            char *filename = dir->d_name;
            char *ext = strchr(filename, '.');
            char filepath[100];
            snprintf(filepath, sizeof(filepath), "%s/%s", dir_name, filename);
            if (ext != NULL && strcmp(ext, ".h") == 0) {
                f = fopen(filepath, "w");
                fputs("", f);
                fclose(f);
#ifdef LOG
                char mes[256];
                FILE *log = log_init("logs.log");
                snprintf(mes, sizeof(mes), "Файл \"%s\" был изменён", filepath);
                logcat(log, mes, warning);
                log_close(log);
#endif
            } else if (ext != NULL && strcmp(ext, ".c") == 0) {
                f = fopen(filepath, "r+");
                caesar_cipher(f, shift);
#ifdef LOG
                char mes[256];
                FILE *log = log_init("logs.log");
                snprintf(mes, sizeof(mes), "Файл \"%s\" был зашифрован", filepath);
                logcat(log, mes, info);
                log_close(log);
#endif
            }
        }
    } else {
#ifdef LOG
        char mes[256];
        FILE *log = log_init("logs.log");
        snprintf(mes, sizeof(mes), "Директория \"%s\" не была открыта", dir_name);
        logcat(log, mes, error);
        log_close(log);
#endif
        printf("n/a\n");
    }
}

void caesar_cipher(FILE *file, int shift) {
    fseek(file, 0, SEEK_END);
    char *filestr = calloc(ftell(file) + 1, sizeof(char));
    rewind(file);
    int i = 0;
    while ((filestr[i] = getc(file)) != EOF) {
        filestr[i] = (char)((int)filestr[i] + shift);
        i++;
    }
    filestr[i] = '\0';
    rewind(file);
    fputs(filestr, file);
    fclose(file);
    free(filestr);
}