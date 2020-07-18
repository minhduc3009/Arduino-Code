/*
  *  Use the I2C bus with EEPROM 24LC64
  *  Sketch:    eeprom.ino
  *  Test Write and Read EEPROM
  *  OK 08-05
  */

#include <Wire.h>

char data13[68];
char data[68];
unsigned long time;
unsigned long finishTime;
void setup()
{    
    Wire.begin(); // initialise the connection
    Serial.begin(9600);  
    for (char i = 1; i <= 64; ++i)
       data13[i-1]=i;
    time = micros();   
    i2c_eeprom_write_page(0x50, 0, (byte *)data13, 64);
//    i2c_eeprom_write_page_64(0x50, 0, (byte *)data13, 64);
    finishTime = micros() - time;
  Serial.println(finishTime);
  delay(5);
//    for (char i = 1; i <= 64; ++i)
//       data13[i-1]=2;
//    i2c_eeprom_write_page_64(0x50, 64, (byte *)data13, 64);
//    for (char i = 1; i <= 64; ++i)
//       data13[i-1]=3;
//    i2c_eeprom_write_page_64(0x50, 128, (byte *)data13, 64);
//    for (char i = 1; i <= 64; ++i)
//       data13[i-1]=4;
//    i2c_eeprom_write_page_64(0x50, 192, (byte *)data13, 64);
//    for (char i = 1; i <= 64; ++i)
//       data13[i-1]=5;
//    i2c_eeprom_write_page_64(0x50, 256, (byte *)data13, 64);
//    Serial.println("Memory written");
}

void loop()
{
    int addr=0; //first address
    
    time = micros(); 
    i2c_eeprom_read_buffer(0x50,0,data,64);
    finishTime = micros() - time;
    Serial.println(finishTime);
    for (char i = 0; i < 64; ++i)
       Serial.print((char)data[i]);


//    byte b = i2c_eeprom_read_byte(0x50, 0); // access the first address from the memory
//    time = micros(); 
//    while (b!=0)
//    {
//        Serial.println(b); //print content to serial port
//        addr++; //increase address
//        b = i2c_eeprom_read_byte(0x50, addr); //access an address from the memory
//    }
//    finishTime = micros() - time;
//    Serial.println(finishTime);
//    Serial.println(" ");
    while(1);
}
