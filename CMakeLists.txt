cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 17)
set(NDK_PATH D:/android-ndk-r26b)##记得修改一下ndk路径

set(CMAKE_SYSTEM_NAME ANDROID)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_SYSTEM_VERSION 21)
set(ANDROID_PLATFORM 21)
set(ANDROID_SDK_TOOLS_VERSION 20)
set(ANDROID_ABI arm64-v8a)
set(ANDROID_NDK ${NDK_PATH})
set(CMAKE_TOOLCHAIN_FILE ${NDK_PATH}/build/cmake/android.toolchain.cmake)
set(ANDROID_SDK_ROOT ${NDK_PATH})

project(VolToShoulder)

include_directories(
        ./include
        ./include/tools
        ./include/VolToShoulder
)

file(GLOB_RECURSE src "./src/*.cpp")

add_executable(VolToShoulder ${src})