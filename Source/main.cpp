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
long long int SampleNumber = 10;
const short int Resolution = 16; 

static int callback(void* NotUsed, int argc, char** argv, char** azColName){
    int i;
    for(i = 0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
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
    MqttHandler.publishInfo(std::to_string(NodeID) + delimiter + std::to_string(NodeID) + std::to_string(SampleNumber) + delimiter + "'Temperature'" + delimiter + std::to_string(static_cast<int>(SensHat.get_temperature()) )  + delimiter + "'C'" + delimiter + std::to_string(Resolution) , "DataBaseMV/Temperature");
    //SampleNumber++;
    MqttHandler.publishInfo(std::to_string(NodeID) + delimiter + std::to_string(NodeID) + std::to_string(SampleNumber) + delimiter + "'Humidity'" + delimiter + std::to_string(static_cast<int>(SensHat.get_humidity()) )  + delimiter + "'%rh'" + delimiter + std::to_string(Resolution) , "DataBaseMV/Humidity");
    //SampleNumber++;
    MqttHandler.publishInfo(std::to_string(NodeID) + delimiter + std::to_string(NodeID) + std::to_string(SampleNumber) + delimiter + "'Pressure'" + delimiter + std::to_string(static_cast<int>(SensHat.get_pressure()) )  + delimiter + "'hPa'" + delimiter + std::to_string(Resolution) , "DataBaseMV/Pressure");
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
        std::string temp;
        std::string hum;
        std::string pres;
        std::string temp1;
        std::string temp2;
        std::string hum1;
        std::string hum2;
        std::string pres1;
        std::string pres2;
        std::string NODE_ID1;
        std::string NODE_ID2;
        std::string location1;
        std::string location2;
        bool node1 = false;
        bool node2 = false;

        while (!(node1 && node2))
        {
            if (PressureGetter.get_flag())
            {
                temp.clear();
                hum.clear();
                pres.clear();
                
                temp = TemperatureGetter.get_received_command();
                std::cout<<temp[0]<<std::endl; 
                hum = HumidityGetter.get_received_command();
                pres = PressureGetter.get_received_command();
            }

            if (temp[0] == '1')
            {
                //std::cout<<"1 done!\n\n";
                temp1 = temp;
                hum1 = hum;
                pres1 = pres;
                NODE_ID1 = "1";
                location1 = "Vincent";
                node1 = true;

            }
            if (temp[0] == '2')
            {
                //std::cout<<"2 done!\n\n";
                temp2 = temp;
                hum2 = hum;
                pres2 = pres;
                NODE_ID2 = "2";
                location2 = "Marijn";
                node2 = true;
            }
        }

        int ret = sqlite3_open("/home/pi/git/DTB_Lab/DataBaseStorage/DataBaseMV.db", &db);
        std::cout << "ret = " << ret << std::endl;
        auto current = std::chrono::system_clock::now();
        std::time_t current_time = std::chrono::system_clock::to_time_t(current);
        tm* tm_local = localtime(&current_time);

        std::string sql = "INSERT INTO timestamp_measurement(UNIX_TIME, current_hour, current_minute, current_second, current_day, current_year) VALUES(" + std::to_string(current_time) + "," + std::to_string(tm_local->tm_hour) + "," + std::to_string(tm_local->tm_min) + "," + std::to_string(tm_local->tm_sec) + "," + std::to_string(tm_local->tm_yday) + "," + std::to_string(tm_local->tm_year) + ");" \
            "INSERT INTO node(NODE_ID, location, UNIX_TIME, SAMPLE_NO) VALUES(" + NODE_ID1 + "," + "'" + location1 + "'" + "," + std::to_string(current_time) + "," + temp1[3] + temp1[4] + temp1[5] + "); " \
            "INSERT INTO node(NODE_ID, location, UNIX_TIME) VALUES(" + NODE_ID2 + "," + "'" + location2 + "'" + "," + std::to_string(current_time) + "," + temp1[0] + temp1[1] + temp1[2] + "); " \
            "INSERT INTO sample(NODE_ID, SAMPLE_NO, measured_variable, value, unit, resolution) VALUES(" + temp1 + ");" \
            "INSERT INTO sample(NODE_ID, SAMPLE_NO, measured_variable, value, unit, resolution) VALUES(" + hum1 + ");" \
            "INSERT INTO sample(NODE_ID, SAMPLE_NO, measured_variable, value, unit, resolution) VALUES(" + pres1 + ");"; \
            "INSERT INTO sample(NODE_ID, SAMPLE_NO, measured_variable, value, unit, resolution) VALUES(" + temp2 + ");" \
            "INSERT INTO sample(NODE_ID, SAMPLE_NO, measured_variable, value, unit, resolution) VALUES(" + hum2 + ");" \
            "INSERT INTO sample(NODE_ID, SAMPLE_NO, measured_variable, value, unit, resolution) VALUES(" + pres2 + ");";

        std::cout << sql << std::endl;


    int ret2 = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    std::cout << "ret2 = " << ret2 << std::endl;
    std::cout << zErrMsg << std::endl; 
    sqlite3_close(db);
    node1 = false;
    //node2 = false;
    }
}
