#include "interrupt.h"

void __interrupt() myISR (void){
    
    /* Buttons */
    if(manualButton){
        operationMode = joystick;
        manualButton = 0;
    }
    if (openButton){
        operationMode = fullyOpen;
        openButton = 0;
    }
    if (closeButton){
        operationMode = fullyClosed;
        closeButton = 0;
    }
    if (randomButton){
        operationMode = random;
        randomButton = 0;
    }
    __delay_ms(10);
    updateScreen = true;
}