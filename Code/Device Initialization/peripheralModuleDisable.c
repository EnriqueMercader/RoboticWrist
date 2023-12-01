#include "peripheralModuleDisable.h"

void peripheralModuleDisable_Configuration(void){
    SYSCMD  = Enabled;  // Peripheral System Clock Network
    FVRMD   = Disabled; // Fixed Voltage Referenc
    CRCMD   = Disabled; // CRC module
    SCANMD  = Enabled;  // Program Memory Scanner Module
    NVMMD   = Enabled;  // Non-Volatile Memory Module
    CLKRMD  = Disabled; // Clock Reference CLKR
    IOCMD   = Enabled;  // Interrupt-on-Change
    NCOMD   = Disabled; // Numerically Control Oscillator
    TMR6MD  = Disabled; // Timer 6
    TMR5MD  = Disabled; // Timer 5
    TMR4MD  = Enabled;  // Timer 4
    TMR3MD  = Disabled; // Timer 3
    TMR2MD  = Enabled;  // Timer 
    TMR1MD  = Disabled; // Timer 1
    TMR0MD  = Disabled;  // Timer 0
    DACMD   = Disabled; // Digital to Analog Converter
    ADCMD   = Enabled; // Analog to Digital Converter
    CMP2MD  = Disabled; // Comparator 2
    CMP1MD  = Disabled; // Comparator 1
    ZCDMD   = Disabled; // Zero Cross Detect module
    PWM7MD  = Disabled; // Pulse-Width Modulator 7
    PWM6MD  = Disabled; // Pulse-Width Modulator 6
    CCP5MD  = Enabled; // Capture and Compare PWM module 5
    CCP4MD  = Enabled;  // Capture and Compare PWM module 4
    CCP3MD  = Enabled;  // Capture and Compare PWM module 3
    CCP2MD  = Enabled;  // Capture and Compare PWM module 2
    CCP1MD  = Enabled;  // Capture and Compare PWM module 1
    UART1MD = Disabled;  // UART Module
    MSSP2MD = Disabled; // 
    MSSP1MD = Disabled;
    CWG3MD  = Disabled; // Complimentary Waveform Generator 3
    CWG2MD  = Disabled; // Complimentary Waveform Generator 2
    CWG1MD  = Disabled; // Complimentary Waveform Generator 1
    SMT2MD  = Disabled; // Signal Measurement Timer2
    SMT1MD  = Disabled; // Signal Measurement Timer1
    CLC4MD  = Disabled; // Configurable Logic Cell 4
    CLC3MD  = Disabled; // Configurable Logic Cell 3
    CLC2MD  = Disabled; // Configurable Logic Cell 2
    CLC1MD  = Disabled; // Configurable Logic Cell 1
    DSMMD   = Disabled; // Data Signal Modulator
}
