#include "interrupts.h"

void interrupts_Configuration(void){
    /* Interrupt on change*/
        /*Manual Button*/
        IOCCFbits.IOCCF0 = 0;   //interrupt on change for C5 - flag
        IOCCNbits.IOCCN0 = 0;   //interrupt on change for C5 - negative
        IOCCPbits.IOCCP0 = 1;   //interrupt on change for C5 - positive
        
        /*Open Button*/
        IOCCFbits.IOCCF1 = 0;   //interrupt on change for C5 - flag
        IOCCNbits.IOCCN1 = 0;   //interrupt on change for C5 - negative
        IOCCPbits.IOCCP1 = 1;   //interrupt on change for C5 - positive
        
        /*Close Button*/
        IOCCFbits.IOCCF2 = 0;   //interrupt on change for C5 - flag
        IOCCNbits.IOCCN2 = 0;   //interrupt on change for C5 - negative
        IOCCPbits.IOCCP2 = 1;   //interrupt on change for C5 - positive
        
        /*Random Button*/
        IOCCFbits.IOCCF3 = 0;   //interrupt on change for C5 - flag
        IOCCNbits.IOCCN3 = 0;   //interrupt on change for C5 - negative
        IOCCPbits.IOCCP3 = 1;   //interrupt on change for C5 - positive
    
    PIE0bits.IOCIE = 1;     // Enable IOCI interrupt 

    /* General */
    INTCONbits.GIE = 1;         // Enable global interrupt
    INTCONbits.PEIE = 1;        // Peripheral interrupt enable
}