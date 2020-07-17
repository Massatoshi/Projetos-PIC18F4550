#include <p18f4550.h>
#include <stdlib.h>

#include "Config.h"
#include "displayLCD.h"
#define Botao_B1 PORTEbits.RE0
#define Botao_B2 PORTEbits.RE1
#define Botao_B3 PORTEbits.RE2

unsigned int valor_AN0 = 00;

const unsigned char Texto_0[] = "Conversor ADC ";
const unsigned char Texto_1[] = "AN0 = ";

void delay_ms(int delaytime)
{
while (--delaytime)
{
__delay_ms(1);
}
} 

void main(){
 
    ADCON1 = 0x0E; 
    ADCON2bits.ADFM = 1; 
    ADCON1bits.VCFG0 = 0; 
    ADCON1bits.VCFG1 = 0; 
    ADCON2bits.ADCS0 = 0; 
    ADCON2bits.ADCS1 = 1;
    ADCON2bits.ADCS2 = 1;
    ADCON2bits.ACQT0 = 1; 
    ADCON2bits.ACQT1 = 0;
    ADCON2bits.ACQT2 = 0;
    ADCON0bits.ADON = 1; 
    ADCON0bits.CHS0 = 0; 
    ADCON0bits.CHS1 = 0;
    ADCON0bits.CHS2 = 0;
    ADCON0bits.CHS3 = 0;


    ConfiguraLCD();
    delay_ms(20);
    PosicaoCursorLCD(1,1);
    EscreveFraseRamLCD(Texto_0);
    PosicaoCursorLCD(2,1);
    EscreveFraseRamLCD(Texto_1);
    DesligaCursor();
    delay_ms(3000);
    while(1){
        ADCON0bits.GO = 1; 
        while(ADCON0bits.GO_DONE == 1) {} {   
            valor_AN0 = (ADRESH<<8) + ADRESL; 
            }
        PosicaoCursorLCD(2,1);
        EscreveFraseRamLCD(Texto_1);
        PosicaoCursorLCD(2,6);
        EscreveInteiroLCD(valor_AN0);
        delay_ms(100);
        }
}