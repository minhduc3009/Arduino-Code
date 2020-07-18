#include <FastCRC.h>

FastCRC16 CRC16;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  
}
double tmp=38.4;
uint8_t header='@';
uint8_t error=1;
uint8_t phase=1;
uint8_t tram;
uint8_t chuc;
uint8_t donvi;
uint8_t thapphan;
uint8_t data_send[10];
uint8_t data_reciver[10];
uint32_t crc;
uint32_t CRC;
int index=0;
int FLAG_DATA_START=0;
void loop() {
  tmp=tmp+0.7;
  if(tmp >=127) tmp=30.5;
  tram=tmp/100;
  chuc=(int)(tmp/10)%10;
  donvi=(int)(tmp)%10;
  thapphan=(int)(tmp*10) % 10;
  FN_Send_To_Master();
  CRC=CRC16.modbus(data_reciver,7);
  if(data_reciver[8]==(CRC & 0x00ff) && data_reciver[7]==((CRC>>8) & 0xff))
  {
    int nhietdo=data_reciver[3]*100+data_reciver[4]*10+data_reciver[5];
    int nhietdo_tp=data_reciver[6];
    Serial.print("NhietDo:=");Serial.print(nhietdo);Serial.print(",");Serial.println(nhietdo_tp);
  }
  else{
    Serial.println("ERROR");
    }
//  for(int j=0;j<8;j++)
//  {
//    Serial.write(data_reciver[j]);
//  }
 delay(2000);
}
void serialEvent() {
  while (Serial.available()) {
    char inChar =Serial.read();
//    Serial.write(inChar);
    if(inChar=='@')
    {
      index=0;
      FLAG_DATA_START = 1;
    }
    if(FLAG_DATA_START==1 && index < 8)
    {
      data_reciver[index]=inChar;
      index++;
    }
    if(index==8){
      FLAG_DATA_START=0;
      index=0;
    }
  }
}
void FN_Send_To_Master(){
    data_send[0]=header;
    data_send[1]=error;
    data_send[2]=phase;
    data_send[3]=tram;
    data_send[4]=chuc;
    data_send[5]=donvi;
    data_send[6]=thapphan;
    crc=CRC16.modbus(data_send,7);
    data_send[8]=(crc & 0x00ff);
    data_send[7]=((crc>>8) & 0xff);
    Serial1.write(data_send[0]);
    Serial1.write(data_send[1]);
    Serial1.write(data_send[2]);
    Serial1.write(data_send[3]);
    Serial1.write(data_send[4]);
    Serial1.write(data_send[5]);
    Serial1.write(data_send[6]);
    Serial1.write(data_send[7]);
    Serial1.write(data_send[8]);
//    Serial.print("crc:=");Serial.println(crc);
    
}

