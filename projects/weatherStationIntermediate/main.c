/**
 * @file main.c
 * @brief Main application file for the Smart Weather Station.
 * @author Your Name
 * @date 2025-08-08
 *
 * This file contains the main application logic. It initializes the modules,
 * reads and validates sensor data in a loop, and logs it.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sensor.h"
#include "validation.h"
#include "logger.h"

#define NUM_LOG_ENTRIES 10

int main() {
    // Seed the random number generator once at the start
    srand(time(NULL));

    // Initialize the logger. This opens the log file.
    if (!logger_init()) {
        fprintf(stderr, "Failed to initialize logger.\n");
        return 1;
    }

    printf("--- Smart Weather Station Logger Initialized (Modular) ---\n");

    for (int i = 0; i < NUM_LOG_ENTRIES; ++i) {
        WeatherData data;

        // Read data from the sensor module
        sensor_read_data(&data);

        // Validate the data using the validation module
        if (validation_is_data_valid(&data)) {
            // Log the data using the logger module
            logger_log_data(&data);
        } else {
            fprintf(stderr, "Warning: Invalid sensor data detected. Skipping log entry.\n");
        }
    }

    printf("\n--- Logging Complete ---\n");

    // Clean up resources used by the logger
    logger_close();

    return 0;
}
