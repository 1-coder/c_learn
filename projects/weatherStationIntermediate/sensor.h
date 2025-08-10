/**
 * @file sensor.h
 * @brief Header file for the sensor module.
 * @author Your Name
 * @date 2025-08-08
 *
 * This header defines the public interface for the sensor module.
 * It includes the data structure for weather data and the function
 * prototype for reading from the sensors.
 */

#ifndef SENSOR_H
#define SENSOR_H

// A struct to hold all related weather data together.
// This is much cleaner than passing multiple pointers around.
typedef struct {
    float temperature;
    float humidity;
    float pressure;
} WeatherData;

/**
 * @brief Reads data from the weather sensors.
 * @param data A pointer to a WeatherData struct to be filled with sensor readings.
 */
void sensor_read_data(WeatherData* data);

#endif // SENSOR_H
