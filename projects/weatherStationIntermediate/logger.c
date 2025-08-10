/**
 * @file logger.c
 * @brief Implementation of the logger module.
 * @author Your Name
 * @date 2025-08-08
 */

#include "logger.h"
#include <stdio.h>
#include <time.h>
#include <stddef.h> // For NULL

#define LOG_FILE_NAME "weather_log.txt"

// This file pointer is static, making it private to this module.
// No other file can access 'log_file' directly.
static FILE* log_file = NULL;

int logger_init(void) {
    // Open the log file in "append" mode.
    log_file = fopen(LOG_FILE_NAME, "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        return 0; // Failure
    }
    return 1; // Success
}

void logger_log_data(const WeatherData* data) {
    if (log_file == NULL || data == NULL) {
        return;
    }

    time_t now = time(NULL);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Log to console
    printf("[%s] Temp: %.1f C, Humidity: %.1f %%, Pressure: %.1f hPa\n",
           time_str, data->temperature, data->humidity, data->pressure);

    // Log to file
    fprintf(log_file, "[%s] Temp: %.1f, Humidity: %.1f, Pressure: %.1f\n",
            time_str, data->temperature, data->humidity, data->pressure);
    
    // Ensure data is written to the file immediately
    fflush(log_file);
}

void logger_close(void) {
    if (log_file != NULL) {
        fclose(log_file);
        log_file = NULL;
    }
}
