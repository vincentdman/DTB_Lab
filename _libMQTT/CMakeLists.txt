add_library(
    _libMQTT
    CommandProcessor.cpp
    CommandProcessor.h 
    MQTTconfig.cpp
    MQTTconfig.h
    MQTTmessage.cpp
    MQTTmessage.h
    Tokenizer.cpp
    Tokenizer.h
    Topic.cpp
    Topic.h
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(Mosquitto REQUIRED IMPORTED_TARGET libmosquitto)
pkg_check_modules(mosquittopp REQUIRED IMPORTED_TARGET libmosquittopp)

target_link_libraries(_libMQTT PUBLIC PkgConfig::Mosquitto PkgConfig::mosquittopp)

target_include_directories(_libMQTT PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")