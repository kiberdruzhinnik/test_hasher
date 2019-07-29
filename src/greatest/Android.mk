LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := hasher_unittest.c
LOCAL_MODULE := hasher_unittest
LOCAL_CPPFLAGS := -Os -fPIE
LOCAL_STATIC_LIBRARIES := sodium hasher

include $(BUILD_EXECUTABLE)