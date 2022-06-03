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
#include <chrono>

void MQTT_Updater(int Interval);
void DataBase();

CommandProcessor MqttHandler(appname, clientname, host, "DataBaseMV/niks" , port);

CommandProcessor TemperatureGetter(appname, "Temperature", host, "DataBaseMV/Temperature" , port);
CommandProcessor PressureGetter(appname, "Pressure", host, "DataBaseMV/Pressure" , port);
CommandProcessor HumidityGetter(appname, "Humidity", host, "DataBaseMV/Humidity" , port);
const int NodeID = 0x01; 
const std::string delimiter = ", ";
long long int SampleNumber = 0;
const short int Resolution = 16; 


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

    std::thread ThreadMQTT(MQTT_Updater,7);
    std::thread DataBaseThread(DataBase);

    ThreadMQTT.join();
    DataBaseThread.join();
    
    exit(0);
    return 0;
}

void MQTT_Updater(int Interval = 5)
{
    while(1)
    {
    MqttHandler.publishInfo(std::to_string(NodeID) + delimiter + std::to_string(SampleNumber) + delimiter + "'Temperature'" + delimiter + std::to_string(static_cast<int>(SensHat.get_temperature()) )  + delimiter + "'C'" + delimiter + std::to_string(Resolution) , "DataBaseMV/Temperature");
    MqttHandler.publishInfo(std::to_string(NodeID) + delimiter + std::to_string(SampleNumber) + delimiter + "'Humidity'" + delimiter + std::to_string(static_cast<int>(SensHat.get_humidity()) )  + delimiter + "'%rh'" + delimiter + std::to_string(Resolution) , "DataBaseMV/Humidity");
    MqttHandler.publishInfo(std::to_string(NodeID) + delimiter + std::to_string(SampleNumber) + delimiter + "'Pressure'" + delimiter + std::to_string(static_cast<int>(SensHat.get_pressure()) )  + delimiter + "'hPa'" + delimiter + std::to_string(Resolution) , "DataBaseMV/Pressure");
    
    SampleNumber++;
    sleep(Interval);
    }
    
}

void DataBase()
{
    sqlite3 *db;
    int rc;
    rc = sqlite3_open("test.db", &db);

    const auto p1 = std::chrono::system_clock::now();
    std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count();
    sleep(1); //so its slower than publish task       
    int MessageGotten = 0;
  

    while(1){
    if (MqttHandler.get_flag())
    {
           
            //LOG(LOG::INFO)<<"System received MQTT command from user and will execute it";
    std::cout<<"MQTT received: " <<  MqttHandler.get_received_command() << std::endl;
            //MqttHandler.publishInfo("testbericht", "roombatvms/mode");
           // sleep(1);
    }
 
    

    if(TemperatureGetter.get_flag())
    {
        std::string received = TemperatureGetter.get_received_command();
        // std::string Item0 = received.substr(0, received.find(delimiter));
        // std::string Item1 = received.substr(1, received.find(delimiter));
        // std::string Item2 = received.substr(2, received.find(delimiter));
        // std::string Item3 = received.substr(3, received.find(delimiter));

        // std::cout << "received: " << Item0 << std::endl; 
        //  std::cout << "received: " << Item1 << std::endl; 
        //   std::cout << "received: " << Item2 << std::endl; 
        //    std::cout << "received: " << Item3 << std::endl; 

size_t pos = 0;
std::string token;

while ((pos = received.find(delimiter)) != std::string::npos) 
{
    token = received.substr(0, pos);
    std::cout << token << std::endl;
    received.erase(0, pos + delimiter.length());

    
}


        //std::string token = s.substr(0, s.find(delimiter));
        
        std::cout<<"Temperature received: " <<  TemperatureGetter.get_received_command() << std::endl;
        MessageGotten++; 
    }
    if(HumidityGetter.get_flag())
    {
        std::cout<<"Humidity received: " <<  HumidityGetter.get_received_command() << std::endl;
        MessageGotten++; 
    }
    if(PressureGetter.get_flag())
    {
        std::cout<<"Pressure received: " <<  PressureGetter.get_received_command() << std::endl;
        MessageGotten++; 
    }
    if(MessageGotten >= 3)
    {
        MessageGotten = 0;
        const auto p1 = std::chrono::system_clock::now();
        std::cout << "received at: " << std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count()<<"\n";
        //std::cout << std::sys_seconds( std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count());
        
        std::cout << "\n\n\n";

    }


    }
}
