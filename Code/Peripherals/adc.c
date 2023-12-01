#include "adc.h"

void adc_Initialize(void){
    // ADLTHL 0; 
    ADLTHL = 0x00;
    // ADLTHH 0; 
    ADLTHH = 0x00;
    // ADUTHL 0; 
    ADUTHL = 0x00;
    // ADUTHH 0; 
    ADUTHH = 0x00;
    // ADSTPTL 0; 
    ADSTPTL = 0x00;
    // ADSTPTH 0; 
    ADSTPTH = 0x00;
    // ADRPT 0; 
    ADRPT = 0x00;
    // ADPCH ANA0; 
    ADPCH = 0x00;
    // ADCAP Additional uC disabled; 
    ADCAP = 0x00;
    // ADPRE 0; 
    ADPRE = 0x00;
    // ADDSEN disabled; ADGPOL digital_low; ADIPEN disabled; ADPPOL VSS; 
    ADCON1 = 0x00;
    // ADCRS 0; ADMD Basic_mode; ADACLR disabled; ADPSIS ADRES; 
    ADCON2 = 0x00;
    // ADCALC First derivative of Single measurement; ADTMD disabled; ADSOI ADGO not cleared; 
    ADCON3 = 0x00;
    // ADAOV ACC or ADERR not Overflowed; 
    ADSTAT = 0x00;
    // ADNREF VSS; ADPREF VDD; 
    ADREF = 0x00;
    // ADACT disabled; 
    ADACT = 0x00;
    // ADCCS FOSC/4; 
    ADCLK = 0x01;
    // ADGO stop; ADFM right; ADON enabled; ADCONT disabled; ADCS FOSC/ADCLK; 
    ADCON0 = 0x84;
    // ADACQ 0; 
    ADACQ = 0x00;
    

}

int adc_readNumerical(char channel){
    ADPCH = channel;            // select the A/D channel     
    ADCON0bits.ADON = 1;        // Turn on the ADC module
    ADCON0bits.ADGO = 1;        // Start the conversion
    while (ADCON0bits.ADGO);    // Wait for the conversion to finish
    return ((ADRESH << 8) + ADRESL);
}

int adc_readPercentage(char channel){
    unsigned long int percentage = 0;
    ADPCH = channel;            // select the A/D channel     
    ADCON0bits.ADON = 1;        // Turn on the ADC module
    ADCON0bits.ADGO = 1;        // Start the conversion
    while (ADCON0bits.ADGO);    // Wait for the conversion to finish
    percentage = ((ADRESH << 8) + ADRESL);   
    percentage = ((percentage * 100)/1024)+1;
    return percentage;
}