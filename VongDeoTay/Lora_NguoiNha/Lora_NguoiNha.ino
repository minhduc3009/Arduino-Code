#include "SX1278.h"
#include <SPI.h>
#include "wiring_private.h"
#include "pins_arduino.h"
#include <avr/sleep.h>
#include <avr/power.h>

#include <stdio.h>
#include <string.h>

#include <StopWatch.h>
StopWatch Timer_secs_clock(StopWatch::SECONDS);
StopWatch Timer_secs_Rung(StopWatch::SECONDS);

#define LORA_MODE  4
#define LORA_CHANNEL  CH_6_BW_125
#define LORA_ADDRESS 7 //7,8,9

#define LORA_KEY_1 A4
#define LORA_KEY_2 A5

#define LED_BATT A1
#define LED_YT A2
#define LED_BN A3

#define VBAT A0
#define Rung  5

#define PO_RF  4

int buttonState1 = 0;
int buttonState2 = 0;

int e;
char my_packet[100];
char message1 [] = "Benh Nhan:04";
char message2 [] = "YTa";

char message_check_BN [] =  "Benh Nhan:04";
char message_check_YTa [] =  "YTa";
void setup()
{
  pinMode(PO_RF, OUTPUT);
  digitalWrite(PO_RF,LOW);
  
  pinMode(LORA_KEY_1, INPUT_PULLUP);
  pinMode(LORA_KEY_2, INPUT_PULLUP);

  pinMode(LED_BATT, OUTPUT);
  pinMode(LED_YT, OUTPUT);
  pinMode(LED_BN, OUTPUT);
  
  digitalWrite(LED_YT,0);
  digitalWrite(LED_BN,0);
  digitalWrite(LED_BATT,0);
  
  pinMode(VBAT, INPUT);
  pinMode(Rung, OUTPUT);
  digitalWrite(Rung,LOW);
  ADMUX = 0xc0;
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.print(F("Address:"));
  Serial.println(LORA_ADDRESS);
  // Print a start message
  Serial.println(F("sx1278 module and Arduino: send two packets (One to an addrees and another one in broadcast)"));

  // Power ON the module
  if (sx1278.ON() == 0){
    Serial.println(F("Setting power ON: SUCCESS "));
  } else {
    Serial.println(F("Setting power ON: ERROR "));
  }

  // Set transmission mode and print the result
  if (sx1278.setMode(LORA_MODE) == 0) {
    Serial.println(F("Setting Mode: SUCCESS "));
  } else {
    Serial.println(F("Setting Mode: ERROR "));
  }

  // Set header
  if (sx1278.setHeaderON() == 0) {
    Serial.println(F("Setting Header ON: SUCCESS "));
  } else {
    Serial.println(F("Setting Header ON: ERROR "));
  }

  // Select frequency channel
  if (sx1278.setChannel(LORA_CHANNEL) == 0) {
    Serial.println(F("Setting Channel: SUCCESS "));
  } else {
    Serial.println(F("Setting Channel: ERROR "));
  }

  // Set CRC
  if (sx1278.setCRC_ON() == 0) {
    Serial.println(F("Setting CRC ON: SUCCESS "));
  } else {
    Serial.println(F("Setting CRC ON: ERROR "));
  }

  // Select output power (Max, High, Intermediate or Low)
  if (sx1278.setPower('M') == 0) {
    Serial.println(F("Setting Power: SUCCESS "));
  } else {
    Serial.println(F("Setting Power: ERROR "));
  }

  // Set the node address and print the result
  if (sx1278.setNodeAddress(LORA_ADDRESS) == 0) {
    Serial.println(F("Setting node address: SUCCESS "));
  } else {
    Serial.println(F("Setting node address: ERROR "));
  }
  // Print a success message
  Serial.println(F("sx1278 configured finished"));
  Serial.println();
}
int check_BN=1;
int check_YTA=1;
void loop(void)
{
  // Receive message for 10 seconds
  //  e = sx1278.receivePacketTimeout(10000);
   e = sx1278.receivePacketTimeoutACK(3000);
  if (e == 0) {
//    Serial.println(F("Package received!"));
    for (unsigned int i = 0; i < sx1278.packet_received.length; i++) {
      my_packet[i] = (char)sx1278.packet_received.data[i];
    }
    check_BN=strcmp (message_check_BN,my_packet);
    check_YTA=strcmp (message_check_YTa,my_packet);
    if(check_BN==0){
      Serial.println(my_packet);
      analogWrite(Rung,127);
      digitalWrite(LED_BN,1);
      delay(3000);
      analogWrite(Rung,0);
    }
    if(check_YTA==0){
      Serial.println(my_packet);
      analogWrite(Rung,127);
      digitalWrite(LED_YT,1);
      delay(3000);
      analogWrite(Rung,0);
    }  
  }
      Serial.print("check_BN:");Serial.println(check_BN);
    Serial.print("check_YTA:");Serial.println(check_YTA);
    Serial.println(Timer_secs_Rung.value());
  if(check_BN==0){
    if(analogRead2(LORA_KEY_2)<=100)
    {
      digitalWrite(LED_BN,0);
      check_BN=1;
    }
  }
  if(check_YTA==0){
    if(analogRead2(LORA_KEY_1)<=100)
    {
      digitalWrite(LED_YT,0);
      check_YTA=1;
    }
  }


//  ///////////////////////////////
//  // 1. Get SNR
//  ///////////////////////////////  
//  e = sx1278.getSNR();
//
//  // check status
//  if( e == 0 ) 
//  {
//    Serial.print(F("Getting SNR \t\t--> OK. "));
//    Serial.print(F("SNR current value is: "));
//    Serial.println(sx1278._SNR);
//  }
//  else 
//  {
//    Serial.println(F("Getting SNR --> ERROR"));
//  } 
//
//  ///////////////////////////////
//  // 2. Get channel RSSI
//  ///////////////////////////////
//  e = sx1278.getRSSI();
//
//  // check status
//  if( e == 0 ) 
//  {
//    Serial.print(F("Getting RSSI \t\t--> OK. "));
//    Serial.print(F("RSSI current value is: "));
//    Serial.println(sx1278._RSSI);
//
//  }
//  else 
//  {
//    Serial.println(F("Getting RSSI --> ERROR"));
//  } 
//
//  ///////////////////////////////
//  // 3. Get last packet received RSSI
//  ///////////////////////////////
//  e = sx1278.getRSSIpacket();
//
//  // check status
//  if( e == 0 ) 
//  {
//    Serial.print(F("Getting RSSI packet \t--> OK. "));
//    Serial.print(F("Last packet RSSI value is: "));    
//    Serial.println(sx1278._RSSIpacket);
//  }
//  else 
//  {
//    Serial.println(F("Getting RSSI packet --> ERROR"));
//  } 
//  
}
int analogRead2(uint8_t pin)
{
  uint8_t low, high;

#if defined(analogPinToChannel)
#if defined(__AVR_ATmega32U4__)
  if (pin >= 18) pin -= 18; // allow for channel or pin numbers
#endif
  pin = analogPinToChannel(pin);
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
  if (pin >= 54) pin -= 54; // allow for channel or pin numbers
#elif defined(__AVR_ATmega32U4__)
  if (pin >= 18) pin -= 18; // allow for channel or pin numbers
#elif defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__)
  if (pin >= 24) pin -= 24; // allow for channel or pin numbers
#else
  if (pin >= 14) pin -= 14; // allow for channel or pin numbers
#endif

#if defined(ADCSRB) && defined(MUX5)
  // the MUX5 bit of ADCSRB selects whether we're reading from channels
  // 0 to 7 (MUX5 low) or 8 to 15 (MUX5 high).
  ADCSRB = (ADCSRB & ~(1 << MUX5)) | (((pin >> 3) & 0x01) << MUX5);
#endif
  
  // set the analog reference (high two bits of ADMUX) and select the
  // channel (low 4 bits).  this also sets ADLAR (left-adjust result)
  // to 0 (the default).
#if defined(ADMUX)
#if defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
  ADMUX = (analog_reference << 4) | (pin & 0x07);
#else
//  ADMUX = (analog_reference << 6) | (pin & 0x07);
  ADMUX = (0 << 6) | (pin & 0x07);
  ADMUX = ADMUX | 0xc0;
#endif
#endif

  // without a delay, we seem to read from the wrong channel
  //delay(1);

#if defined(ADCSRA) && defined(ADCL)
  // start the conversion
  sbi(ADCSRA, ADSC);

  // ADSC is cleared when the conversion finishes
  while (bit_is_set(ADCSRA, ADSC));

  // we have to read ADCL first; doing so locks both ADCL
  // and ADCH until ADCH is read.  reading ADCL second would
  // cause the results of each conversion to be discarded,
  // as ADCL and ADCH would be locked when it completed.
  low  = ADCL;
  high = ADCH;
#else
  // we dont have an ADC, return 0
  low  = 0;
  high = 0;
#endif

  // combine the two bytes
  return (high << 8) | low;
}
