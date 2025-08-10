/**
 * @file buffer.h
 * @brief Header for a dynamic circular buffer for WeatherData.
 * @author Your Name
 * @date 2025-08-09
 */

#ifndef BUFFER_H
#define BUFFER_H

#include <stddef.h>
#include "sensor.h"

// An "opaque" struct. The user of the buffer doesn't know its internal fields.
// This enforces encapsulation. All interaction must happen via buffer_* functions.
typedef struct Buffer Buffer;

/**
 * @brief Creates and allocates memory for a new buffer.
 * @param capacity The maximum number of elements the buffer can hold.
 * @return A pointer to the newly created Buffer, or NULL on failure.
 */
Buffer* buffer_create(size_t capacity);

/**
 * @brief Frees the memory associated with the buffer.
 * @param buffer The buffer to destroy.
 */
void buffer_destroy(Buffer* buffer);

/**
 * @brief Adds a WeatherData element to the buffer.
 * @param buffer The buffer to add to.
 * @param data A pointer to the data to add.
 * @return 1 on success, 0 if buffer is full (in a simple implementation).
 */
int buffer_add(Buffer* buffer, const WeatherData* data);

/**
 * @brief Gets the number of elements currently in the buffer.
 * @param buffer The buffer.
 * @return The number of elements.
 */
size_t buffer_get_size(const Buffer* buffer);

/**
 * @brief Gets an element from the buffer at a specific index.
 * @param buffer The buffer.
 * @param index The index of the element to retrieve.
 * @return A pointer to the element, or NULL if index is out of bounds.
 */
const WeatherData* buffer_get_element(const Buffer* buffer, size_t index);

#endif // BUFFER_H
