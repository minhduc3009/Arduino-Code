void FN_Interrupt0(void)
{
   detachInterrupt(0);
}
void FN_Interrupt1(void)
{
  detachInterrupt(1);
  delay(100);
  buttonStateYT = analogRead2(LORA_KEY_YT);
  buttonStateBN = analogRead2(LORA_KEY_BN);
  Serial.println(buttonStateYT);
  Serial.println(buttonStateBN);
  if(buttonStateYT<=100){
    FLAG_CHECK_BT_YT=1;
    Serial.println("YT");
  }
  if(buttonStateBN<=100){
    FLAG_CHECK_BT_BN=1;
    Serial.println("BN");
  }
  
  attachInterrupt(1, FN_Interrupt1, LOW);
}
void enterSleep(void)
{
  sx1278.writeRegister(REG_OP_MODE, LORA_SLEEP_MODE);
//const uint8_t LORA_SLEEP_MODE = 0x80;
//const uint8_t LORA_STANDBY_MODE = 0x81;
//const uint8_t LORA_TX_MODE = 0x83;
//const uint8_t LORA_RX_MODE = 0x85;
  /* Setup pin2 as an interrupt and attach handler. */
  attachInterrupt(1, FN_Interrupt1, LOW);
  delay(100);

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);

  sleep_enable();

  sleep_mode();

  /* The program will continue from here. */

  /* First thing to do is disable sleep. */
  sleep_disable();
  sx1278.writeRegister(REG_OP_MODE, LORA_STANDBY_MODE);
}
