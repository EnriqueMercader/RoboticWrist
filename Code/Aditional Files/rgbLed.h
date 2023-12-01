#ifndef RGBLED_H
#define	RGBLED_H

    /* Includes */
    #include <xc.h>

    /* Definitions */
    #define red 0
    #define blue 1
    #define green 2
    #define purple 3
    #define lightGreen 4
    #define lightBlue 5
    #define white   6
    #define redLED  LATB7
    #define blueLED  LATB5
    #define greenLED  LATB6

    /* Function prototypes */
    void led_setColor(char color);

#endif	/* RGBLED_H */

