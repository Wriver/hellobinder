LOCAL_PATH:= $(call my-dir)

# Build hello client
include $(CLEAR_VARS)

LOCAL_SRC_FILES:=hello_client.cpp
LOCAL_SHARED_LIBRARIES := \
	liblog  \
	libbinder \
	libutils

LOCAL_MODULE:=helloclient
include $(BUILD_EXECUTABLE)

# Build hello service
include $(CLEAR_VARS)

LOCAL_SRC_FILES:=hello_service.cpp
LOCAL_SHARED_LIBRARIES := \
	liblog  \
	libbinder \
	libutils

LOCAL_MODULE:=helloservice
include $(BUILD_EXECUTABLE)
