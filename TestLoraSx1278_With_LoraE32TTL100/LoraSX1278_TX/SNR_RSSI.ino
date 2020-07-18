void FN_GET_SNR_RSSI(void)
{
  int e_check=0;
  ///////////////////////////////
  // 1. Get SNR
  ///////////////////////////////
  e_check = sx1278.getSNR();

  // check status
  if( e_check == 0 )
  {
    Serial.print(F("Getting SNR \t\t--> OK. "));
    Serial.print(F("SNR current value is: "));
    Serial.println(sx1278._SNR);
  }
  else
  {
    Serial.println(F("Getting SNR --> ERROR"));
  }

  ///////////////////////////////
  // 2. Get channel RSSI
  ///////////////////////////////
  e_check = sx1278.getRSSI();

  // check status
  if( e_check == 0 )
  {
    Serial.print(F("Getting RSSI \t\t--> OK. "));
    Serial.print(F("RSSI current value is: "));
    Serial.println(sx1278._RSSI);

  }
  else
  {
    Serial.println(F("Getting RSSI --> ERROR"));
  }

  ///////////////////////////////
  // 3. Get last packet received RSSI
  ///////////////////////////////
  e_check = sx1278.getRSSIpacket();

  // check status
  if( e_check == 0 )
  {
    Serial.print(F("Getting RSSI packet \t--> OK. "));
    Serial.print(F("Last packet RSSI value is: "));
    Serial.println(sx1278._RSSIpacket);
  }
  else
  {
    Serial.println(F("Getting RSSI packet --> ERROR"));
  }
}
