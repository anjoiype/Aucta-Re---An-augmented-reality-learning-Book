
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := QCAR-prebuilt
LOCAL_SRC_FILES = ../../../build/lib/$(TARGET_ARCH_ABI)/libQCAR.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../../../build/include
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)


LOCAL_MODULE := FrameMarkers


TARGET_PLATFORM := android-5
	
OPENGLES_LIB  := -lGLESv2
OPENGLES_DEF  := -DUSE_OPENGL_ES_2_0


LOCAL_CFLAGS := -Wno-write-strings $(OPENGLES_DEF)


LOCAL_LDLIBS := \
    -llog $(OPENGLES_LIB)
     
LOCAL_SHARED_LIBRARIES := QCAR-prebuilt

	
LOCAL_SRC_FILES := FrameMarkers.cpp SampleUtils.cpp Texture.cpp

LOCAL_ARM_MODE := arm


include $(BUILD_SHARED_LIBRARY)
