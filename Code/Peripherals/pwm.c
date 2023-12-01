#include "pwm.h"

void pwm_start(void){
    /* PWM 1 */
    CCP1CON = 0x8F;                 // MODE PWM; EN enabled; CCP1FMT right_aligned; 
	CCPR1H = 0;
	CCPR1L = 0;
    CCPTMRS0bits.C1TSEL = 0x1;      // Selecting Timer 2
    
    /* PWM 2 */
    CCP2CON = 0x8F;                 // MODE PWM; EN enabled; CCP2FMT right_aligned; 
	CCPR2H = 0;
	CCPR2L = 0;                     // Servo starts where it was left on.
    CCPTMRS0bits.C2TSEL = 0x1;      // Selecting Timer 2
    
    /* PWM 3 */
    CCP3CON = 0x8F;                 // MODE PWM; EN enabled; CCP3FMT right_aligned; 
	CCPR3H = 0;
	CCPR3L = 0;
    CCPTMRS0bits.C3TSEL = 0x1;      // Selecting Timer 2
    
    /* PWM 4 */
    CCP4CON = 0x8F;                 // MODE PWM; EN enabled; CCP3FMT right_aligned; 
	CCPR4H = 0;
	CCPR4L = 0;
    CCPTMRS0bits.C4TSEL = 0x1;      // Selecting Timer 2
    
    /* PWM 5 */
    CCP5CON = 0x8F;                 // MODE PWM; EN enabled; CCP3FMT right_aligned; 
	CCPR5H = 0;
	CCPR5L = 0;
    CCPTMRS1bits.C5TSEL = 0x1;      // Selecting Timer 2
    
    /* Timer 2 configuration */
    T2CLKCON = 0x01;    // T2CS FOSC/4; 
    T2HLT = 0x00;       // T2PSYNC Not Synchronized; T2MODE Software control; T2CKPOL Rising Edge; T2CKSYNC Not Synchronized;
    T2RST = 0x00;       // T2RSEL T2CKIPPS pin;
    T2PR = 0x9B;        // PR2 155; 
    T2TMR = 0x00;       // TMR2 0; 
    PIR4bits.TMR2IF = 0;    // Clearing IF flag.
    T2CON = 0xF0;       // T2CKPS 1:128; T2OUTPS 1:1; TMR2ON on; 
}