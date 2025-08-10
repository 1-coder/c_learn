/**
 * @file processing.c
 * @brief Implementation of various data processing functions.
 * @author Your Name
 * @date 2025-08-09
 */

#include "processing.h"
#include <stdio.h>
#include "logger.h" // To log the results

void process_average_temp(const Buffer* data_buffer) {
    if (data_buffer == NULL || buffer_get_size(data_buffer) == 0) {
        log_processed_data("Average Temp: N/A (no data)");
        return;
    }

    float sum = 0.0f;
    size_t size = buffer_get_size(data_buffer);

    for (size_t i = 0; i < size; ++i) {
        const WeatherData* data = buffer_get_element(data_buffer, i);
        sum += data->temperature;
    }

    char result_str[100];
    snprintf(result_str, sizeof(result_str), "Average Temp: %.2f C", sum / size);
    log_processed_data(result_str);
}

void process_min_max_humidity(const Buffer* data_buffer) {
    size_t size = buffer_get_size(data_buffer);
    if (data_buffer == NULL || size == 0) {
        log_processed_data("Min/Max Humidity: N/A (no data)");
        return;
    }

    const WeatherData* first_element = buffer_get_element(data_buffer, 0);
    float min_hum = first_element->humidity;
    float max_hum = first_element->humidity;

    for (size_t i = 1; i < size; ++i) {
        const WeatherData* data = buffer_get_element(data_buffer, i);
        if (data->humidity < min_hum) min_hum = data->humidity;
        if (data->humidity > max_hum) max_hum = data->humidity;
    }

    char result_str[100];
    snprintf(result_str, sizeof(result_str), "Min/Max Humidity: %.1f%% / %.1f%%", min_hum, max_hum);
    log_processed_data(result_str);
}

void process_pressure_trend(const Buffer* data_buffer) {
    size_t size = buffer_get_size(data_buffer);
    if (data_buffer == NULL || size < 2) {
        log_processed_data("Pressure Trend: N/A (insufficient data)");
        return;
    }

    const WeatherData* first_data = buffer_get_element(data_buffer, 0);
    const WeatherData* last_data = buffer_get_element(data_buffer, size - 1);

    float trend = last_data->pressure - first_data->pressure;
    char result_str[100];

    if (trend > 0.5f) {
        snprintf(result_str, sizeof(result_str), "Pressure Trend: Rising (%.2f hPa)", trend);
    } else if (trend < -0.5f) {
        snprintf(result_str, sizeof(result_str), "Pressure Trend: Falling (%.2f hPa)", trend);
    } else {
        snprintf(result_str, sizeof(result_str), "Pressure Trend: Stable (%.2f hPa)", trend);
    }
    log_processed_data(result_str);
}
