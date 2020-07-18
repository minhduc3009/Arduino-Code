//void FN_Interrupt0(void)
//{
//   detachInterrupt(0);
//   Serial.println("-OK Ngat 00000-");
//   attachInterrupt(0, FN_Interrupt0, HIGH);
//}
//void FN_Interrupt1(void)
//{
//  detachInterrupt(1);
//  buttonStateYT = analogRead2(LORA_KEY_YT);
//  buttonStateBN = analogRead2(LORA_KEY_BN);
//  Serial.println(buttonStateYT);
//  Serial.println(buttonStateBN);
//  if(buttonStateYT<=100){
//    FLAG_CHECK_BT_YT=1;
//    Serial.println("YT");
//  }
//  if(buttonStateBN<=100){
//    FLAG_CHECK_BT_BN=1;
//    Serial.println("BN");
//  }
//  
//  attachInterrupt(1, FN_Interrupt1, LOW);
//}
//void enterSleep(void)
//{
//
//  /* Setup pin2 as an interrupt and attach handler. */
//  attachInterrupt(1, FN_Interrupt1, LOW);
//  delay(100);
//
//  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
//
//  sleep_enable();
//
//  sleep_mode();
//
//  /* The program will continue from here. */
//
//  /* First thing to do is disable sleep. */
//  sleep_disable();
//}
