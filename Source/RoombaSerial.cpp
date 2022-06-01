// /**
//  * @file RoombaSerial.cpp
//  * @author Thimo Meeusen
//  * @brief Implementation of the RoombaSerial class.
//  * @version 0.1
//  * @date 2021-06-17
//  * @class RoombaSerial class to handle communication with the Serial class.
//  * @copyright Copyright (c) 2021
//  * @details Implementation of the RoombaSerial class. This class handles the comunication between the SerialLink class and the rest of the code 
//  */

// #include "RoombaSerial.h"

// /**
//  * @brief Singleton function to get the instance.
//  * 
//  * @return RoombaSerial& Reference to the instance.
//  * 
//  * @details Singleton function to get the instance of the RoombaSerial class. 
//  */

// RoombaSerial &RoombaSerial::GetInstance()
// {
//     static RoombaSerial instance;
//     return instance;
// }

// /**
//  * @brief constructor for the RoombaSerial class.
//  * 
//  * @details constructor for the RoombaSerial class. constructs and initialises the RoombaSerial class. 
//  */

// RoombaSerial::RoombaSerial(std::string COM, unsigned int BaudRate)
//     : usb_tll(COM, BaudRate)
// {
//     LOG(LOG::DEBUG) << "RoombaSerial started on COM: " << COM << "at :" << BaudRate;
// }

// /**
//  * @brief Function that writes incoming commands to the roomba via usb ttl 
//  * 
//  * @param data The command that must be sent to the roomba
//  * @param amount The amount of bytes that must be sent, the command plus arguments
//  * 
//  * @details Incoming commands plus arguments are cast to a vector, the vector is then sent over usb
//  */

// void RoombaSerial::RoombaWrite(std::array<uint8_t, 255> data, int amount)
// {
//     for (int i = 0; i < amount; i++)
//     {   
//         std::vector<uint8_t> ConvertedData{static_cast<unsigned char>(data[i])};
//         usb_tll.write(ConvertedData);
//     }
// }

// /**
//  * @brief Function to retrieve information about the roomba
//  * 
//  * @param data The command that must be sent to the roomba
//  * @param amount The amount of bytes that must be sent, the command plus arguments
//  * @param ReadSize The amount of bytes that the roomba returns
//  * 
//  * @return std::vector<uint8_t> a vector with all the incoming bytes from the roomba
//  * 
//  * @details This function calls RoombaWrite to sent a command with arguments, the roomba returns sensor information which are retrieved and returned
//  */

// std::vector<uint8_t> RoombaSerial::RoombaWriteRead(std::array<uint8_t,255> data, size_t amount, size_t ReadSize)
// {
//     RoombaWrite(data,amount);
//     return {0,0,0,0};//usb_tll.read(ReadSize);
// }

// /**
//  * @brief Function that processes mqtt commands and writes them to the roomba
//  * 
//  * @param command The received mqtt string  
//  * 
//  * @details This function is called when an mqtt message is received. The command and its arguments are retreived and the correct command is sent to the roomba over serial.
//  */

// void RoombaSerial::ProcessCommand(std::string command)
// {
//     index = 0;
//     arg_count = 0;

//     received_command.clear();

//     while(command[index] != ' ')
//     {
//         received_command += command[index];
//         index++;
//     }

//     index++;

//     auto search = commandsMap.find(received_command);
   
//     if(search != commandsMap.end())
//     {
//         LOG(LOG::INFO)<< "Command received " << static_cast<int>(search->second);
//         command_data[0] = search->second;
//     }
//     else
//     {
//         LOG(LOG::ERROR)<< "Command not found";
//         return;
//     }


//     while(command[index] != '\0') 
//     {
//         if(command[index] == ' ')
//         {
//             arg_count++;
//             index++;
//         }
//         args[arg_count] += command[index];
//         index++;
//     }

//     for(int m=0; m<arg_count; m++)
//     {
//         command_data[(m+1)] = static_cast<uint8_t>(*(args[m].c_str()));
//     }
    
//     RoombaSerial::RoombaWrite(command_data, (arg_count+1));
// }

// /**
//  * @brief Returns the mode from the received roomba data
//  * 
//  * @param mode data from the roomba that represents the current mode
//  * 
//  * @return std::string string to be sent via mqtt
//  * 
//  * @details Roomba returns a integer, this function returns the correct corresponding string
//  */
// std::string RoombaSerial::CheckMode(int mode)
// {
//     switch (mode)
//     {
//     case 0:
//         return "OFF";
//     case 1:
//         return "PASSIVE";
//     case 2:
//         return "SAFE";
//     case 3:
//         return "FULL";
//     default:
//         return "ERROR";
//     }
// }
