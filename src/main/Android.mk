LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := main.c utils.c
LOCAL_MODULE := main
LOCAL_CPPFLAGS := -Os -fPIE
LOCAL_STATIC_LIBRARIES := sodium hasher

include $(BUILD_EXECUTABLE)