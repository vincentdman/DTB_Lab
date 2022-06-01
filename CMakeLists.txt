cmake_minimum_required(VERSION 3.0.0)
project(roomba VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(Include)
add_subdirectory(Source)
add_subdirectory(_libSenseHAT)
add_subdirectory(_libUtils)
add_subdirectory(_libMQTT)