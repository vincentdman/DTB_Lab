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
 
target_link_libraries(roomba includes)
target_link_libraries(roomba _libMQTT)
target_link_libraries(roomba _libUtils)
target_link_libraries(roomba _libSenseHAT)