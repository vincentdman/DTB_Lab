// /**
//  * @file LOG_FILE.cpp
//  * @author Vincent de Man
//  * @brief Implementation of the logging file class.
//  * @version 0.1
//  * @date 2021-05-24
//  * @class Logging file class to handle the logging file correctely. 
//  * @copyright Copyright (c) 2021
//  * @details Implementation of the logging file class. This class safely handles the logging file for the user. 
//  */

// #include "LOG_FILE.h"

// /**
//  * @brief Construct a new log file object.
//  * 
//  * @details Constructor opens the file RoombaLogging.txt for writing and appends the header to it. 
//  */
// LOG_FILE::LOG_FILE()
// {
//     LOGGER_FILE.open("RoombaLogging.txt", std::ios::out | std::ios::app);
//     LOGGER_FILE << std::endl;
//     LOGGER_FILE << "//***************************************************************************\\" << std::endl;
//     LOGGER_FILE << "STARTED LOGGING ON: " << std::asctime(std::localtime(&time));
//     LOGGER_FILE << "//***************************************************************************\\" << std::endl;
// }

// /**
//  * @brief Destroy the log file object.
//  * 
//  * @details Destructor closes the file correctely and writes the end header to it. 
//  */
// LOG_FILE::~LOG_FILE()
// {
//     std::time_t timeD = std::time(nullptr);
//     LOGGER_FILE << std::endl;
//     LOGGER_FILE << "//***************************************************************************\\" << std::endl;
//     LOGGER_FILE << "STOPPED LOGGING ON: " << std::asctime(std::localtime(&timeD));
//     LOGGER_FILE << "//***************************************************************************\\" << std::endl;
//     LOGGER_FILE.close();
// }

// /**
//  * @brief Singleton function to get the instance.
//  * 
//  * @return LOG_FILE& Reference to the instance.
//  * 
//  * @details Singleton function to get the instance of the logging file. 
//  */
// LOG_FILE &LOG_FILE::getInstance()
//     {
//         static LOG_FILE instance;
//         return instance;
//     }
    
