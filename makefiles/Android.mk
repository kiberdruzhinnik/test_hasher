TOP_LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

include $(TOP_LOCAL_PATH)/../src/sodium/Android.mk
include $(TOP_LOCAL_PATH)/../src/hasher/Android.mk
include $(TOP_LOCAL_PATH)/../src/main/Android.mk
include $(TOP_LOCAL_PATH)/../src/greatest/Android.mk