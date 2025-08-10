/**
 * @file sensor.c
 * @brief Implementation of the sensor module.
 * @author Your Name
 * @date 2025-08-08
 *
 * This file simulates reading data from weather sensors.
 */

#include "sensor.h"
#include <stdlib.h> // For rand()
#include "validation.h" // For sensor range constants

// This function is "static", meaning it's only visible within this file (sensor.c).
// It's a helper function that the outside world doesn't need to know about.
// This is a key principle of encapsulation.
static float get_random_float(float min, float max) {
    return min + ((float)rand() / RAND_MAX) * (max - min);
}

void sensor_read_data(WeatherData* data) {
    if (data == NULL) {
        return; // Always check for NULL pointers
    }

    // Simulate potential for out-of-range values to test validation
    data->temperature = get_random_float(TEMP_MIN - 5.0f, TEMP_MAX + 5.0f);
    data->humidity    = get_random_float(HUMIDITY_MIN - 10.0f, HUMIDITY_MAX + 10.0f);
    data->pressure    = get_random_float(PRESSURE_MIN - 20.0f, PRESSURE_MAX + 20.0f);
}
