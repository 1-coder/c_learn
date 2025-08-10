/**
 * @file logger.h
 * @brief Header file for the logger module.
 * @author Your Name
 * @date 2025-08-08
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
 * @brief Logs a set of weather data.
 * @param data A pointer to the WeatherData to be logged.
 */
void logger_log_data(const WeatherData* data);

/**
 * @brief Closes the logger and releases resources.
 */
void logger_close(void);

#endif // LOGGER_H
