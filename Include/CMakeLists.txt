add_library(
    includes
    BatteryIndicator.h 
    LOG_FILE.h 
    LOG.h 
    Opcodes.h 
    RoombaSerial.h
    main.h
    ThreadFunctions.h
    Config.h 
    SignalHandler.h
)
set_target_properties(includes PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(includes PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
