/**
 * @file processing.h
 * @brief Header for the data processing module.
 * @author Your Name
 * @date 2025-08-09
 */

#ifndef PROCESSING_H
#define PROCESSING_H

#include "buffer.h"

// This is the core of the plugin architecture.
// 'data_processor' is now a type that represents a pointer to a function
// which takes a Buffer pointer and returns nothing.
typedef void (*data_processor)(const Buffer* data_buffer);

// --- Processing Function Prototypes ---

/**
 * @brief Calculates and logs the average temperature from the buffer.
 * @param data_buffer The buffer containing weather data.
 */
void process_average_temp(const Buffer* data_buffer);

/**
 * @brief Finds and logs the min/max humidity from the buffer.
 * @param data_buffer The buffer containing weather data.
 */
void process_min_max_humidity(const Buffer* data_buffer);

/**
 * @brief Determines and logs the barometric pressure trend.
 * @param data_buffer The buffer containing weather data.
 */
void process_pressure_trend(const Buffer* data_buffer);


#endif // PROCESSING_H
