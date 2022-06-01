/**
 * @file ThreadFunctions.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include "ThreadFunctions.h"
//std::mutex threadLock;
bool running = true; 
//RoombaSerial &SerialConnection = RoombaSerial::GetInstance();
//CommandProcessor mqttHandler(appname, clientname, host, port);

// /**
//  * @brief Signal handle function. 
//  * 
//  * @details Signal handle function. Gets called when the programe receives SIGINT, SIGHUB, SIGQUIT or SIGKILL. 
//  */
 void got_signal(int)
 {
     //LOG(LOG::DEBUG) << "Caught a quit signal, program will stop when threads are done";
     //running = false;
     std::cout<<"shutdown"<<std::endl;
     exit(1);
 }


// void StartRoomba(void)
// {
//     SerialConnection.RoombaWrite({START}, 1);
// }

// void StartMainSystemThreads(void)
// {
//     LOG(LOG::INFO) << "The Main system threads will be started.... ";
//     std::thread buttonThread(Buttons);
//     std::thread batteryThread(BatteryStatus);
//     std::thread commandThread(UserCommands);
//     std::thread modeThread(Mode);

//     buttonThread.join();
//     batteryThread.join();
//     commandThread.join();
//     modeThread.join();    
//     LOG(LOG::INFO) << "System Shutdown!";
// }



// /**
//  * @brief Thread function to handle the MQTT user commands.
//  * 
//  * @details checks if the user send date via MQTT and handles the data accordingly.
//  */
// void UserCommands()
// {
//     while (running)
//     {
//         threadLock.lock();
//         if (mqttHandler.get_flag())
//         {
//             SerialConnection.ProcessCommand(mqttHandler.get_received_command());
//             LOG(LOG::INFO)<<"System received MQTT command from user and will execute it";
//             usleep(10);
//         }
//         threadLock.unlock();
//         sleep(UserCommandsSleepTime);
//     }
// }

// /**
//  * @brief Thread function to update the battery status on the sense hat. 
//  * 
//  * @details gets the batterystatus from the roomba and updates the sensehat and sends it to the webpage.
//  */
// void BatteryStatus()
// {
//     BatteryIndicator &battery = BatteryIndicator::getInstance();

//     while (running)
//     {
//         threadLock.lock();
//         auto readData = SerialConnection.RoombaWriteRead({QUERY, 1, BATTERY_CHARGE}, 3, 2);

//         int batteryCharge = (readData[1] | (readData[0] << 8));
//         int percentage = ((float)batteryCharge / MaxBatteryCharge) * 100;

//         std::string percentageString = std::to_string(percentage);
//         percentageString += '%';
//         mqttHandler.publishInfo(percentageString.c_str(), "roombatvms/batterystatus");

//         threadLock.unlock();

//         LOG(LOG::INFO) << "Battery percentage is: " << percentage << "%";
//         battery.SetBatteryIndicator(percentage);
//         sleep(BatteryStatusSleepTime);
//     }
// }

// /**
//  * @brief thread function to get the mode and transmit it to the webpage.
//  * 
//  * @details thread function to get the mode and transmit it to the webpage.
//  */
// void Mode()
// {
//     while (running)
//     {
//         threadLock.lock();

//         auto readData = SerialConnection.RoombaWriteRead({QUERY, 1, OI_MODE}, 3, 1);

//         // LOG(LOG::DEBUG)<<(int)readData[0];
//         std::string modeInfo = SerialConnection.CheckMode((int)readData[0]);
        
//         mqttHandler.publishInfo(modeInfo, "roombatvms/mode");
//         threadLock.unlock();
//         sleep(ModeSleepTime);
//     }
// }

/**
 * @brief thread function to read out the buttons and transmit it to the webpage.
 * 
 * @details thread function to read out the buttons and transmit it to the webpage.
 */
// void Buttons()
// {
//     while (running)
//     {
//         threadLock.lock();

//         auto readData = SerialConnection.RoombaWriteRead({QUERY, 1, P_BUTTONS}, 3, 1);
         
//         if (readData[0] & CleanButtonBit)
//         {
//             mqttHandler.publishInfo("Roomba clean button pressed", "roombatvms/buttons");
//             LOG(LOG::INFO) << "Clean button pressed!";
//         }
//         else if (readData[0] & SpotButtonBit)
//         {
//             mqttHandler.publishInfo("Roomba spot button pressed", "roombatvms/buttons");
//             LOG(LOG::INFO) << "Spot button pressed!";
//         }
//         else if (readData[0] & DockButtonBit)
//         {
//             mqttHandler.publishInfo("Roomba dock button pressed", "roombatvms/buttons");
//             LOG(LOG::INFO) << "Dock button pressed!";
//         }
//         threadLock.unlock();
//         usleep(ButtonsSleepTime);
//     }
// }