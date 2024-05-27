#include <assert.h>
#include <stdint.h>

#include "Memory.h"

const size_t memory_size = 10 * 1024 * 1024;
const size_t scratch_pad_size = 1 * 1024 * 1024;
uint8_t* memory;
size_t index;

void memory_init() {
	memory = malloc(sizeof(uint8_t) * memory_size);
	index = scratch_pad_size;
}

void* memory_scratch_pad(size_t size) {
	assert(size < scratch_pad_size);
	return memory;
}

void* memory_allocate(size_t size) {
	assert(index + size < memory_size);
	void* data = &memory[index];
	index += size;
	return data;
}
