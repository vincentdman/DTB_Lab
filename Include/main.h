/**
 * @file main.h
 * @author Vincent de Man
 * @brief Header file for the main file of the roomba project. 
 * @version 0.1
 * @date 2021-06-22
 * @details 
 * @copyright Copyright (c) 2021
 * 
 */ 

#ifndef MAIN_H 
#define MAIN_H

#include <iostream>
#include "ThreadFunctions.h"
#include "LedMatrix.h"
#include "Pixel.h"
#include "BatteryIndicator.h"
#include <unistd.h>
#include <signal.h>
#include <cstring>
#include "LOG.h"
#include "RoombaSerial.h"
#include "SerialLink.h"
#include <vector>
#include "CommandProcessor.h"
#include <mosquitto.h>
#include <thread>
#include <mutex>
#include "Opcodes.h"
#include "Config.h"
#include "SignalHandler.h"
#include "SenseHAT.h"
#include "string.h"

//extern RoombaSerial &SerialConnection = RoombaSerial::GetInstance();
//extern CommandProcessor mqttHandler(appname, clientname, host, port);


#endif