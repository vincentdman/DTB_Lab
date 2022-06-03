/**
 * @file main.cpp
 * @author TVMS
 * @brief main file for roomba code
 * @version 0.1
 * @date 2021-04-15
 * @details
 * @copyright Copyright (c) 2021
 */

#include "main.h"
#include <sqlite3.h> 

CommandProcessor MqttHandler(appname, clientname, host, port);
SenseHAT SensHat;
/**
 * @brief Main function of roomba code. 
 * 
 * @return int status the main exited with.
 * 
 * @details 
 */
int main(void)
{
    struct sigaction sa;
    set_signal(sa);
    sqlite3 *db;
    int rc;
    rc = sqlite3_open("test.db", &db);
    
    //StartRoomba(); 
    while(1){
    if (MqttHandler.get_flag())
        {
           
            //LOG(LOG::INFO)<<"System received MQTT command from user and will execute it";
    std::cout<<"MQTT received: " <<  MqttHandler.get_received_command() << std::endl;
            //MqttHandler.publishInfo("testbericht", "roombatvms/mode");
           // sleep(1);
        }
    

    
  
    
    MqttHandler.publishInfo( std::to_string(SensHat.get_temperature() ), "roombatvms/Temperature");
    MqttHandler.publishInfo( std::to_string(SensHat.get_humidity() ), "roombatvms/Humidity");
    MqttHandler.publishInfo( std::to_string(SensHat.get_pressure() ), "roombatvms/Pressure");
    sleep(1);
   
   
   // std::cout<<"test\n";
    // MqttHandler.publishInfo("testbericht", "roombatvms/mode");
     //sleep(1);
    //StartMainSystemThreads();    
    }
    exit(0);
    return 0;
}
