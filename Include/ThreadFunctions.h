/**
 * @file ThreadFunctions.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef THREAD_FUNCTIONS_H
#define THREAD_FUNCTIONS_H

#include "Config.h"
#include "main.h"
#include <mutex>
#include "RoombaSerial.h"
#include "CommandProcessor.h"

void StartMainSystemThreads(void);

void got_signal(int);

void StartRoomba(); 
void BatteryStatus();
void Mode();
void Buttons();
void UserCommands();




#endif // THREAD_FUNCTIONS_H