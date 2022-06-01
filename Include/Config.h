/**
 * @file Config.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <string> 

//General configuration
#define BatteryStatusSleepTime 10
#define ModeSleepTime 10
#define ButtonsSleepTime 100000
#define UserCommandsSleepTime 1
#define MaxBatteryCharge 65535
#define CleanButtonBit 0x01
#define SpotButtonBit 0x02
#define DockButtonBit 0x04

//MQTT configuration: 
const std::string appname = "roombatvms";
const std::string clientname = "mode";
const std::string host =  "broker.mqttdashboard.com";//"broker.hivemq.com";
const int port = 1883;

#endif