add_library(
    _libSenseHAT
    Joystick.cpp
    Joystick.h
    JoystickDevice.c
    JoystickDevice.h 
    LedMatrix.cpp
    LedMatrix.h 
    LedMatrixDevice.c 
    LedMatrixDevice.h
    Pixel.cpp
    Pixel.h 
    SenseHAT.cpp
    SenseHAT.h
)
#find_package(RTIMULIB )  
find_library(librtimulib 7.2.1 )
find_library(RTIMULib libRTIMULib.so)
target_link_libraries(_libSenseHAT RTIMULib)
target_include_directories(_libSenseHAT PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")