#include"activity2.h"
#include <avr/io.h>
#include <util/delay.h>


void Init_ADC()
{
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}

uint16_t Read_ADC(uint8_t ch)
{
    //Selecting ADC Channel
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX|=ch;
    //Starts Single Conversion
    ADCSRA|=(1<<ADSC);
    while(!(ADCSRA&(1<<ADIF)));
    //Clearing ADIF
    ADCSRA|=(1<<ADIF);
    return(ADC);
}
