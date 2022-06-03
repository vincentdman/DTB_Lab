/**
 * @file LOG.h
 * @author Vincent de Man
 * @brief Logging header for roomba project. 
 * @version 0.1
 * @date 2021-05-24
 * @details Header for the LOG class that handles the logging of the roomba. 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef LOG_H
#define LOG_H

#define LOG_LEVEL INFO
#define MAX_MESSAGE_WIDTH 40

#include <iostream>
#include <ctime>
#include <fstream>
#include <thread>
#include <mutex>
#include <iomanip>

#include "LOG_FILE.h"

class LOG
{
public:
    typedef enum
    {
        INFO = 0,
        DEBUG,
        WARNING,
        ERROR,
        VERBOSE,
    } LoggingLevel_t;

    LOG(LoggingLevel_t level);

    ~LOG();

    template <typename T>
    LOG &operator<<(const T &msg)
    {
        if (LOG_LEVEL <= _level)
        {
            if (once == false)
            {
                msg_size = sizeof(msg) / sizeof(std::string);
                once = true;
            }
            GetStream() << msg;
            log_file << msg;
        }
        return *this;
    }

private:
    int msg_size = 0;
    bool once = false; 
    std::string Header;  
    std::time_t time = std::time(nullptr);
    LOG_FILE &log_file = LOG_FILE::getInstance();

    std::ostream &GetStream();

    void SetHeader(void);
    LoggingLevel_t _level = VERBOSE;
};

#endif