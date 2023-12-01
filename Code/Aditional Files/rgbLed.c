#include "rgbLed.h"

void led_setColor(char color){
    switch (color) {
        case red:
            redLED      = 1;
            blueLED     = 0;
            greenLED    = 0;
            break;
        case blue:
            redLED      = 0;
            blueLED     = 1;
            greenLED    = 0;
            break;
        case green:
            redLED      = 0;
            blueLED     = 0;
            greenLED    = 1;
            break;
        case purple:
            redLED      = 1;
            blueLED     = 1;
            greenLED    = 0;
            break;
        case lightGreen:
            redLED      = 1;
            blueLED     = 0;
            greenLED    = 1;
            break;
        case lightBlue:
            redLED      = 0;
            blueLED     = 1;
            greenLED    = 1;
            break;
        case white:
            redLED      = 1;
            blueLED     = 1;
            greenLED    = 1;
            break;
        default:
            
            break;
    }
}
