#include <arm_neon.h>
#include <malloc.h>

void* aligned_malloc(unsigned int size, unsigned int align) {
  void* ptr;
  ptr = memalign(16, size);
  return ptr;
}


void vec_add(float* v1, float* v2, float* v3, unsigned int size) {

  float32x4_t r1, r2, r3;
  unsigned int i = 0;

  for(i = 0 ; i < size ; i+=4) {

    r1 = vld1q_f32(&v1[i]);
    r2 = vld1q_f32(&v2[i]);

    r3 = vaddq_f32(r1, r2);

    vst1q_f32(&v3[i], r3);
  }
  for( ; i < size ; ++i) {
    v3[i] = v1[i] + v2[i];
  }


}
