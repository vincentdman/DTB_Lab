/**
 * @file LOG_FILE.h
 * @author Vincent de Man
 * @brief Class to handle the logging file.
 * @version 0.1
 * @date 2021-05-24
 * @details Class to safely handle the logging file with the mutex File_lock. 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef LOG_FILE_H 
#define LOG_FILE_H

#include <iostream>
#include <ctime>
#include <fstream>
#include <thread>
#include <mutex>

class LOG_FILE
{
public:
    LOG_FILE();
    ~LOG_FILE();
    LOG_FILE(const LOG_FILE &obj) = delete;
    LOG_FILE &operator=(const LOG_FILE &obj) = delete;
    [[nodiscard]] static LOG_FILE &getInstance();

    std::ofstream LOGGER_FILE;
    template<typename T>
    LOG_FILE &operator<<(const T &msg)
    { 
         LOGGER_FILE << msg;
         return *this;
    }

    std::mutex File_Lock;

private:
    
    std::time_t time = std::time(nullptr);
    
    
};

#endif