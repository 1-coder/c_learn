/**
 * @file buffer.c
 * @brief Implementation of a dynamic circular buffer.
 * @author Your Name
 * @date 2025-08-09
 */

#include "buffer.h"
#include <stdlib.h>
#include <stdio.h>

// This is the actual definition of the Buffer struct.
// Because it's in the .c file, it's hidden from the outside world.
struct Buffer {
    WeatherData* data;
    size_t capacity;
    size_t head;
    size_t tail;
    size_t count;
};

Buffer* buffer_create(size_t capacity) {
    if (capacity == 0) return NULL;

    // Allocate memory for the Buffer management struct itself
    Buffer* buffer = (Buffer*)malloc(sizeof(Buffer));
    if (buffer == NULL) {
        perror("Failed to allocate memory for buffer struct");
        return NULL;
    }

    // Allocate memory for the actual data array
    buffer->data = (WeatherData*)malloc(capacity * sizeof(WeatherData));
    if (buffer->data == NULL) {
        perror("Failed to allocate memory for buffer data");
        free(buffer); // Clean up partially allocated struct
        return NULL;
    }

    buffer->capacity = capacity;
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;

    return buffer;
}

void buffer_destroy(Buffer* buffer) {
    if (buffer == NULL) return;
    
    // IMPORTANT: Free the data array first, then the struct itself.
    free(buffer->data);
    free(buffer);
}

int buffer_add(Buffer* buffer, const WeatherData* data) {
    if (buffer == NULL || data == NULL) return 0;

    // Place the new data at the head
    buffer->data[buffer->head] = *data;
    
    // Move head to the next position, wrapping around if necessary
    buffer->head = (buffer->head + 1) % buffer->capacity;

    if (buffer->count < buffer->capacity) {
        buffer->count++;
    } else {
        // If buffer is full, the tail also moves, overwriting the oldest data
        buffer->tail = (buffer->tail + 1) % buffer->capacity;
    }

    return 1;
}

size_t buffer_get_size(const Buffer* buffer) {
    return (buffer != NULL) ? buffer->count : 0;
}

const WeatherData* buffer_get_element(const Buffer* buffer, size_t index) {
    if (buffer == NULL || index >= buffer->count) {
        return NULL;
    }
    // Calculate the actual position in the circular array
    size_t actual_index = (buffer->tail + index) % buffer->capacity;
    return &buffer->data[actual_index];
}
