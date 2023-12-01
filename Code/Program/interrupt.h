#ifndef INTERRUPT_H
#define	INTERRUPT_H
    /* Includes */
    #include <xc.h>
#include <stdbool.h>
#define _XTAL_FREQ 4000000

    

    /* Definitions */
#define joystick 0
#define fullyOpen 1
#define fullyClosed 2
#define random  3

#define manualButton    IOCCF0
#define openButton      IOCCF1
#define closeButton     IOCCF2
#define randomButton    IOCCF3
       
char operationMode = 0;
bool updateScreen = true;

#endif	/* INTERRUPT_H */

