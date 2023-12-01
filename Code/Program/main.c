/* Libraries */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <xc.h>

/* Included Files */
#include "configurationBits.h"
#include "pwm.h"
#include "lcd.h"
#include "generalInputOutput.h"
#include "peripheralModuleDisable.h"
#include "peripheralPinSelect.h"
#include "oscillator.h"
#include "adc.h"
#include "interrupts.h"
#include "interrupt.h"
#include "rgbLed.h"

/* Definitions */
#define numberOfServos      5
#define fullyOpenValue      74
#define fullyClosedValue    18

/* Functions */
void initializeDevice(void){
    oscillator_Configuration();
    peripheralModuleDisable_Configuration();
    peripheralPinSelect_Configuration();
    generalInputOutput_Configuration();
    adc_Initialize();
    pwm_start();
    interrupts_Configuration();
}
void modeUpdate(void){
    if (updateScreen == true){
            lcdClear();
            switch (operationMode){
            case joystick:
                led_setColor(green);
                lcd_printText_XY("MANUAL",1,1);
                lcd_printText_XY("A",8,1);
                lcd_printText_XY("B",13,1);
                lcd_printText_XY("C",3,2);
                lcd_printText_XY("D",8,2);
                lcd_printText_XY("E",13,2);
                break;
            case fullyOpen:
                led_setColor(blue);
                lcd_printText_XY("   Fully Open",1,1);
                lcd_printText_XY("All servos 100%",1,2);
                CCPR1L = fullyOpenValue;
                CCPR2L = fullyOpenValue;
                CCPR3L = fullyOpenValue;
                CCPR4L = fullyOpenValue;
                CCPR5L = fullyOpenValue;
                break;
            case fullyClosed:
                led_setColor(white);
                lcd_printText_XY("  Fully Closed",1,1);
                lcd_printText_XY("  All servos 0%",1,2);
                CCPR1L = fullyClosedValue;
                CCPR2L = fullyClosedValue;
                CCPR3L = fullyClosedValue;
                CCPR4L = fullyClosedValue;
                CCPR5L = fullyClosedValue;
                break;
            case random:
                led_setColor(purple);
                lcd_printText_XY("Random",1,1);
                lcd_printText_XY("A",8,1);
                lcd_printText_XY("B",13,1);
                lcd_printText_XY("C",3,2);
                lcd_printText_XY("D",8,2);
                lcd_printText_XY("E",13,2);
                
                for (char i = 0; i < numberOfServos; i++){
                   char temporaryPercentage = rand() % 100;
                   switch (i){
                        case 0:
                            lcd_printText_XY("   ",9,1);
                            lcd_printNumber_XY(temporaryPercentage,9,1);
                            lcd_printCharacter('%');
                            CCPR1L = ((temporaryPercentage / 2) + 20);
                            break;
                        case 1:
                            lcd_printText_XY("   ",14,1);
                            lcd_printNumber_XY(temporaryPercentage,14,1);
                            lcd_printCharacter('%');
                            CCPR2L = ((temporaryPercentage / 2) + 20);
                            break;
                        case 2:
                            lcd_printText_XY("   ",4,2);
                            lcd_printNumber_XY(temporaryPercentage,4,2);
                            lcd_printCharacter('%');
                            CCPR3L = ((temporaryPercentage / 2) + 20);
                            break;
                        case 3:
                            lcd_printText_XY("   ",9,2);
                            lcd_printNumber_XY(temporaryPercentage,9,2);
                            lcd_printCharacter('%');
                            CCPR4L = ((temporaryPercentage / 2) + 20);
                            break;
                        case 4:
                            lcd_printText_XY("   ",14,2);
                            lcd_printNumber_XY(temporaryPercentage,14,2);
                            lcd_printCharacter('%');
                            CCPR5L = ((temporaryPercentage / 2) + 20);
                            break;
                        default:
                            break;
                    }
                }
                break;
            default:
                break;
            }
            updateScreen = false;
        }
}
void joystickControl(void){
    /* Local variables */
    char previousPotentiometerReading[5] = {0,0,0,0,0};
    char newPotentiometerReading[5] = {0,0,0,0,0};
    
    /* Code */
    if (operationMode == joystick){
            for (char i = 0; i < numberOfServos; i++){
                    newPotentiometerReading[i] = adc_readPercentage(i);
                    if (newPotentiometerReading[i] >= 100){
                        newPotentiometerReading[i] = 99;
                    }
                    __delay_ms(1);
                    if (newPotentiometerReading[i] != previousPotentiometerReading[i]){
                        switch (i){
                            case 0:
                                lcd_printText_XY("   ",9,1);
                                lcd_printNumber_XY(newPotentiometerReading[i],9,1);
                                lcd_printCharacter('%');
                                CCPR1L = ((newPotentiometerReading[i] / 2) + 20);
                                break;
                            case 1:
                                lcd_printText_XY("   ",14,1);
                                lcd_printNumber_XY(newPotentiometerReading[i],14,1);
                                lcd_printCharacter('%');
                                CCPR2L = ((newPotentiometerReading[i] / 2) + 20);
                                break;
                            case 2:
                                lcd_printText_XY("   ",4,2);
                                lcd_printNumber_XY(newPotentiometerReading[i],4,2);
                                lcd_printCharacter('%');
                                CCPR3L = ((newPotentiometerReading[i] / 2) + 20);
                                break;
                            case 3:
                                lcd_printText_XY("   ",9,2);
                                lcd_printNumber_XY(newPotentiometerReading[i],9,2);
                                lcd_printCharacter('%');
                                CCPR4L = ((newPotentiometerReading[i] / 2) + 20);
                                break;
                            case 4:
                                lcd_printText_XY("   ",14,2);
                                lcd_printNumber_XY(newPotentiometerReading[i],14,2);
                                lcd_printCharacter('%');
                                CCPR5L = ((newPotentiometerReading[i] / 2) + 20);
                                break;
                            default:
                                break;
                        }
                        previousPotentiometerReading[i] = newPotentiometerReading[i];
                    }
                }
        }
}
void main(void) {
    initializeDevice();
    lcd_Initialization();
    while (1){
        modeUpdate();
        joystickControl();
    }     
}
