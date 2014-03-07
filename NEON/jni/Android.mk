LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := NEON
#LOCAL_CFLAGS := -mfpu=neon
LOCAL_SRC_FILES := orion_example_NEON_NEONActivity.cpp NEON.cpp.neon

include $(BUILD_SHARED_LIBRARY)
