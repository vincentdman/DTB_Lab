// /**
//  * @file LOG.cpp
//  * @author Vincent de Man
//  * @brief Implementation of the LOG class. 
//  * @version 0.1
//  * @date 2021-05-24
//  * @class LOG class to handle the logging for the user. 
//  * @copyright Copyright (c) 2021
//  * @details LOG class to make it easy for the user to handle logging.
//  */

// #include "LOG.h"

// /**
//  * @brief Construct a new LOG object.
//  * 
//  * @param level The Log level the message will be displayed as. 
//  * 
//  * @details Constructor takes the file mutex lock and prints the correct header for the logging level to the output stream. 
//  */
// LOG::LOG(LoggingLevel_t level) : _level(level)
// {
//     log_file.File_Lock.lock();

//     SetHeader();
//     if (LOG_LEVEL <= _level)
//     {
//         log_file << std::left;
//         log_file << Header;
//         GetStream() << std::left << Header;
//     }
// }

// /**
//  * @brief Destroy the LOG object
//  * 
//  * @details Destructor sets the file mutex lock free and writes the current time at the end of the message.
//  */
// LOG::~LOG()
// {

//     if (LOG_LEVEL <= _level)
//     {
//         GetStream() << "\t";
//         GetStream() << std::setw(MAX_MESSAGE_WIDTH - msg_size) << std::right << " |" << std::asctime(std::localtime(&time));

//         log_file << "\t";
//         log_file << std::setw(MAX_MESSAGE_WIDTH - msg_size) << std::right;
//         log_file << " |";
//         log_file << std::asctime(std::localtime(&time));
//     }
//     log_file.File_Lock.unlock();
// }

// /**
//  * @brief Private function to get the output stream. 
//  *  
//  * @return std::ostream& The output stream that is going to be used.
//  * 
//  * @details Function to get the output stream for the logging message. normal is std::cout error is std::cerr.  
//  */
// std::ostream &LOG::GetStream()
// {
//     if (_level == ERROR)
//     {
//         return std::cerr;
//     }
//     return std::cout;
// }

// /**
//  * @brief Function to set the correct header according to the log level.
//  * 
//  * @details Funciton to set the correct header according to the log level set in the constructor. 
//  */
// void LOG::SetHeader()
// {
//     switch (_level)
//     {
//     case INFO:
//         Header = "[INFO]    ~$ ";
//         break;
//     case DEBUG:
//         Header = "[DEBUG]   ~$ ";
//         break;
//     case WARNING:
//         Header = "[WARNING] ~$ ";
//         break;
//     case ERROR:
//         Header = "[ERROR]   ~$ ";
//         break;
//     case VERBOSE:
//         Header = "[VERBOSE] ~$ ";
//         break;
//     }
// }