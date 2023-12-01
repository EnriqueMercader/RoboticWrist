#include "peripheralPinSelect.h"

void peripheralPinSelect_Configuration(void){  
    RB2PPS = 0x0B;   //RB2->CCP3:CCP3;    
    RB0PPS = 0x09;   //RB0->CCP1:CCP1;    
    RB1PPS = 0x0A;   //RB1->CCP2:CCP2;    
    RB3PPS = 0x0C;
    RE0PPS = 0x0D;
}
