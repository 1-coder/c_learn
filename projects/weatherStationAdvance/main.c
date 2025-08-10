/**
 * @file main.c
 * @brief Main application file for the Advanced Smart Weather Station.
 * @author Your Name
 * @date 2025-08-09
 *
 * This file now manages a dynamic data buffer and a processing pipeline
 * implemented with function pointers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sensor.h"
#include "validation.h"
#include "logger.h"
#include "buffer.h"
#include "processing.h"

#define NUM_SAMPLES_TO_COLLECT 200
#define BUFFER_CAPACITY 25

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // --- Setup ---
    if (!logger_init()) {
        fprintf(stderr, "Failed to initialize logger.\n");
        return 1;
    }

    // Create a dynamic buffer for our weather data
    Buffer* data_buffer = buffer_create(BUFFER_CAPACITY);
    if (data_buffer == NULL) {
        fprintf(stderr, "Failed to create data buffer.\n");
        logger_close();
        return 1;
    }

    // Define our data processing pipeline using function pointers
    data_processor pipeline[] = {
        process_average_temp,
        process_min_max_humidity,
        process_pressure_trend
    };
    int num_pipeline_steps = sizeof(pipeline) / sizeof(pipeline[0]);

    printf("--- Advanced Weather Station Initialized ---\n");
    printf("Collecting %d samples into a buffer of size %d...\n\n", NUM_SAMPLES_TO_COLLECT, BUFFER_CAPACITY);

    // --- Data Collection Phase ---
    for (int i = 0; i < NUM_SAMPLES_TO_COLLECT; ++i) {
        WeatherData data;
        sensor_read_data(&data);

        if (validation_is_data_valid(&data)) {
            if (!buffer_add(data_buffer, &data)) {
                fprintf(stderr, "Warning: Buffer is full. Overwriting oldest data.\n");
            }
            logger_log_raw_data(&data); // Log the raw data point
        } else {
            fprintf(stderr, "Warning: Invalid sensor data detected. Skipping.\n");
        }
    }

    printf("\n--- Data Collection Complete. Starting Processing Pipeline ---\n");

    // --- Data Processing Phase ---
    for (int i = 0; i < num_pipeline_steps; ++i) {
        pipeline[i](data_buffer);
    }

    printf("\n--- Processing Complete ---\n");

    // --- Cleanup ---
    buffer_destroy(data_buffer);
    logger_close();

    return 0;
}
