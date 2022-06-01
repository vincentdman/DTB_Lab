// /**
//  * @file BatteryIndicator.cpp
//  * @author Vincent de Man
//  * @brief Implementation of the batteryindicator class.
//  * @version 0.2
//  * @date 2021-05-23
//  * @class Class to display a battery icon on the sense hat. 
//  * @copyright Copyright (c) 2021
//  * @details Implementation of the BatteryIndicator class. 
//  */
// #include "BatteryIndicator.h"

// const Pixel BatteryIndicator::GreenPixel        = {0,       255,    0};
// const Pixel BatteryIndicator::LightGreenPixel   = {0,       128,    0};
// const Pixel BatteryIndicator::YellowPixel       = {255,     255,    0};
// const Pixel BatteryIndicator::OrangePixel       = {255,     165,    0};
// const Pixel BatteryIndicator::RedPixel          = {255,     0,      0};
// const Pixel BatteryIndicator::GreyPixel         = {128,     128,    128};
// const Pixel BatteryIndicator::BlankPixel        = {0,       0,      0};

// const BatteryIndicator::InternalBatteryColour_t BatteryGreen{BatteryIndicator::GreenPixel, BatteryIndicator::GreenPixel, BatteryIndicator::GreenPixel, BatteryIndicator::GreenPixel, BatteryIndicator::GreenPixel};
// const BatteryIndicator::InternalBatteryColour_t BatteryLightGreen{BatteryIndicator::LightGreenPixel, BatteryIndicator::LightGreenPixel, BatteryIndicator::LightGreenPixel, BatteryIndicator::LightGreenPixel};
// const BatteryIndicator::InternalBatteryColour_t BatteryYellow{BatteryIndicator::YellowPixel, BatteryIndicator::YellowPixel, BatteryIndicator::YellowPixel};
// const BatteryIndicator::InternalBatteryColour_t BatteryOrange{BatteryIndicator::OrangePixel, BatteryIndicator::OrangePixel};
// const BatteryIndicator::InternalBatteryColour_t BatteryRed{BatteryIndicator::RedPixel};

// /**
//  * @brief Construct a new BatteryIndicator object. 
//  * 
//  * @details Constructor clears the display and sets the border for the battery icon.
//  */
// BatteryIndicator::BatteryIndicator()
// {
//     LOG(LOG::DEBUG) << "Constructor BatteryIndicator got called!";
//     _Display.clear();
//     DisplayBatteryBorder();
// }

// /**
//  * @brief Destroy the Battery Indicator object
//  * 
//  * @details Destroys the object and set the leds to the off state. 
//  */
// BatteryIndicator::~BatteryIndicator()
// {
//     LOG(LOG::DEBUG) << "Destructor BatteryIndicator got called!";
//     _Display.clear();
// }

// /**
//  * @brief Function to get the instance of the singleton. 
//  * 
//  * @return BatteryIndicator& the instance of the battery class. 
//  * 
//  * @details Function to get the instance of the singelton so only one BatteryIndicator class can exist. 
//  */
// BatteryIndicator &BatteryIndicator::getInstance()
// {
//     static BatteryIndicator instance;
//     return instance;
// }

// /**
//  * @brief Function to set the border of the icon.
//  * 
//  * @details Function to set a light grey border of the battery icon. 
//  */
// void BatteryIndicator::DisplayBatteryBorder()
// {
//     LOG(LOG::DEBUG) << "Battery border gets displayed";
//     int Error = 0;
//     for (int i = BATTERY_BORDER_OFFSET; i < MATRIX_SIZE - BATTERY_BORDER_OFFSET; i++)
//     {
//         Error |= _Display.setPixel(i, 0, GreyPixel);
//         Error |= _Display.setPixel(BATTERY_BORDER_OFFSET, i - BATTERY_BORDER_OFFSET, GreyPixel);
//         Error |= _Display.setPixel(i, MATRIX_SIZE - BATTERY_TIP_OFFSET, GreyPixel);
//         Error |= _Display.setPixel(MATRIX_SIZE - BATTERY_TIP_OFFSET, i, GreyPixel);
//     };
//     Error |= DisplayBatteryTip();
//     DisplayingErrorCheck(Error);
// }

// /**
//  * @brief Function to display the tip of the battery. 
//  * 
//  * @return int returns potential drawing errors.
//  * 
//  * @details Function to display the tip of the battery. 
//  */
// int BatteryIndicator::DisplayBatteryTip()
// {
//     LOG(LOG::DEBUG) << "Battery TIP will be displayed";
//     int Error = 0;
//     Error |= _Display.setPixel(BATTERY_TIP_HIGH, ROW_SEVEN, GreyPixel);
//     Error |= _Display.setPixel(BATTERY_TIP_LOW, ROW_SEVEN, GreyPixel);
//     return Error;
// }

// /**
//  * @brief Function to set the battery indicator for a specific percentage.
//  * 
//  * @param percentage current percentage of the battery charge.
//  * 
//  * @details Function to set the battery indicator for a specific percentage. 
//  */

// void BatteryIndicator::SetBatteryIndicator(int percentage){
//     if(percentage >= 80)
//     {
//         SetBatteryGreen();
//     }
//     else if(percentage >= 60)
//     {
//         SetBatteryLightGreen();
//     }
//     else if(percentage >= 40)
//     {
//         SetBatteryYellow();
//     }
//     else if(percentage >= 20)
//     {
//         SetBatteryOrange();
//     }
//     else
//     {
//         SetBatteryRed();
//     }
// }

// /**
//  * @brief Function to set the battery colour to green.
//  * 
//  * @details Function to set the battery colour to green. Whole battery will become green execpt for the border. 
//  */
// void BatteryIndicator::SetBatteryGreen()
// {
//     LOG(LOG::INFO) << "Battery displays green";
//     DisplayInternalBattery(BatteryGreen);
// }

// /**
//  * @brief Function to set the battery icon to light green.
//  * 
//  * @details Function to set the battery icon to light green. One line will be blank so user knows battery is depleting. 
//  */
// void BatteryIndicator::SetBatteryLightGreen()
// {
//     LOG(LOG::INFO) << "Battery displays light green";
//     DisplayInternalBattery(BatteryLightGreen);
// }

// /**
//  * @brief Function to set the battery icon to yellow.
//  * 
//  * @details Function to set the battery icon to yellow. Also two lines will be blank so the user sees the battery is starting to drain more. 
//  */
// void BatteryIndicator::SetBatteryYellow()
// {
//     LOG(LOG::INFO) << "Battery displays yellow";
//     DisplayInternalBattery(BatteryYellow);
// }

// /**
//  * @brief Function to set the battery icon to orange.
//  * 
//  * @details Function to set the battery icon to orange. And makes 3 lines blank so user sees the battery is going low soon.
//  */
// void BatteryIndicator::SetBatteryOrange()
// {
//     LOG(LOG::INFO) << "Battery displays orange";
//     DisplayInternalBattery(BatteryOrange);
// }

// /**
//  * @brief Function to set the battery icon to red.
//  * 
//  * @details Function to set the battery icon to red. 4 lines will be blank so user sees it is crucial to charge the device now. 
//  */
// void BatteryIndicator::SetBatteryRed()
// {
//     LOG(LOG::INFO) << "Battery displays red";
//     DisplayInternalBattery(BatteryRed);
// }

// /**
//  * @brief Function to set the internal rows of the battery icon.
//  * 
//  * @param RowData The struct containing the colour of the rows inside the icon.
//  * 
//  * @details Function to set the internal rows of the battery icon based on the data inside the passed in struct.  
//  */
// void BatteryIndicator::DisplayInternalBattery(const InternalBatteryColour_t &RowData)
// {
//     int Error = 0;
//     for (int i = BATTERY_INTERNAL_OFFSET; i < MATRIX_SIZE - BATTERY_INTERNAL_OFFSET; i++)
//     {
//         Error |= _Display.setPixel(i, ROW_ONE, RowData.Pixel_Row1);
//         Error |= _Display.setPixel(i, ROW_TWO, RowData.Pixel_Row2);
//         Error |= _Display.setPixel(i, ROW_THREE, RowData.Pixel_Row3);
//         Error |= _Display.setPixel(i, ROW_FOUR, RowData.Pixel_Row4);
//         Error |= _Display.setPixel(i, ROW_FIVE, RowData.Pixel_Row5);
//     }
//     DisplayingErrorCheck(Error);
// }

// /**
//  * @brief Function to check for displaying errors.
//  * 
//  * @param Error The parameter that gets checked for errors. 
//  * 
//  * @details Function that checks for displaying errors. When there is a error a message will be printed to cerr. 
//  */
// void BatteryIndicator::DisplayingErrorCheck(int Error)
// {
//     if (Error != 0)
//     {
//         LOG(LOG::ERROR) << "Something went wrong while trying to set the sense hat rgb lights Error: " << Error;
//     }
// }
