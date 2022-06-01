add_library(
    _libUtils
    ChronoUtils.h
    ParExe.h
    ParLoop.h
    ParQueue.h 
    ParWait.h 
    INIreader/INIreader.cpp
    INIreader/INIreader.h
    INIreader/INIreader.cpp
    INIreader/INIreader.h
    JSON/json.hpp
    SerialLink/SerialLink.cpp
    SerialLink/SerialLink.h
)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.67.0 COMPONENTS filesystem regex) 
FIND_PACKAGE(Threads REQUIRED)

if(Boost_FOUND)
target_link_libraries(_libUtils PUBLIC ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
endif() 

target_include_directories(_libUtils PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/INIreader" "${CMAKE_CURRENT_SOURCE_DIR}/JSON" "${CMAKE_CURRENT_SOURCE_DIR}/SerialLink")