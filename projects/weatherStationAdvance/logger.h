/**
 * @file logger.h
 * @brief Header file for the logger module.
 * @author Your Name
 * @date 2025-08-09
 */

#ifndef LOGGER_H
#define LOGGER_H

#include "sensor.h" // For WeatherData

/**
 * @brief Initializes the logger.
 * @return 1 on success, 0 on failure.
 */
int logger_init(void);

/**
 * @brief Logs a raw weather data reading.
 * @param data A pointer to the WeatherData to be logged.
 */
void logger_log_raw_data(const WeatherData* data);

/**
 * @brief Logs a processed data string (e.g., an analysis result).
 * @param message The string message to log.
 */
void log_processed_data(const char* message);

/**
 * @brief Closes the logger and releases resources.
 */
void logger_close(void);

#endif // LOGGER_H
