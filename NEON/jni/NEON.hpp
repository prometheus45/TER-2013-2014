#ifndef NEON_HPP
#define NEON_HPP

void vec_add(float* v1, float* v2, float* v3, unsigned int size);

float* aligned_malloc(unsigned int size, unsigned int align);

#endif
