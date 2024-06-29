#include "logger.h"

#include <time.h>

FILE *log_init(char *filename) {
    FILE *file;
    file = fopen(filename, "a");
    return file;
}

void logcat(FILE *log_file, char *message, enum log_level level) {
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    char time_str[9];
    strftime(time_str, sizeof(time_str), "%T", now);
    char log_note[256];
    switch (level) {
        case debug:
            snprintf(log_note, sizeof(log_note), "DEBUG %s %s\n", time_str, message);
            break;
        case info:
            snprintf(log_note, sizeof(log_note), "INFO %s %s\n", time_str, message);
            break;
        case warning:
            snprintf(log_note, sizeof(log_note), "WARNING %s %s\n", time_str, message);
            break;
        case error:
            snprintf(log_note, sizeof(log_note), "ERROR %s %s\n", time_str, message);
            break;
    }
    fputs(log_note, log_file);
}

void log_close(FILE *log_file) { fclose(log_file); }