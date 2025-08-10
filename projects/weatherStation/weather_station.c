/**
 * @file weather_station.c
 * @brief A simple data logger for a smart weather station.
 * @author Your Name
 * @date 2025-08-07
 *
 * This program simulates reading data from weather sensors (temperature, humidity,
 * barometric pressure), validates the data, and logs it to both the console
 * and a file named "weather_log.txt". This covers C fundamentals.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --- Constants and Configuration ---
#define LOG_FILE_NAME "weather_log.txt"
#define NUM_LOG_ENTRIES 10

// --- Simulated Sensor Value Ranges ---
#define TEMP_MIN -10.0f // Celsius
#define TEMP_MAX 50.0f
#define HUMIDITY_MIN 20.0f // Percent
#define HUMIDITY_MAX 90.0f
#define PRESSURE_MIN 980.0f // hPa
#define PRESSURE_MAX 1030.0f

// --- Function Prototypes ---
void read_sensor_data(float* temperature, float* humidity, float* pressure);
int is_data_valid(float temp, float hum, float pres);
void log_data(FILE* file_ptr, float temp, float hum, float pres);
float get_random_float(float min, float max);

/**
 * @brief Main function to run the weather station logger.
 */
int main() {
    // Open the log file in "append" mode. "w" would overwrite it each time.
    FILE* log_file = fopen(LOG_FILE_NAME, "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    printf("--- Smart Weather Station Logger Initialized ---\n");
    printf("Logging %d entries to console and %s\n\n", NUM_LOG_ENTRIES, LOG_FILE_NAME);

    for (int i = 0; i < NUM_LOG_ENTRIES; ++i) {
        float temp, hum, pres;

        read_sensor_data(&temp, &hum, &pres);

        if (is_data_valid(temp, hum, pres)) {
            log_data(log_file, temp, hum, pres);
        } else {
            // In a real system, you'd have more robust error handling.
            fprintf(stderr, "Warning: Invalid sensor data detected. Skipping log entry.\n");
        }
    }

    printf("\n--- Logging Complete ---\n");

    // Always close the file when you're done with it.
    fclose(log_file);

    return 0;
}

/**
 * @brief Simulates reading data from sensors by generating random values.
 * @param temperature Pointer to store the temperature value.
 * @param humidity Pointer to store the humidity value.
 * @param pressure Pointer to store the pressure value.
 *
 * This function demonstrates the use of pointers to "return" multiple values
 * from a function.
 */
void read_sensor_data(float* temperature, float* humidity, float* pressure) {
    *temperature = get_random_float(TEMP_MIN - 5.0f, TEMP_MAX + 5.0f); // Include out-of-range values for validation
    *humidity    = get_random_float(HUMIDITY_MIN - 10.0f, HUMIDITY_MAX + 10.0f);
    *pressure    = get_random_float(PRESSURE_MIN - 20.0f, PRESSURE_MAX + 20.0f);
}

/**
 * @brief Validates the sensor data against predefined limits.
 * @param temp The temperature value to validate.
 * @param hum The humidity value to validate.
 * @param pres The pressure value to validate.
 * @return 1 if data is valid, 0 otherwise.
 */
int is_data_valid(float temp, float hum, float pres) {
    if (temp < TEMP_MIN || temp > TEMP_MAX) return 0;
    if (hum < HUMIDITY_MIN || hum > HUMIDITY_MAX) return 0;
    if (pres < PRESSURE_MIN || pres > PRESSURE_MAX) return 0;
    return 1;
}

/**
 * @brief Logs the data to the console and a file.
 * @param file_ptr A pointer to the log file.
 * @param temp The temperature value.
 * @param hum The humidity value.
 * @param pres The pressure value.
 */
void log_data(FILE* file_ptr, float temp, float hum, float pres) {
    // Get current time for the log entry
    time_t now = time(NULL);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Log to console
    printf("[%s] Temp: %.1f C, Humidity: %.1f %%, Pressure: %.1f hPa\n",
           time_str, temp, hum, pres);

    // Log to file
    fprintf(file_ptr, "[%s] Temp: %.1f, Humidity: %.1f, Pressure: %.1f\n",
            time_str, temp, hum, pres);
    
    // Ensure data is written to the file immediately
    fflush(file_ptr);
}

/**
 * @brief Generates a random float between a min and max value.
 * @param min The minimum value.
 * @param max The maximum value.
 * @return A random float within the range.
 */
float get_random_float(float min, float max) {
    return min + ((float)rand() / RAND_MAX) * (max - min);
}
