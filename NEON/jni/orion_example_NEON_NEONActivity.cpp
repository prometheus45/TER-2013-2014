#include <orion_example_NEON_NEONActivity.hpp>

#include <NEON.hpp>

JNIEXPORT jfloatArray JNICALL Java_orion_example_NEON_NEONActivity_vecAdd(JNIEnv* env, jobject obj, jfloatArray jv1, jfloatArray jv2) {

  jfloat* v0;
  jfloat* v1 = env->GetFloatArrayElements(jv1, 0);
  jfloat* v2 = env->GetFloatArrayElements(jv2, 0);

  jint size = env->GetArrayLength(jv1);

  jfloatArray array = env->NewFloatArray(size);

  v0 = (float*)aligned_malloc(size * 4, 16);

  vec_add(v1, v2, v0, size);

  env->SetFloatArrayRegion(array, 0, size, v0);

  return array;

}

JNIEXPORT jfloatArray JNICALL Java_orion_example_NEON_NEONActivity_alignedMalloc
(JNIEnv* env, jobject obj, jint size, jint align) {

  float* mem = (float*)aligned_malloc(size * 4, align);

  jfloatArray array = env->NewFloatArray(size);

  env->SetFloatArrayRegion(array, 0, size, mem);

  return array;

}
