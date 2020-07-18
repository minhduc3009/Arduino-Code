/*
  Code by VirtueVu
  Arduino Due - TFT 5 Inch
*/
#include <UTFT.h> // Thư viện UTFT
#include <URTouch.h>
#define TOUCH_ORIENTATION  LANDSCAPE
UTFT myGLCD(EHOUSE50,38,39,40,41); 
URTouch  myTouch( 6, 5, 4, 3, 2);

#include <StopWatch.h> // Thư viện Timer Clock
StopWatch Timer_secs(StopWatch::SECONDS);
StopWatch Timer_secs_check_connect(StopWatch::SECONDS);
StopWatch Timer_secs_check_end(StopWatch::SECONDS);

#include <DueFlashStorage.h> // Thư viện Flash 
DueFlashStorage dueFlashStorage; //dueFlashStorage.write(0,a); dueFlashStorage.read(0);

//#include <FastCRC.h>// thư viện CRC
//FastCRC16 CRC16;

#include "setup.h" // thư viện Setup

//========================================================
void setup(){
  pinMode(42,OUTPUT);
  myGLCD.InitLCD();
//==LOGO=================================================
    myGLCD.fillScr(255, 255, 255);
    myGLCD.drawBitmap (220, 140, 130, 60, yuin, 3);
    FN_TONE(2);
    delay(4000);
//    while(1);
//===================================================
  myGLCD.clrScr();
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_HI);  
  Serial.begin(9600);
  Serial1.begin(9600);
  FN_Draw_Page_Menu();
  FN_READ_FLASHSTORE();


// FN_PAGE_ORIGIN();
//  FN_Draw_Page_Menu();
 // while(1){}
//    FN_Draw_Page_Select();delay(5000);
//    FN_Draw_TABLE_ERROR();delay(5000);
//    FN_Draw_Page_Setup();delay(5000);
//  }
}// end setup();
// void loop()
// {
// }
void loop()
{
    Timer_secs_check_connect.start();

    flag_count_connect= Timer_secs_check_connect.value();

//    if(flag_count_connect >=15) {
//      error=6;
//    }

    flag_check_end=Timer_secs_check_end.value();
    if(flag_check_end>=180){
        Timer_secs_check_end.stop();
        Timer_secs_check_end.reset();
        flag_check_end=0;
        phase=0;
    }
    if(flag_check_end>0){
        FN_TONE_ON();
        delay(100);
    }

    // Check lenh Stop tu mach duoi 
    if(flag_check_stop_cmd==1){

        FLAG_START_STOP=0;
        FLAG_STATE=0;// tắt

        myGLCD.setFont(GroteskBold24x48);
        myGLCD.setBackColor(255, 255,255 );  // nền sau của chữ
        myGLCD.setColor(0, 255, 0); // màu chữ
        myGLCD.print("START", 40, yy2+140);

        Timer_secs_check_end.stop();
        Timer_secs_check_end.reset();
        Timer_secs.stop();  
        Timer_secs.reset(); 

        flag_check_end=0;
        phase=0;
        data_reciver[2]=0;
        flag_check_stop_cmd=0;
        flag_check_timer=0;
        vr_select=vr_state_select;

    }
    //========= Data_Progress =========================================================================================
    FN_Data_Progress();
    //========= Unit Timer Count Down ==========================================================

    if(FLAG_STATE==1 && timer_minute_set < 255 && flag_check_timer==1){
      Timer_secs.start(); // Start timer giây

      int tmp_sec = 59 - Timer_secs.value()%60; // giây đếm lùi

      int tmp_min = timer_minute_set - (Timer_secs.value()/60) -1; // Phút lùi

      if( Timer_secs.value()/60 >= timer_minute_set ){ // Nếu đếm lùi về không thì dùng timer
        Timer_secs.stop();
        Timer_secs.reset();
        FLAG_STATE=0;
        flag_check_timer=0;
        phase=5;
      }

      if(tmp_min>=0 && tmp_sec>=0){
        if(tmp_min<10 && tmp_sec>=10){
            myGLCD.setFont(GroteskBold24x48);    
            myGLCD.setBackColor(VGA_WHITE);  // nền sau của chữ
            myGLCD.setColor(0, 0, 0); // màu chữ

            myGLCD.printNumI(0, x1+125, yy4+17);
            myGLCD.printNumI(tmp_min,x1+125+24*1, yy4+17);
            myGLCD.print(":",x1+125+24*2, yy4+17);
            myGLCD.printNumI(tmp_sec,x1+125+24*3, yy4+17);             
        }
        else if(tmp_min>=10 && tmp_sec>=10){
            myGLCD.setFont(GroteskBold24x48);    
            myGLCD.setBackColor(VGA_WHITE);  // nền sau của chữ
            myGLCD.setColor(0, 0, 0); // màu chữ

            myGLCD.printNumI(tmp_min,x1+125, yy4+17);
            myGLCD.print(":",x1+125+24*2, yy4+17);
            myGLCD.printNumI(tmp_sec,x1+125+24*3, yy4+17); 
        }
        else if(tmp_min<10 && tmp_sec<10){
            myGLCD.setFont(GroteskBold24x48);    
            myGLCD.setBackColor(VGA_WHITE);  // nền sau của chữ
            myGLCD.setColor(0, 0, 0); // màu chữ

            myGLCD.printNumI(0, x1+125, yy4+17);
            myGLCD.printNumI(tmp_min,x1+125+24*1, yy4+17);
            myGLCD.print(":",x1+125+24*2, yy4+17);
            myGLCD.printNumI(0, x1+125+24*3, yy4+17);
            myGLCD.printNumI(tmp_sec,x1+125+24*4, yy4+17);            
        }
        else if(tmp_min>=10 && tmp_sec<10){
            myGLCD.setFont(GroteskBold24x48);    
            myGLCD.setBackColor(VGA_WHITE);  // nền sau của chữ
            myGLCD.setColor(0, 0, 0); // màu chữ

            myGLCD.printNumI(tmp_min,x1+125, yy4+17);
            myGLCD.print(":",x1+125+24*2, yy4+17);
            myGLCD.printNumI(0, x1+125+24*3, yy4+17);
            myGLCD.printNumI(tmp_sec,x1+125+24*4, yy4+17);            
        }          
      }    
    }// end if(FLAG_STATE==1);
    else if(FLAG_STATE==0)
    {
      Timer_secs.stop();  
      Timer_secs.reset();
      // flag_check_timer=0; 
      // flag_check_stop_cmd=0;    
    }
    //=========Selec Function===========================================================
    switch(vr_select){
       case 1:// dao cat
         myGLCD.drawBitmap (x0+67, yy2+50, 64, 64, blue_cut, 1); 
         FN_Update(Vr_Cut_Tem,Vr_Cut_Timer,Vr_Cut_Exhaust);
         Timer_secs.reset();
         vr_state_select=1;dueFlashStorage.write(12,vr_state_select); 
         vr_select=7; 
         break;
       case 3:// dung dich
         myGLCD.drawBitmap (x0+67, yy2+50, 64, 64, dungdich, 1);
         FN_Update(Vr_DD_Tem,Vr_DD_Timer,Vr_DD_Exhaust);
         Timer_secs.reset();
         vr_state_select=3; dueFlashStorage.write(12,vr_state_select); 
         vr_select=7; 
         break;
       case 4:// vai
         myGLCD.drawBitmap (x0+67, yy2+50, 64, 64, vai, 1); 
         FN_Update(Vr_Vai_Tem,Vr_Vai_Timer,Vr_Vai_Exhaust);
         Timer_secs.reset();
         vr_state_select=4; dueFlashStorage.write(12,vr_state_select); 
         vr_select=7; 
         break;
       case 6://Khong Xac Dinh
         myGLCD.drawBitmap (x0+67, yy2+50, 64, 64, icon_setup, 1);
         FN_Update(Vr_Setup_Tem,Vr_Setup_Timer,Vr_Setup_Exhaust);
         Timer_secs.reset();
         vr_state_select=6;dueFlashStorage.write(12,vr_state_select); 
         vr_select=7;  
         break;
    } // end switch case'
    //======Unit Touch Scren ==============================================================
    if (myTouch.dataAvailable()){
          myTouch.read();
          m=myTouch.getX();
          n=myTouch.getY();

          if ((m>=x0) && (m<x1)) 
          {
             // =====Start-Stop==========================================
            if ((n>=yy2) && (n<yy4))  // START-STOP
            {
              waitForIt(x0, yy2, x1, yy4);FN_TONE(1);
              if(vr_select>0 && FLAG_START_STOP==1)
              {
                FLAG_START_STOP=0;

                FLAG_STATE=0;// tắt

                myGLCD.setFont(GroteskBold24x48);
                myGLCD.setBackColor(255, 255,255 );  // nền sau của chữ
                myGLCD.setColor(0, 255, 0); // màu chữ
                myGLCD.print("START", 40, yy2+140);

                FN_Send_Data(0);delay(100);FN_Send_Data(0);

                Timer_secs_check_end.stop();
                Timer_secs_check_end.reset();
                flag_check_end=0;
                phase=0;
                flag_check_timer=0; 
                flag_check_stop_cmd=0;data_reciver[2]=0;
                vr_select=vr_state_select;
                // FN_TONE(3);
              }
              else if(vr_select>0&& FLAG_START_STOP==0)
              {

                FLAG_STATE=1; // hoạt động

                FLAG_START_STOP=1;

                myGLCD.setColor(255,255,255); // nền của khung 
                myGLCD.fillRoundRect(x0+20, yy2+140, x1-20, yy2+140 +49);
                myGLCD.setFont(GroteskBold24x48);
                myGLCD.setBackColor(255, 255,255 );  // 
                myGLCD.setColor(255, 0, 0); // 
                myGLCD.print("STOP ", 50, yy2+140);

                FN_Send_Data(1);delay(100);FN_Send_Data(1);
                FN_TONE(3);
                flag_check_timer=0; 
                flag_check_stop_cmd=0;data_reciver[2]=0;
                vr_select=vr_state_select;

              }
            }
            // ===== SETUP ==========================================
            if ((n>=yy4) && (n<yy6) && FLAG_STATE!=1)  // Function Setup
            {
               waitForIt(x0, yy4, x1, yy6);FN_TONE(1);
               FN_PAGE_SELECT();
            }
          }// end if
          // =====Running+Mode==========================================
          if((m>=x1) && (m<x2))
          {
              if ((n>=yy3+1+4) && (n<yy5)) // Function Mode
              {
                FN_TONE(1);
                // waitForIt(x1, yy3+1+4, x2, yy5);
              }
          }//end IF
          // ===== SETTING TEMP TIME EXHAUST ============================
          if((m>=x2) && (m<x3))
          {
            index_digit=0;
            // x=y=z=t=0;
            // vr_time_1=vr_time_2=0;
            // vr_exhaust_1=vr_exhaust_1=0;
            // ===== SETTING TEMP ============================
              if ((n>=170) && (n<170+40) && FLAG_STATE!=1) // TEMP
              {
                FN_TONE(1);
                F_Page_Set_Temp_Time_Ex=0;
                FN_Control_Page_Setup2();    
                FN_Draw_Page_Menu();
                myGLCD.setColor(255,255,255); // nền của khung 
                myGLCD.fillRoundRect(x0+1+4, yy2+1+4, x1-1-4, yy4-1-4);
                myGLCD.setFont(GroteskBold24x48);
                myGLCD.setBackColor(255, 255,255 );  // nền sau của chữ
                myGLCD.setColor(0, 255, 0); // màu chữ
                myGLCD.print("START", 40, yy2+140);  
              }
              // ===== SETTING  TIME  ============================
              if ((n>=270) && (n<270+40) && FLAG_STATE!=1) // TIME
              {
                FN_TONE(1);
                F_Page_Set_Temp_Time_Ex=1;
                FN_Control_Page_Setup2();     
                FN_Draw_Page_Menu();
                myGLCD.setColor(255,255,255); // nền của khung 
                myGLCD.fillRoundRect(x0+1+4, yy2+1+4, x1-1-4, yy4-1-4);
                myGLCD.setFont(GroteskBold24x48);
                myGLCD.setBackColor(255, 255,255 );  // nền sau của chữ
                myGLCD.setColor(0, 255, 0); // màu chữ
                myGLCD.print("START", 40, yy2+140);            
              }
              // ===== SETTING EXHAUST ============================
              if ((n>=370) && (n<370+40) && FLAG_STATE!=1) // EXHAUST
              {
                FN_TONE(1);
                F_Page_Set_Temp_Time_Ex=2;
                FN_Control_Page_Setup2(); 
                FN_Draw_Page_Menu();
                myGLCD.setColor(255,255,255); // nền của khung 
                myGLCD.fillRoundRect(x0+1+4, yy2+1+4, x1-1-4, yy4-1-4);
                myGLCD.setFont(GroteskBold24x48);
                myGLCD.setBackColor(255, 255,255 );  // nền sau của chữ
                myGLCD.setColor(0, 255, 0); // màu chữ
                myGLCD.print("START", 40, yy2+140);                
              }
              // ===== SETTING FOOTER ============================                          
              if ((n>=430) && (n<480) && FLAG_STATE!=1 ) {// Footer Origin
                FN_TONE(1);
                FN_PAGE_ORIGIN();
              }
          }//end IF

          Serial.print("m:=");Serial.println(m);
          Serial.print("n:=");Serial.println(n);
          Serial.print("FLAG_START_STOP:=");Serial.println(FLAG_START_STOP);
          Serial.print("FLAG_STATE:=");Serial.println(FLAG_STATE);
          Serial.print("flag_check_timer:=");Serial.println(flag_check_timer);
          Serial.print("flag_check_stop_cmd:=");Serial.println(flag_check_stop_cmd);
      }//end touch
}// end loop

void waitForIt(int x1, int y1, int x2, int y2)
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  while (myTouch.dataAvailable())
  myTouch.read();
  myGLCD.setColor(0, 0, 0);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
}
void FN_Update(int m,int n,int p)
{
    timer_minute_set = n;

    myGLCD.setColor(VGA_NAVY);
    myGLCD.fillRoundRect(x2+40,170,x2+40+24*3,170+32);// temp
    myGLCD.fillRoundRect(x2+40,270,x2+40+24*5,270+32);// time
    myGLCD.fillRoundRect(x2+40,370,x2+40+24*3,370+32);// exhaust

    myGLCD.setFont(Ubuntu);
    myGLCD.setBackColor(VGA_NAVY );  // nền sau của chữ

    myGLCD.setColor(VGA_RED); // màu chữ
    myGLCD.printNumI(m,x2+40,130+40);

     myGLCD.setColor(VGA_GREEN);
     myGLCD.printNumI(n,x2+40, 230+40);
     myGLCD.print(":00",x2+40+24*2, 230+40);

    myGLCD.setColor(VGA_OLIVE);
    myGLCD.printNumI(p,x2+40, 330+40);

    myGLCD.setFont(GroteskBold24x48);    
    myGLCD.setBackColor(VGA_WHITE);  // nền sau của chữ
    myGLCD.setColor(0, 0, 0); // màu chữ

    myGLCD.printNumI(n, x1+125, yy4+17);
    myGLCD.print(":00",x1+125+24*2, yy4+17);

}
void FN_Data_Progress(){
    // data_send[0]=header;
    // data_send[1]=error;
    // data_send[2]=phase;
    // data_send[3]=tram;
    // data_send[4]=chuc;
    // data_send[5]=donvi;
    // data_send[6]=thapphan;
    // crc=CRC16.modbus(data_send,7);
    // data_send[8]=(crc & 0x00ff);
    // data_send[7]=((crc>>8) & 0xff);

    // data_send[0]=header;
    // data_send[1]=state; 0 - 1 - 2
    // data_send[2]=exhaust;
    // data_send[3]=tram;
    // data_send[4]=chuc;
    // data_send[5]=donvi;
    // data_send[6]=thapphan;
    // crc=CRC16.modbus(data_send,7);
    // data_send[8]=(crc & 0x00ff);
    // data_send[7]=((crc>>8) & 0xff);

  // Tinh CRC
//    CRC=CRC16.modbus(data_reciver,7);
    // so sanh CRC
    if(data_reciver[8]==(CRC & 0x00ff) && data_reciver[7]==((CRC>>8) & 0xff))
    {
      // Tach dữ liệu nhiệt độ
      data_nhietdo=data_reciver[3]*100+data_reciver[4]*10+data_reciver[5];
      data_nhietdo_tp=data_reciver[6];
      // Serial.print("NhietDo:=");Serial.print(data_nhietdo);Serial.print(",");Serial.println(data_nhietdo_tp);
      // Tách dữ liệu lỗi 
      error=data_reciver[1];
      // Tách dữ liệu phase
      phase=data_reciver[2];
      /*****************************************************************************/
      // Update nhiet do
      if(data_nhietdo<100)
      {
         myGLCD.setColor(VGA_WHITE);
         myGLCD.fillRoundRect(x1+1+5, yy1+75, 225+64, yy1+75+100);// Nhietdo
         myGLCD.setFont(SevenSeg_XXXL_Num);    
         myGLCD.setBackColor(VGA_WHITE );  // nền sau của chữ
         myGLCD.setColor(VGA_RED); // màu chữ
         myGLCD.printNumI(data_nhietdo, 225+64, yy1+75);
         myGLCD.printNumI(data_nhietdo_tp, 200+64*4, yy1+75);
         myGLCD.setFont(GroteskBold24x48);
         myGLCD.print(",", 225+64*3, yy1+75+80);
         myGLCD.print("o", 200+64*5, yy1+75);
         myGLCD.print("C", 200+64*6-35, yy1+75);
      }
      else if(data_nhietdo>=100 && data_nhietdo <999){
       // myGLCD.setColor(VGA_WHITE);
       // myGLCD.fillRoundRect(x1+1+5, yy1+75, 225+64, yy1+75+100);// Nhietdo
       myGLCD.setFont(SevenSeg_XXXL_Num);    
       myGLCD.setBackColor(VGA_WHITE );  // nền sau của chữ
       myGLCD.setColor(VGA_RED); // màu chữ
       myGLCD.printNumI(data_nhietdo, 225, yy1+75);
       myGLCD.printNumI(data_nhietdo_tp, 200+64*4, yy1+75);
       myGLCD.setFont(GroteskBold24x48);
       myGLCD.print(",", 225+64*3, yy1+75+80);
       myGLCD.print("o", 200+64*5, yy1+75);
       myGLCD.print("C", 200+64*6-35, yy1+75);
      }
      else {};

        Timer_secs_check_connect.stop();   
        Timer_secs_check_connect.reset();  
        flag_count_connect=0;

    }// end if check crc
    else{
      Serial.println("ERROR");
      }
            /*****************************************************************************/
      // Update error
      if(error==0)
      {
        myGLCD.setFont(BigFont);    
        myGLCD.setBackColor(VGA_GRAY);  // nền sau của chữ
        myGLCD.setColor(0, 0, 255); // màu chữ
        myGLCD.print("Status:", x1+15, yy4+135);//yy4+1+4+51
        myGLCD.setColor(VGA_GREEN);
        myGLCD.print("Ready            ", x1+15+16*7, yy4+135);
      }
      else
      {   
          FN_TONE_ON();
          delay(80);
          FN_TONE_OFF();
          delay(80);
          FN_CHECK_ERROR();
      }
      /*****************************************************************************/
      // Update phase
      if(phase==0)
      {
        myGLCD.setFont(BigFont);    
        myGLCD.setBackColor(VGA_GRAY);  // nền sau của chữ
        myGLCD.setColor(0, 0, 255); // màu chữ
        myGLCD.print("Phase:", x1+15, yy4+90);//yy4+1+4+51
        myGLCD.setColor(0, 0, 255);
        myGLCD.print("Stop           ", x1+15+16*6, yy4+90);
      }
      else
      {
          FN_CHECK_PHASE();
      }



    //   
}
void serialEvent1(){
  while (Serial1.available()) {
    char inChar =Serial1.read();
//    Serial1.write(inChar);
    if(inChar=='@')
    {
      index_data_reciver=0;
      FLAG_DATA_START = 1;
    }
    if(FLAG_DATA_START==1 && index_data_reciver < 9)
    {
      data_reciver[index_data_reciver]=inChar;
      index_data_reciver++;
    }
    if(index_data_reciver==9){
      FLAG_DATA_START=0;
      index_data_reciver=0;
    }
  }
}
void FN_TONE(uint8_t tt)
{
 for(int e=0;e<tt;e++)
 {
  digitalWrite(42,HIGH);
  delay(80);
  digitalWrite(42,LOW);
  delay(80);
 }
}
void FN_TONE_ON()
{
  digitalWrite(42,HIGH);
}
void FN_TONE_OFF()
{
  digitalWrite(42,LOW);
}
void FN_READ_FLASHSTORE()
{
  Vr_Cut_Tem=dueFlashStorage.read(0);
  Vr_Cut_Timer=dueFlashStorage.read(1);
  Vr_Cut_Exhaust=dueFlashStorage.read(2);
  Vr_DD_Tem=dueFlashStorage.read(3);
  Vr_DD_Timer=dueFlashStorage.read(4);
  Vr_DD_Exhaust=dueFlashStorage.read(5); 
  Vr_Vai_Tem=dueFlashStorage.read(6);
  Vr_Vai_Timer=dueFlashStorage.read(7);
  Vr_Vai_Exhaust=dueFlashStorage.read(8); 
  Vr_Setup_Tem=dueFlashStorage.read(9);
  Vr_Setup_Timer=dueFlashStorage.read(10);
  Vr_Setup_Exhaust=dueFlashStorage.read(11); 

  vr_select=dueFlashStorage.read(12); 
}
void FN_CHECK_ERROR(){
  switch (error) {
      case 1:
          myGLCD.setFont(BigFont);    
          myGLCD.setBackColor(VGA_GRAY);  // nền sau của chữ
          myGLCD.setColor(VGA_RED); // màu chữ
          myGLCD.print("Error:Overheating", x1+15, yy4+135);//yy4+1+4+51
        break;
      case 2:
          myGLCD.setFont(BigFont);    
          myGLCD.setBackColor(VGA_GRAY);  // nền sau của chữ
          myGLCD.setColor(VGA_RED); // màu chữ
          myGLCD.print("Error:Door Open  ", x1+15, yy4+135);//yy4+1+4+51
        break;
      case 3:
          myGLCD.setFont(BigFont);    
          myGLCD.setBackColor(VGA_GRAY);  // nền sau của chữ
          myGLCD.setColor(VGA_RED); // màu chữ
          myGLCD.print("Error:Valve      ", x1+15, yy4+135);//yy4+1+4+51
        break;
      case 4:
          myGLCD.setFont(BigFont);    
          myGLCD.setBackColor(VGA_GRAY);  // nền sau của chữ
          myGLCD.setColor(VGA_RED); // màu chữ
          myGLCD.print("Error:Sensor RTD ", x1+15, yy4+135);//yy4+1+4+51
        break;
      case 5:
          myGLCD.setFont(BigFont);    
          myGLCD.setBackColor(VGA_GRAY);  // nền sau của chữ
          myGLCD.setColor(VGA_RED); // màu chữ
          myGLCD.print("Error:Water      ", x1+15, yy4+135);//yy4+1+4+51
        break;
      case 6:
          myGLCD.setFont(BigFont);    
          myGLCD.setBackColor(VGA_GRAY);  // nền sau của chữ
          myGLCD.setColor(VGA_RED); // màu chữ
          myGLCD.print("Error:Connect    ", x1+15, yy4+135);//yy4+1+4+51
        break;                
  }

}
void FN_CHECK_PHASE(){
  switch (phase){
      case 1:
          myGLCD.setFont(BigFont);    
          myGLCD.setBackColor(VGA_GRAY);  // nền sau của chữ
          myGLCD.setColor(0, 0, 255); // màu chữ
          myGLCD.print("Phase:", x1+15, yy4+90);//yy4+1+4+51
          myGLCD.setColor(0, 0, 255);
          myGLCD.print("Heating & Purge", x1+15+16*6, yy4+90);
        break;
      case 2:
          myGLCD.setFont(BigFont);    
          myGLCD.setBackColor(VGA_GRAY);  // nền sau của chữ
          myGLCD.setColor(0, 0, 255); // màu chữ
          myGLCD.print("Phase:", x1+15, yy4+90);//yy4+1+4+51
          myGLCD.setColor(0, 0, 255);
          myGLCD.print("Heating        ", x1+15+16*6, yy4+90);
        break;
      case 3:
          myGLCD.setFont(BigFont);    
          myGLCD.setBackColor(VGA_GRAY);  // nền sau của chữ
          myGLCD.setColor(0, 0, 255); // màu chữ
          myGLCD.print("Phase:", x1+15, yy4+90);//yy4+1+4+51
          myGLCD.setColor(0, 0, 255);
          myGLCD.print("Steerilization ", x1+15+16*6, yy4+90);
        break;
      case 4:
          myGLCD.setFont(BigFont);    
          myGLCD.setBackColor(VGA_GRAY);  // nền sau của chữ
          myGLCD.setColor(0, 0, 255); // màu chữ
          myGLCD.print("Phase:", x1+15, yy4+90);//yy4+1+4+51
          myGLCD.setColor(0, 0, 255);
          myGLCD.print("Exhaust        ", x1+15+16*6, yy4+90);
        break;
      case 5:
          myGLCD.setFont(BigFont);    
          myGLCD.setBackColor(VGA_GRAY);  // nền sau của chữ
          myGLCD.setColor(0, 0, 255); // màu chữ
          myGLCD.print("Phase:", x1+15, yy4+90);//yy4+1+4+51
          myGLCD.setColor(0, 0, 255);
          myGLCD.print("End            ", x1+15+16*6, yy4+90);
          // khoi tao timer
          Timer_secs_check_end.start();
        break;
        case 6: // Cho phep dem timer
          flag_check_timer=1;
          break; 
        case 7: // Lenh Stop
          flag_check_stop_cmd=1;
          break;           
  }
}
void FN_Send_Data(uint8_t state_data)
{
  uint8_t tram_data;
  uint8_t chuc_data;
  uint8_t donvi_data;
  uint8_t thapphan_data;
  uint8_t exhaust_data;
  uint8_t Nhietdo_data;

  switch (vr_state_select) {
     case 1:
              Nhietdo_data=Vr_Cut_Tem;
              exhaust_data = Vr_Cut_Exhaust; 
       break;
     case 3:
              Nhietdo_data=Vr_DD_Tem;
              exhaust_data = Vr_DD_Exhaust;                                                  
       break;
     case 4:
              Nhietdo_data=Vr_Vai_Tem;
              exhaust_data = Vr_Vai_Exhaust;                                            
       break;
     case 6:
             Nhietdo_data=Vr_Setup_Tem;
            exhaust_data = Vr_Setup_Exhaust;                                          
       break;                   
  }


            tram_data=Nhietdo_data/100;
            chuc_data=(int)(Nhietdo_data/10)%10;
            donvi_data=(int)(Nhietdo_data)%10;
            thapphan_data=(int)(Nhietdo_data*10) % 10;

            data_send[0]=header;
            data_send[1]=state_data;
            data_send[2]=exhaust_data;
            data_send[3]=tram_data;
            data_send[4]=chuc_data;
            data_send[5]=donvi_data;
            data_send[6]=thapphan_data;

//            crc=CRC16.modbus(data_send,7);
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
}











