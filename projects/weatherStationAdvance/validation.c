/**
 * @file validation.c
 * @brief Implementation of the data validation module.
 * @author Your Name
 * @date 2025-08-08
 */

#include "validation.h"
#include <stddef.h> // For NULL

int validation_is_data_valid(const WeatherData* data) {
    if (data == NULL) {
        return 0;
    }

    if (data->temperature < TEMP_MIN || data->temperature > TEMP_MAX) return 0;
    if (data->humidity < HUMIDITY_MIN || data->humidity > HUMIDITY_MAX) return 0;
    if (data->pressure < PRESSURE_MIN || data->pressure > PRESSURE_MAX) return 0;
    
    return 1;
}
