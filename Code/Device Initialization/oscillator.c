#include "oscillator.h"

void oscillator_Configuration(void){
    OSCCON1 = 0x60;     // NOSC HFINTOSC; NDIV 1; 
    OSCCON3 = 0x00;     // CSWHOLD may proceed; SOSCPWR Low power; 
    OSCEN = 0x00;       // MFOEN disabled; LFOEN disabled; ADOEN disabled; SOSCEN disabled; EXTOEN disabled; HFOEN disabled; 
    OSCFRQ = 0x02;      // HFFRQ 4_MHz; 
    OSCTUNE = 0x00;     // HFTUN 0;
}