/**
 * @file logger.c
 * @brief Implementation of the logger module.
 * @author Your Name
 * @date 2025-08-09
 */

#include "logger.h"
#include <stdio.h>
#include <time.h>
#include <stddef.h> // For NULL

#define LOG_FILE_NAME "weather_log.txt"

static FILE* log_file = NULL;

int logger_init(void) {
    // Open the log file in "write" mode to start fresh for this advanced run
    log_file = fopen(LOG_FILE_NAME, "w");
    if (log_file == NULL) {
        perror("Error opening log file");
        return 0;
    }
    fprintf(log_file, "--- Weather Log Initialized ---\n");
    return 1;
}

void logger_log_raw_data(const WeatherData* data) {
    if (log_file == NULL || data == NULL) {
        return;
    }

    time_t now = time(NULL);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&now));

    char buffer[200];
    snprintf(buffer, sizeof(buffer), "[%s] RAW - Temp: %.1f C, Hum: %.1f %%, Pres: %.1f hPa",
           time_str, data->temperature, data->humidity, data->pressure);
    
    printf("%s\n", buffer);
    fprintf(log_file, "%s\n", buffer);
    fflush(log_file);
}

void log_processed_data(const char* message) {
    if (log_file == NULL || message == NULL) {
        return;
    }
    
    time_t now = time(NULL);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&now));

    char buffer[200];
    snprintf(buffer, sizeof(buffer), "[%s] PROCESSED - %s", time_str, message);

    printf("%s\n", buffer);
    fprintf(log_file, "%s\n", buffer);
    fflush(log_file);
}

void logger_close(void) {
    if (log_file != NULL) {
        fprintf(log_file, "--- Log Closed ---\n");
        fclose(log_file);
        log_file = NULL;
    }
}
