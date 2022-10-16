# Find Pangolin (https://github.com/stevenlovegrove/Pangolin)
find_package(Pangolin 0.8 REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})

add_executable(hello_camera_view main.cpp)
target_link_libraries(hello_camera_view ${Pangolin_LIBRARIES})
