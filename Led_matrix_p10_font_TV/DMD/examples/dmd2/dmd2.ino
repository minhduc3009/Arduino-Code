#include <SPI.h>
#include <TimerOne.h>
#include <DMD.h>
#include <SystemFont5x7.h>
#include <tiengviet.h>
#include <EEPROM.h>

//Fire up the DMD library as dmd
#define DISPLAYS_ACROSS 2
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

boolean stringComplete = false;  // whether the string is complete
char mang[256];
int i,t,dem;
unsigned char test;
int tiengviet,flagmode;
unsigned char mang2[256],Readout[200],ReadoutScrool[200],ReadoutNormal[200];
unsigned char Mode1Line1_1[10],Mode1Line1_2[10],Mode1Line1_3[10],Mode1Line1_4[10],Mode1Line1_5[10];
unsigned char Mode1Line2_1[10],Mode1Line2_2[10],Mode1Line2_3[10],Mode1Line2_4[10],Mode1Line2_5[10];

int kyhieu=32; // dau cach 

void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
}

void setup(void)
{

   //initialize TimerOne's interrupt/CPU usage used to scan and refresh the display
   Timer1.initialize( 5000 );           //period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.
   Timer1.attachInterrupt( ScanDMD );   //attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()

   //clear/init the DMD pixels held in RAM
   dmd.clearScreen( true );   //true is normal (all pixels off), false is negative (all pixels on)
   
   
   Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly  
  
  if (stringComplete) {
//    Serial.println(mang2);
//    Serial.println("-----------------");
    for(t=0;t<200;t++)
    {    
      EEPROM.write(t,0);
    }
    
    for(t=0;t<200;t++)
    {
      EEPROM.write(t,mang2[t]);
      if(mang2[t]==13)t=209;
    }
    
    for(t=0;t<200;t++)
    {
      mang[t]=EEPROM.read(t);
      if(EEPROM.read(t)==13)t=209;
    }
  //  Serial.println(mang);
    // clear
    for(t=0;t<200;t++)
    {
      mang[t]=0;
      mang2[t]=0;
    }
    
    Readdata();
    t=0;
    stringComplete = false;
  }
  
  // lay du lieu ban dau.
  
   Readdata();
  
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte 
    test= Serial.read(); 
  
  // xử lý code tiếng việt tại đây.
    if(test == 1) // Rx = 0x01
    {
      tiengviet = 1;
      test=0;
    }
    
    if(test == 30)      // Rx = 0x1E
    {
      tiengviet = 2;
      test=0;
    }
    // 0X01
    if(tiengviet == 1)
      {
        if(test == 3) test = 199;
        if(test == 2) test = 132;
        if(test == 16) test = 144;
        if(test == 17) test = 211;
        if(test == 41) test = 226;
        if(test == 40) test = 159;
        if(test == 105) test = 248;
        if(test == 104) test = 181;
        if(test == 161) test = 239;
        if(test == 160) test = 172;
        if(test == 176) test = 250;
        if(test == 175) test = 183;
      }
    // 0X1E
    if(tiengviet == 2) // ;tiengviet == 2
       {
            if(test == 160 && tiengviet == 2)        {test = 129;tiengviet =3;}     // Ạ
            if(test == 161 && tiengviet == 2)        {test = 196;tiengviet =3;}       // ạ
            if(test == 183 && tiengviet == 2)        {test = 202;tiengviet =3;}       //  ặ loi Ị
            if(test == 182 && tiengviet == 2)        {test = 135;  tiengviet =3;}     //  Ă
            if( test ==  173 && tiengviet == 2)      {test = 208; tiengviet =3;}      // ậ
            if( test ==  172 && tiengviet == 2)      {test = 141;  tiengviet =3;}     // Ậ
            if( test ==  185 && tiengviet == 2)      {test = 214;  tiengviet =3;}     // ẹ
            if( test ==  184 && tiengviet == 2)      {test = 147;  tiengviet =3;}     // Ẹ
            if( test ==  199 && tiengviet == 2)      {test = 220;  tiengviet =3;}    // ệ
            if( test ==  198 && tiengviet == 2)      {test = 153;  tiengviet =3;}     // Ệ
            if( test ==  203 && tiengviet == 2)      {test = 225; tiengviet =3;}      // ị
            if( test ==  202 && tiengviet == 2)      {test = 158; tiengviet =3;}      // Ị
            if( test ==  205 && tiengviet == 2)      {test = 230; tiengviet =3;}      // ọ
            if( test ==  204 && tiengviet == 2)      {test = 163; tiengviet =3;}      // Ọ
            if( test ==  217 && tiengviet == 2)      {test = 236; tiengviet =3;}      // ộ
            if( test ==  216 && tiengviet == 2)      {test = 169; tiengviet =3;}      // Ộ
            if( test ==  227 && tiengviet == 2)      {test = 242;  tiengviet =3;}     // ợ
            if( test ==  226 && tiengviet == 2)      {test = 175; tiengviet =3;}      // Ợ
            if( test ==  229 && tiengviet == 2)      {test = 247; tiengviet =3;}      // ụ
            if( test ==  228 && tiengviet == 2)      {test = 180; tiengviet =3;}      // Ụ
            if( test ==  241 && tiengviet == 2)      {test = 253; tiengviet =3;}      // ự
            if( test ==  240 && tiengviet == 2)      {test = 186; tiengviet =3;}      // Ự
            if( test ==  245 && tiengviet == 2)      {test = 29; tiengviet =3;}      // ỵ
            if( test ==  244 && tiengviet == 2)      {test = 191;tiengviet =3;}       // Ỵ
            
            if(test == 181  && tiengviet == 2)      {test = 203;tiengviet =3;}       // ẵ
            if(test == 180  && tiengviet == 2)      {test = 136;tiengviet =3;}        // Ẵ
            if(test == 171 && tiengviet == 2)       {test = 209;tiengviet =3;}        // ẫ
            if(test == 170  && tiengviet == 2)      {test = 142;tiengviet =3;}        // Ẫ
            if(test == 189 && tiengviet == 2)       {test = 215; tiengviet =3;}       // ẽ    // lỗi ỗ
            if(test == 188  && tiengviet == 2)      {test = 148;tiengviet =3;}        // Ễ
            if(test == 197  && tiengviet == 2)      {test = 221;tiengviet =3;}        // ễ
            if(test == 196  && tiengviet == 2)      {test = 154;tiengviet =3;}        // Ễ
            if(test == 215  && tiengviet == 2)      {test = 237;tiengviet =3;}        // ỗ
            if(test == 214  && tiengviet == 2)      {test = 170;tiengviet =3;}        // Ỗ
            if(test == 225  && tiengviet == 2)      {test = 243;tiengviet =3;}        // ỡ
            if(test == 224  && tiengviet == 2)       {test = 176;tiengviet =3;}        // Ỡ
            if(test == 239  && tiengviet == 2)      {test = 254;tiengviet =3;}        // ữ
            if(test == 238  && tiengviet == 2)      {test = 187;tiengviet =3;}        // Ữ
            if(test == 249  && tiengviet == 2)      {test = 30;tiengviet =3;}        // ỹ
            if(test == 248  && tiengviet == 2)      {test = 192;tiengviet =3;}        // Ỹ
            
            if(test == 177  && tiengviet == 2)      {test = 200;tiengviet =3;}         // ằ
            if(test == 176  && tiengviet == 2)      {test = 133;tiengviet =3;}         // Ằ
            if(test == 167 && tiengviet == 2)       {test = 206;tiengviet =3;}         // ầ
            if(test == 166  && tiengviet == 2)      {test = 139;tiengviet =3;}         // Ầ
            if(test == 193  && tiengviet == 2)      {test = 218;tiengviet =3;}         // ề
            if(test == 192  && tiengviet == 2)      {test = 151;tiengviet =3;}         // Ề
            if(test == 211  && tiengviet == 2)      {test = 234;tiengviet =3;}         // ồ  LỖI Ừ
            if(test == 210  && tiengviet == 2)      {test = 167;tiengviet =3;}         // Ồ
            if(test == 221  && tiengviet == 2)      {test = 240;tiengviet =3;}        // ờ
            if(test == 220  && tiengviet == 2)      {test = 173;tiengviet =3;}         // Ờ
            if(test == 235  && tiengviet == 2)      {test = 251;tiengviet =3;}         // ừ
            if(test == 234  && tiengviet == 2)      {test = 184;tiengviet =3;}         // Ừ
            if(test == 243  && tiengviet == 2)      {test = 27;tiengviet =3;}         // ỳ
            if(test == 242  && tiengviet == 2)      {test = 189;tiengviet =3;}         // Ỳ
            
             if(test == 175 && tiengviet == 2 )      {test = 201;tiengviet =3;}         // ắ
             if(test == 174  && tiengviet == 2)      {test = 134;tiengviet =3;}         // Ắ
             if(test == 165  && tiengviet == 2)      {test = 207;tiengviet =3;}        // ấ
             if(test == 164  && tiengviet == 2)      {test = 140;tiengviet =3;}         // Ấ
             if(test == 191  && tiengviet == 2)      {test = 219; tiengviet =3;}         // ế    LỖI ớ
             if(test == 190  && tiengviet == 2)      {test = 152;tiengviet =3;}         // Ế
             if(test == 209  && tiengviet == 2)      {test = 235;tiengviet =3;}         // ố
             if(test == 208  && tiengviet == 2)      {test = 168;tiengviet =3;}         // Ố
             if(test == 219  && tiengviet == 2)      {test = 241;tiengviet =3;}         // ớ
             if(test == 218  && tiengviet == 2)      {test = 174;tiengviet =3;}         // Ớ
             if(test == 233  && tiengviet == 2)      {test = 252;tiengviet =3;}         // ứ
             if(test == 232  && tiengviet == 2)      {test = 185;tiengviet =3;}         // Ứ
            
             if(test == 163  && tiengviet == 2)     {test = 198;tiengviet =3;}       // ả
             if(test == 162  && tiengviet == 2)     {test = 131;tiengviet =3;}        // Ả
             if(test == 179  && tiengviet == 2)     {test = 204;tiengviet =3;}        // ẳ
             if(test == 178 && tiengviet == 2 )     {test = 137;tiengviet =3;}        // Ằ
             if(test == 169  && tiengviet == 2)     {test = 210;tiengviet =3;}        // ẩ
             if(test == 168  && tiengviet == 2)     {test = 143;tiengviet =3;}        // Ẩ
             if(test == 187  && tiengviet == 2)     {test = 216;tiengviet =3;}        // ẻ
             if(test == 186  && tiengviet == 2)     {test = 149;tiengviet =3;}        // Ẻ
             if(test == 195  && tiengviet == 2)     {test = 222;tiengviet =3;}        // ể LỖI Ở
             if(test == 194  && tiengviet == 2)     {test = 155;tiengviet =3;}        // Ể
             if(test == 201  && tiengviet == 2)     {test = 227;tiengviet =3;}        // ỉ
             if(test == 200  && tiengviet == 2)     {test = 160;tiengviet =3;}        // Ỉ
             if(test == 207  && tiengviet == 2)     {test = 232;tiengviet =3;}        // ỏ
             if(test == 206  && tiengviet == 2)     {test = 165;tiengviet =3;}        // Ỏ
             if(test == 213  && tiengviet == 2)     {test = 238;tiengviet =3;}        // ổ
             if(test == 212  && tiengviet == 2)     {test = 171;tiengviet =3;}        // Ổ
             if(test == 223  && tiengviet == 2)     {test = 244;tiengviet =3;}        // ở
             if(test == 222  && tiengviet == 2)     {test = 177;tiengviet =3;}        // Ở
             if(test == 231  && tiengviet == 2)     {test = 249;tiengviet =3;}        // ủ
             if(test == 230  && tiengviet == 2)     {test = 182;tiengviet =3;}        // Ủ
             if(test == 237  && tiengviet == 2)     {test = 255;tiengviet =3;}        // ử
             if(test == 236  && tiengviet == 2)     {test = 188;tiengviet =3;}        // Ử
             if(test == 247  && tiengviet == 2)     {test =  31;tiengviet =3;}        // ỷ
             if(test == 246  && tiengviet == 2)     {test = 193;tiengviet =3;}        // Ỷ
       } 
   
    if(test == 226 && tiengviet == 0 ) { test = 205  ; tiengviet =3;}    // â    LỖI Í
    if(test == 194 && tiengviet == 0 ) test = 138  ;    // Â
    if(test == 234 && tiengviet == 0 ) { test = 217  ; tiengviet =3;}    // ê    LỖI Ù
    if(test == 202 && tiengviet == 0 ) test = 150  ;    // Ê
    if(test == 244 && tiengviet == 0 ) { test = 233  ; tiengviet =3;}  // ô    LỖI é
    if(test == 212 && tiengviet == 0 ) test = 166  ;    // Ô
    if(test == 227 && tiengviet == 0 ) test = 197  ;    // ã
    if(test == 195 && tiengviet == 0 ) test = 130  ;    // Ã
    if(test == 245 && tiengviet == 0 ) test = 231  ;    // õ
    if(test == 213 && tiengviet == 0 ) test = 164  ;    // Õ
    if(test == 224 && tiengviet == 0 ) test = 195  ;    // à
    if(test == 192 && tiengviet == 0 ) test = 127  ;    // À
    if(test == 232 && tiengviet == 0 ) test = 212  ;    // è
    if(test == 200 && tiengviet == 0 ) test = 145  ;    // È
    if(test == 236 && tiengviet == 0 ) test = 223  ;    // ì
    if(test == 204 && tiengviet == 0 ) test = 156  ;    // Ì
    if(test == 242 && tiengviet == 0 ) test = 228  ;    // ò
    if(test == 210 && tiengviet == 0 ) test = 161  ;    // Ò
    if(test == 249 && tiengviet == 0 ) test = 245  ;    // ù
    if(test == 217 && tiengviet == 0 ) test = 178  ;    // Ù
    if(test == 225 && tiengviet == 0 ) test = 194  ;    // á
    if(test == 193 && tiengviet == 0 ) test = 128  ;    // Á
    if(test == 233 && tiengviet == 0 ) test = 213  ;    // é
    if(test == 201 && tiengviet == 0 ) test = 146  ;    // É
    if(test == 237 && tiengviet == 0 ) test = 224  ;    // í
    if(test == 205 && tiengviet == 0 ) test = 157  ;    // Í
    if(test == 243 && tiengviet == 0 ) test = 229  ;    // ó
    if(test == 211 && tiengviet == 0 ) test = 162  ;    // Ó
    if(test == 250 && tiengviet == 0 ) test = 246  ;    // ú
    if(test == 218 && tiengviet == 0 ) test = 179  ;    // Ú
    if(test == 253 && tiengviet == 0 ) test = 28  ;    // ý
    if(test == 221 && tiengviet == 0 ) test = 190  ;    // Ý
 
    
    if(test > 0) 
    {
      mang2[t]=test;
      tiengviet=0;
      t++;
    }   
    if (mang2[t-1] == '\r') {
      Serial.println("OK");
      flagmode=0;
      for(dem=0;dem<10;dem++)
      {
        Mode1Line1_1[dem]=0;
        Mode1Line1_2[dem]=0;
        Mode1Line1_3[dem]=0;
        Mode1Line1_4[dem]=0;
        Mode1Line1_5[dem]=0;
        Mode1Line2_1[dem]=0;
        Mode1Line2_2[dem]=0;
        Mode1Line2_3[dem]=0;
        Mode1Line2_4[dem]=0;
        Mode1Line2_5[dem]=0;
        
      }
      stringComplete = true;
    } 
    
  }
}



void Readdata()
{
  int i,j,t;
  
  // Select che do
            if(EEPROM.read(0)=='1')
              {
                flagmode = 1;
              }
           if(EEPROM.read(0)=='2')
              {
               flagmode = 2;
              }  
           if(EEPROM.read(0)=='3')
              {
                flagmode = 3;
              }
              
       // che do 1 --------------------       
           if(flagmode == 1)
           {
             
             for(i=0;i<200;i++)Readout[i]=0;// xoa du lieu mang cu
             
             for(i=1;i<200;i++)
              {
                Readout[i-1]=EEPROM.read(i);
                if(EEPROM.read(i)==13)
                  {
                    i=209; // thoat khoi vong lap
                  }
              }
             if(strlen((char*)Readout)>0)   tachchu(Readout) ;
           }
    //-------------------- che do 2 ------------------------------
          if(flagmode == 2)
          {
            for(i=0;i<200;i++)ReadoutScrool[i]=0;
            for(i=1;i<200;i++)
                   {
                     ReadoutScrool[i-1]=EEPROM.read(i);
                     if (EEPROM.read(i)==13)
                      i=209; 
                   }
           drawText(ReadoutScrool);
               
          }
          
    //--------------------- che do 3 ----------------------------------
           if(flagmode == 3)
          {
             for(i=0;i<200;i++)
             {
               Readout[i]=0;// xoa du lieu mang cu
               ReadoutNormal[i]=0;
               ReadoutScrool[i]=0;
             }
             for(i=1;i<200;i++)
              {
                ReadoutNormal[i-1]=EEPROM.read(i);
                if(EEPROM.read(i)=='#')
                  {
                    j=i;
                    i=209; // thoat khoi vong lap
                  }
                  if(EEPROM.read(i)==13)
                  {
                    i=209; // thoat khoi vong lap
                  }
               }
               if(j>0)
                 {
                   t=j;
                   for(j=j+1;j<200;j++)
                   {
                     ReadoutScrool[j-t-1]=EEPROM.read(j);
                     if (EEPROM.read(j)==13)
                      j=209; 
                   }
 //                  Serial.println(ReadoutScrool);
                   j=0;
                 }  
               if(strlen((char*)ReadoutNormal)>0) tachchu(ReadoutNormal); 
               if(strlen((char*)ReadoutScrool)>0) drawText(ReadoutScrool);   
           }
}



// -------------------- Draw text --------------------------

void Normaltext()
{
  
  if(strlen((char*)Mode1Line1_1) > 0 || strlen((char*)Mode1Line2_1) > 0)
     {
       drawNormalText(Mode1Line1_1,Mode1Line2_1);
     }
     
     if(strlen((char*)Mode1Line1_2) > 0 || strlen((char*)Mode1Line2_2) > 0)
     {
       drawNormalText(Mode1Line1_2,Mode1Line2_2);
     }
     
     if(strlen((char*)Mode1Line1_3) > 0 || strlen((char*)Mode1Line2_3) > 0)
     {
       drawNormalText(Mode1Line1_3,Mode1Line2_3);
     }
  
}

void tachchu( unsigned char* Readout)
{
  int i;
              
             for(i=0;i<strlen((char*)Readout);i++)
               {
                 Mode1Line1_1[i]=Readout[i];
                 if(Readout[i]==kyhieu) i=209;
               }
//             Serial.println(Mode1Line1_1);
            //--------------------------------
             i=strlen((char*)Mode1Line1_1);
             if(i<strlen((char*)Readout)-1)
             {
               dem=i;
               for(i;i<strlen((char*)Readout);i++)
                 {
                   Mode1Line2_1[i-dem]=Readout[i];
                   if(Readout[i]==kyhieu) i=209 ;
                 }
//              Serial.println(Mode1Line2_1);
             }
             //-------------------------------

              i=strlen((char*)Mode1Line1_1)+strlen((char*)Mode1Line2_1);
             if(i<strlen((char*)Readout)-1)
             {
               dem=i;
               for(i;i<strlen((char*)Readout);i++)
                 {
                   
                    Mode1Line1_2[i-dem]=Readout[i];
                     if(Readout[i]==kyhieu) i=209;
                 }
 //              Serial.println(Mode1Line1_2);
             }
             //-------------------------------
             
             i=strlen((char*)Mode1Line1_1)+strlen((char*)Mode1Line2_1)+strlen((char*)Mode1Line1_2);
             if(i<strlen((char*)Readout)-1)
             {
               dem=i;
               for(i;i<strlen((char*)Readout);i++)
                 {
                   
                    Mode1Line2_2[i-dem]=Readout[i];
                     if(Readout[i]==kyhieu) i=209;
                 }
//               Serial.println(Mode1Line2_2);
             }
             //-------------------------------
             
             i=strlen((char*)Mode1Line1_1)+strlen((char*)Mode1Line2_1)+strlen((char*)Mode1Line1_2)+strlen((char*)Mode1Line2_2);
             if(i<strlen((char*)Readout)-1)
             {
               dem=i;
               for(i;i<strlen((char*)Readout);i++)
                 {
                   
                    Mode1Line1_3[i-dem]=Readout[i];
                     if(Readout[i]==kyhieu) i=209;
                 }
//               Serial.println(Mode1Line1_3);
             }
             //-------------------------------
            i=strlen((char*)Mode1Line1_1)+strlen((char*)Mode1Line2_1)+strlen((char*)Mode1Line1_2)+strlen((char*)Mode1Line2_2)+strlen((char*)Mode1Line1_3);
             if(i<strlen((char*)Readout)-1)
             {
               dem=i;
               for(i;i<strlen((char*)Readout);i++)
                 {
                   
                    Mode1Line2_3[i-dem]=Readout[i];
                     if(Readout[i]==kyhieu) i=209;
                 }
//               Serial.println(Mode1Line2_3);
             }
           Normaltext();  
}
void drawNormalText( unsigned char* text1, unsigned char* text2)
{
  long i;
     // display some text
   dmd.clearScreen( true );
   dmd.selectFont(System5x7);
   for (byte x=0;x<DISPLAYS_ACROSS;x++) {
     for (byte y=0;y<DISPLAYS_DOWN;y++) {
       dmd.drawString(  2+(32*x),  1+(16*y), text1, 5, GRAPHICS_NORMAL );
       dmd.drawString(  2+(32*x),  9+(16*y), text2, 5, GRAPHICS_NORMAL );
     }
   }
   for(i=0;i<3000;i++)
   {
     delay(1 );  
     if(Serial.available() >0) i=4000;
   }
}

// scroll text
void drawText( unsigned char* dispString ) 
{
  dmd.clearScreen( true );
  dmd.selectFont( Tieng_viet );
//  int sLength = dispString.length();
//  char newString[256];
  int sLength = strlen((char*)dispString);
//  dispString.toCharArray( newString, sLength+1 );
  dmd.drawMarquee( dispString , sLength , ( 32*DISPLAYS_ACROSS )-1 ,0);
  long start=millis();
  long timer=start;
  long timer2=start;
  boolean ret=false;
  while( !ret && Serial.available()== 0){
    if ( ( timer+80 ) < millis() ) {
      ret=dmd.stepMarquee( -1 , 0 );
      timer=millis();
    }
  }
}


