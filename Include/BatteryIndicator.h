/**
 * @file BatteryIndicator.h
 * @author Vincent de Man
 * @brief Class to display a battery icon on the sense hat.
 * @version 0.1
 * @date 2021-05-23
 * @details Header file for class BatteryIndicator. This class displays a battery icon on the sense hat.
 * The icon has 5 states the user can display to show the current battery capacity. 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef BATTERYINDICATOR_H
#define BATTERYINDICATOR_H

#include <iostream>
#include "Pixel.h"
#include "LedMatrix.h"
#include "LOG.h"

#define ROW_ONE   1
#define ROW_TWO   2
#define ROW_THREE 3
#define ROW_FOUR  4
#define ROW_FIVE  5
#define ROW_SEVEN 7

#define BATTERY_TIP_HIGH 3
#define BATTERY_TIP_LOW 4 

#define MATRIX_SIZE 8
#define BATTERY_BORDER_OFFSET 1
#define BATTERY_TIP_OFFSET 2
#define BATTERY_INTERNAL_OFFSET 2

class BatteryIndicator
{
public:
    BatteryIndicator();
    ~BatteryIndicator();
    BatteryIndicator(const BatteryIndicator &obj) = delete;
    BatteryIndicator &operator=(const BatteryIndicator &obj) = delete;
    [[nodiscard]] static BatteryIndicator &getInstance();

    void SetBatteryIndicator(int percentage);
    void SetBatteryGreen(void);
    void SetBatteryLightGreen(void);
    void SetBatteryYellow(void);
    void SetBatteryOrange(void);
    void SetBatteryRed(void);

    typedef struct
    {
        Pixel Pixel_Row1{0, 0, 0};
        Pixel Pixel_Row2{0, 0, 0};
        Pixel Pixel_Row3{0, 0, 0};
        Pixel Pixel_Row4{0, 0, 0};
        Pixel Pixel_Row5{0, 0, 0};

    } InternalBatteryColour_t;

    static const Pixel GreenPixel;
    static const Pixel LightGreenPixel;
    static const Pixel YellowPixel;
    static const Pixel OrangePixel;
    static const Pixel RedPixel;
    static const Pixel GreyPixel;
    static const Pixel BlankPixel;

private:
    void DisplayBatteryBorder(void);
    int DisplayBatteryTip(void);
    void DisplayingErrorCheck(const int Error);

    void DisplayInternalBattery(const InternalBatteryColour_t &RowData);

    LedMatrix _Display;

    static const InternalBatteryColour_t _BatteryGreen;
    static const InternalBatteryColour_t _BatteryLightGreen;
    static const InternalBatteryColour_t _BatteryYellow;
    static const InternalBatteryColour_t _BatteryOrange;
    static const InternalBatteryColour_t _BatteryRed;
};

#endif