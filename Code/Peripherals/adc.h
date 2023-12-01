
#ifndef ADC_H
#define	ADC_H

#include <xc.h>
#define _XTAL_FREQ 4000000
void adc_Initialize(void);
int adc_readNumerical(char channel);
int adc_readPercentage(char channel);

#endif	/* ADC_H */

