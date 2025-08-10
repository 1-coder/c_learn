/**
 * @file validation.h
 * @brief Header file for the data validation module.
 * @author Your Name
 * @date 2025-08-08
 */

#ifndef VALIDATION_H
#define VALIDATION_H

#include "sensor.h" // Needs WeatherData definition

// --- Public Constants for Sensor Value Ranges ---
#define TEMP_MIN -10.0f
#define TEMP_MAX 50.0f
#define HUMIDITY_MIN 20.0f
#define HUMIDITY_MAX 90.0f
#define PRESSURE_MIN 980.0f
#define PRESSURE_MAX 1030.0f

/**
 * @brief Validates the sensor data against predefined limits.
 * @param data A pointer to the WeatherData struct to validate.
 * @return 1 if data is valid, 0 otherwise.
 */
int validation_is_data_valid(const WeatherData* data);

#endif // VALIDATION_H
