/**
 * @file Opcodes.h
 * @author Vincent de Man
 * @brief Opcodes header file for roomba project
 * @version 0.1
 * @date 2021-06-02
 * @details Opcodes header file for roomba project. Used to define the opcodes of the roomba.
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef OPCODES_H
#define OPCODES_H

//starting commands
#define START   128
#define BAUD    129

//mode commands
#define SAFE    131
#define FULL    132

//cleaning commands
#define CLEAN   135
#define MAX     136 
#define SPOT    134
#define SEEK_DOCK 143
#define SCHEDULE 167
#define SET_DAY_TIME 168
#define POWER 133

//actuator commands
#define DRIVE 137
#define DRIVE_DIRECT 145
#define DRIVE_PWM 146
#define MOTORS 138
#define PWM_MOTORS 144
#define LEDS 139 
#define SCHEDULE_LEDS 162
#define DIGIT_LEDS 163 
#define ASCII_LEDS 164
#define BUTTONS 165 
#define SONG 140 
#define PLAY 141

//input commands
#define SENSORS 142
#define QUERY 149
#define STREAM 148 
#define PAUSE_RESUME_STREAM 150 

//define sensor packets
#define BUMP_WHEEL_DROP 7
#define WALL 8
#define CLIFF_LEFT 9 
#define CLIFF_FRONT_LEFT 10 
#define CLIFF_FRONT_RIGHT 11
#define CLIFF_RIGHT 12 
#define VIRTUAL_WALL 13 
#define WHEEL_OVERCURRENT 14 
#define DIRT_DETECT 15 
#define UNUSED_BYTE 16 
#define INFRA_RED 17 
#define IR_LEFT 52
#define IR_RIGHT 53 
#define P_BUTTONS 18 
#define DISTANCE 19 
#define ANGLE 20 
#define CHARGING_STATE 21 
#define VOLTAGE 22
#define CURRENT 23
#define TEMPERATURE 24 
#define BATTERY_CHARGE 25
#define BATTERY_CAPACITY 26
#define WALL_SIGNAL 27 
#define CLIFF_LEFT_SIGNAL 28 
#define CLIFF_FRONT_LEFT_SIGNAL 29 
#define CLIFF_FRONT_RIGHT_SIGNAL 30
#define CLIFF_RIGHT_SIGNAL 31
#define CHARGING_SOURCES_AVAILABLE 34 
#define OI_MODE 35 
#define SONG_NUMBER 36 
#define SONG_PLAYING 37 
#define NUM_STREAM_PACKETS 38 
#define REQ_VELOCITY 39 
#define REQ_RADIUS 40 
#define REQ_RIGHT_VELOCITY 41 
#define REQ_LEFT_VELOCITY 42 
#define RIGHT_ENCODER_COUNT 43 
#define LEFT_ENCODER_COUNT 44 
#define LIGHT_BUMPER 45 
#define LIGHT_BUMP_LEFT_SIGNAL 46 
#define LIGHT_BUMP_FRONT_LEFT_SIGNAL 47 
#define LIGHT_BUMP_CENTER_LEFT_SIGNAL 48 
#define LIGHT_BUMP_CENTER_RIGHT_SIGNAL 49 
#define LIGHT_BUMP_FRONT_RIGHT_SIGNAL 50 
#define LIGHT_BUMP_RIGHT_SIGNAL 51 
#define LEFT_MOTOR_CURRENT 54 
#define RIGHT_MOTOR_CURRENT 55
#define MAIN_BRUSH_MOTOR_CURRENT 56 
#define SIDE_BRUSH_MOTOR_CURRENT 56 
#define STASIS 58 

#endif