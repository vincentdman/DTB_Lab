add_executable(
    roomba 
    main.cpp 
    LOG_FILE.cpp 
    LOG.cpp 
    BatteryIndicator.cpp 
    RoombaSerial.cpp
    ThreadFunctions.cpp
    SignalHandler.cpp
)  
#find_package(libsqlite3-dev 3.34.1)
find_package (SQLite3 REQUIRED)
include_directories(${SQLITE3_INCLUDE_DIRS})
target_link_libraries (roomba ${SQLITE3_LIBRARIES})

target_link_libraries(roomba sqlite3)
target_link_libraries(roomba pthread)
target_link_libraries(roomba includes)
target_link_libraries(roomba _libMQTT)
target_link_libraries(roomba _libUtils)
target_link_libraries(roomba _libSenseHAT)