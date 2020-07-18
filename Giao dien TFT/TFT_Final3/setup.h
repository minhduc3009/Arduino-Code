
#if defined(ARDUINO) && (ARDUINO >= 100)
#  include "Arduino.h"
#else
# if !defined(IRPRONTO)
#   include "WProgram.h"
# endif
#endif

//=================FONT==================================
extern uint8_t SmallFont[];//8x12
extern uint8_t BigFont[];//16x16
extern uint8_t SevenSegNumFont[];//32x50
extern uint8_t SixteenSegment96x144Num[];
extern uint8_t Grotesk16x32[];
extern uint8_t Grotesk24x48[];
extern uint8_t SevenSegmentFull[];//32x50 pixels
extern uint8_t SevenSeg_XXXL_Num[];//64x100 pixels
extern uint8_t GroteskBold24x48[];
extern uint8_t UbuntuBold[];// 24x32
extern uint8_t Ubuntu[]; // 24x32

//================Image===================================
extern unsigned short yuin[7800];
extern unsigned short blue_cut[4096];
extern unsigned short bottle[4096];
extern unsigned short cao_su[4096];
extern unsigned short dungdich[4096];
extern unsigned short vai[4096];
extern unsigned short footer[19250];
extern unsigned short icon_setup[4096];
extern unsigned short logo_mini[46800];
extern unsigned short logo[14400];
//==============Variable TFT =====================================
  unsigned int x0=1;
  unsigned int x1=200;
  unsigned int x2=585;
  unsigned int x3=800;

  unsigned int yy0=1;
  unsigned int yy1=60;
  unsigned int yy2=100;
  unsigned int yy3=300;
  unsigned int yy4=300;
  unsigned int yy5=478;
  unsigned int yy6=480;

  unsigned int x_dc=200;
  unsigned int y_dc=74;
  unsigned int x_set=472;
  unsigned int y_set=276;

  //==============Variable Local =====================================
  int m,n;
  int x,y,z,t=0; // Variable for Tempature
  int vr_time_1,vr_time_2=0; // Variable for Timer
  int vr_exhaust_0,vr_exhaust_1,vr_exhaust_2=0;     // Variable for Exhaust
  int vr_exhaust_tmp=0;
  uint8_t index_digit=0; 
  uint8_t vr_select=0;
  uint8_t vr_state_select=0;
  
  float tem_set=0;
  int timer_minute_set=0;
  int timer_second_set=0;

  uint8_t F_Page_Set_Temp_Time_Ex = 0; // Cờ 
  uint8_t FLAG_START_STOP = 0;
  uint8_t FLAG_STATE = 2;
  //===================================================
  int Vr_Cut_Tem;
  int Vr_Cut_Timer;
  int Vr_Cut_Exhaust;

  int Vr_DD_Tem;
  int Vr_DD_Timer;
  int Vr_DD_Exhaust;

  int Vr_Vai_Tem;
  int Vr_Vai_Timer;
  int Vr_Vai_Exhaust;

  int Vr_Setup_Tem;
  int Vr_Setup_Timer;
  int Vr_Setup_Exhaust;
  //=======VR SEND AND RECIVER DATA=================================================
  uint8_t header='@';
  uint8_t tram;
  uint8_t chuc;
  uint8_t donvi;
  uint8_t thapphan;

  uint8_t data_send[10];
  uint8_t data_reciver[10];

  uint32_t crc;
  uint32_t CRC;
  uint8_t index_data_reciver=0;
  uint8_t FLAG_DATA_START=0;
  uint8_t data_nhietdo;
  uint8_t data_nhietdo_tp;
  int error;
  int phase;
  uint8_t flag_count_connect=0;
  uint16_t flag_check_end=0;
  uint8_t flag_check_timer=0;
  uint8_t flag_check_stop_cmd=0;

