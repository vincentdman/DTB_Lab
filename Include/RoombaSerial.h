/**
 * @file Opcodes.h
 * @author Vincent & Marijn
 * @brief RoombaSerial header file for roomba project
 * @version 0.1
 * @date 2021-06-02
 * @details RoombaSerial header file for roomba project. handles serial for the roomba.
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef RoombaSerial_H
#define RoombaSerial_H

#include "SerialLink.h"
#include "LOG.h"
#include <string>
#include <vector>
#include <array>
#include "Opcodes.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

class RoombaSerial
{
    public:    
    RoombaSerial(std::string COM = "/dev/ttyUSB0", unsigned int BaudRate= 115200);
    [[nodiscard]] static RoombaSerial& GetInstance();
    void RoombaWrite(std::array<uint8_t, 255> data, int amount);
    void ProcessCommand(std::string command);

    [[nodiscard]] std::vector<uint8_t> RoombaWriteRead(std::array<uint8_t,255> data, size_t amount, size_t ReadSize);
    std::string CheckMode(int mode);

    private:
    ~RoombaSerial()=default;
    RoombaSerial(const RoombaSerial&) = delete;
    RoombaSerial& operator=(const RoombaSerial&) = delete;

    std::string received_command;
    std::string args[30];
    std::array<uint8_t, 255> command_data;
    int index;
    int arg_count;
    std::map<std::string, uint8_t> commandsMap { {"START", START}, {"BAUD", BAUD}, {"SAFE", SAFE}, {"FULL", FULL}, {"CLEAN", CLEAN}, {"MAX", MAX}, {"SPOT", SPOT}, {"SEEK_DOCK", SEEK_DOCK}, {"SCHEDULE", SCHEDULE}, {"SET_DAY_TIME", SET_DAY_TIME}, {"POWER", POWER}, {"DRIVE", DRIVE}, {"DRIVE_DIRECT", DRIVE_DIRECT}, {"DRIVE_PWM", DRIVE_PWM}, {"MOTORS", MOTORS}, {"PWM_MOTORS", PWM_MOTORS}, {"LEDS", LEDS}, {"SCHEDULE_LEDS", SCHEDULE_LEDS}, {"DIGIT_LEDS", DIGIT_LEDS}, {"ASCII_LEDS", ASCII_LEDS}, {"BUTTONS", BUTTONS}, {"SONG", SONG}, {"PLAY", PLAY}, {"SENSORS", SENSORS}, {"QUERY", QUERY}, {"STREAM", STREAM}, {"PAUSE_RESUME_STREAM", PAUSE_RESUME_STREAM} };
    
    static const constexpr std::chrono::milliseconds ReadTimeout = std::chrono::milliseconds(200);
    SerialLink usb_tll;

};
 

#endif
