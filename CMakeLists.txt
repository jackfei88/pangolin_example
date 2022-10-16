cmake_minimum_required(VERSION 3.10)

project(pangolin_examples)

add_subdirectory(BasicOpenGL)

add_subdirectory(HelloPangolin)
add_subdirectory(HelloPangolinThreads)
add_subdirectory(SimpleDisplay)
add_subdirectory(SimpleMultiDisplay)
add_subdirectory(SimpleDisplayImage)
add_subdirectory(SimplePlot)
add_subdirectory(SimpleVideo)
add_subdirectory(SharedMemoryCamera)
add_subdirectory(SimpleRecord)

if(NOT EMSCRIPTEN)
    add_subdirectory(HelloPangolinOffscreen)
    add_subdirectory(SimpleScene)
endif()

add_subdirectory(VBODisplay)


add_subdirectory(HelloCameraView)


