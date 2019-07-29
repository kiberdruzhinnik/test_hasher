LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := hasher.c
LOCAL_MODULE := hasher
LOCAL_CPPFLAGS := -Os -fPIE
LOCAL_STATIC_LIBRARIES := sodium

include $(BUILD_STATIC_LIBRARY)