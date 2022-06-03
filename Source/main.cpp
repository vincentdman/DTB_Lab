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

    sleep(1); //so its slower than publish task       
    char* zErrMsg = 0;

    while (1) 
    {
    
        char temp1[1000];
        char temp2[1000];
        char hum1[1000];
        char hum2[1000];
        char pres1[1000];
        char pres2[1000];
        char NODE_ID1[5];
        char NODE_ID2[5];
        char location1[100];
        char location2[100];
        bool node1 = false;
        bool node2 = false;

        while (node1 && node2)
        {
            if (PressureGetter.get_flag())
            {
                temp = TemperatureGetter.get_received_command();
                hum = HumidityGetter.get_received_command();
                pres = PressureGetter.get_received_command();
            }

            if (temp[0] == '1')
            {
                NODE_ID = "1";
                location = "Vincent";
                node1 = true;

            }
            if (temp[0] == '2')
            {
                NODE_ID = "2";
                location = "Marijn";
                node2 = true;
            }
        }

        //sqlite3_open("DataBaseMV.db", &db);

        auto current = std::chrono::system_clock::now();
        std::time_t current_time = std::chrono::system_clock::to_time_t(current);
        tm* tm_local = localtime(&current_time);

        char* sql = "INSERT INTO timestamp_measurement(UNIX_TIME, current_hour, current_minute, current_second, current_day, current_year) VALUES(" + std::to_string(current_time) + "," + std::to_string(tm_local->tm_hour) + "," + ::to_string(tm_local->tm_minute) + "," + ::to_string(tm_local->tm_second) + "," + ::to_string(tm_local->tm_yday) + "," + ::to_string(tm_local->tm_year) + ");" \
            "INSERT INTO node(NODE_ID, location, UNIX_TIME) VALUES(" + NODE_ID1 + "," + location1 + "," + std::to_string(current_time) + "); " \
            "INSERT INTO node(NODE_ID, location, UNIX_TIME) VALUES(" + NODE_ID2 + "," + location2 + "," + std::to_string(current_time) + "); " \
            "INSERT INTO sample(NODE_ID, SAMPLE_NO, measured_variable, value, unit, resolution) VALUES(" + temp1 + ");" \
            "INSERT INTO sample(NODE_ID, SAMPLE_NO, measured_variable, value, unit, resolution) VALUES(" + hum1 + ");" \
            "INSERT INTO sample(NODE_ID, SAMPLE_NO, measured_variable, value, unit, resolution) VALUES(" + pres1 + ");" \
            "INSERT INTO sample(NODE_ID, SAMPLE_NO, measured_variable, value, unit, resolution) VALUES(" + temp2 + ");" \
            "INSERT INTO sample(NODE_ID, SAMPLE_NO, measured_variable, value, unit, resolution) VALUES(" + hum2 + ");" \
            "INSERT INTO sample(NODE_ID, SAMPLE_NO, measured_variable, value, unit, resolution) VALUES(" + pres2 + ");";

    }

    std::cout << sql << endl;
    //sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    //sqlite3_close(db);
    }
}
