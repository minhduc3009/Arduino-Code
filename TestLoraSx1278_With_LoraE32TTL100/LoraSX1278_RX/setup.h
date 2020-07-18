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
#define LORA_ADDRESS 8 //7,8,9
#define LORA_SEND_TO_ADDRESS_NG_NHA  8
#define LORA_SEND_TO_ADDRESS_Y_TA  2
#define LORA_KEY_YT A4
#define LORA_KEY_BN A5
#define LED_BATT A1
#define LED_YT A2
#define LED_BN A3
#define VBAT A0
#define Rung  5
#define PO_RF  4
#define int0_wakeup  2
#define int1_wakeup  3

int buttonStateYT = 0;
int buttonStateBN = 0;
uint8_t e;
char my_packet[20];
char my_packet_send_mega[20];
char message1 [] = "Benh Nhan:05";
char message2 [] = "YTa";

char message_check_BN [] =  "Benh Nhan:05";
char message_check_YTa [3] = {3,2,5};

float v_bat;

uint8_t FLAG_CHECK_BT_YT=0;
uint8_t FLAG_CHECK_BT_BN=0;




