//#include <avr/sleep.h>
#include <avr/interrupt.h>
//#define LED_PIN 13
// Ham khoi tao Watchdog 8s
void init_WDT(){
  //SETUP WATCHDOG TIMER
  WDTCSR = (24);//change enable and WDE - also resets
  //  16 ms:     0b000000
  //  32 ms:     0b000001
  //  64 ms:     0b000010
  //  0.125s:    0b000011
  //  0.25s :    0b000100
  //  0.5s  :    0b000101
  //  1 second:  0b000110
  //  2 seconds: 0b000111
  //  4 seconds: 0b100000
  //  8 seconds: 0b100001
  WDTCSR = 0b100001; //  8 seconds
  WDTCSR |= (1<<6);//enable interrupt mode
}
// Ngat ADC
void disable_ADC(){
  //Disable ADC - don't forget to flip back after waking up if using ADC in your application ADCSRA |= (1 << 7);
  ADCSRA &= ~(1 << 7);
}
// Bat ADC
void enable_ADC(){
  ADCSRA |= (1 << 7);
  }
// Thiet lap che do ngu
void SLEEP_MODE(){ 
  //ENABLE SLEEP - this enables the sleep mode
  SMCR |= (1 << 2); //power down mode
  SMCR |= 1;//enable sleep
}
//BOD DISABLE
void BOD_DISABLE(){
  //BOD DISABLE - this must be called right before the __asm__ sleep instruction
  MCUCR |= (3 << 5); //set both BODS and BODSE at the same time
  MCUCR = (MCUCR & ~(1 << 5)) | (1 << 6); //then set the BODS bit and clear the BODSE bit at the same time  
}
void SLEEP_NOW(){
  __asm__  __volatile__("sleep");//in line assembler to go to sleep
}
void digitalInterrupt(){
  //needed for the digital input interrupt
}
ISR(WDT_vect){
  //DON'T FORGET THIS!  Needed for the watch dog timer.  This is called after a watch dog timer timeout - this is the interrupt function called after waking up
}// watchdog interrupt
