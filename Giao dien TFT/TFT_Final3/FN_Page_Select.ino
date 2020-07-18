void FN_PAGE_SELECT()
{
 FN_Draw_Page_Select();
 while(1){
   if (myTouch.dataAvailable())
   {
        myTouch.read();
        m=myTouch.getX();
        n=myTouch.getY();
        Serial.print("m:=");Serial.println(m);
        Serial.print("n:=");Serial.println(n);
        if(n>=1 && n<55){ // BACK
          if(m>=1 && m<180)
          {
            FN_TONE(1);
                          switch (vr_state_select) {
                 case 1:
                        vr_select=1;
                   break;
                 case 3:

                        vr_select=3;
                                       
                   break;
                 case 4:
                       
                        vr_select=4;    
                                                          
                   break;
                 case 6:
                         
                        vr_select=6;  
                                                             
                   break;                   
             }
            break;
          }
            
        }
       if((n>=y_dc)&&(n<(y_dc+64*2))){
           if((m>=x_dc) && (m<(x_dc+64*2))){ // Hinh Dao Cut
               vr_select=1;FN_TONE(1);
               break;
           }
           // if((m>=336) && (m<464)){ // Hinh trai lo bottle
           //     vr_select=2;FN_TONE(1);
           //     break;
           // }
           if((m>=x_set) && (m<(x_set+64*2))){// Hinh dung dich
               vr_select=3;m=n=0;FN_TONE(1);
               break;
           }
       }
       if((n>=y_set)&&(n<(y_set+64*2))){
           if((m>=x_dc) && (m<(x_dc+64*2))){ // hinh vai
               vr_select=4;FN_TONE(1);
               break;
           }
           // if((m>=336) && (m<464))){ // hinh cao su
           //     vr_select=5;FN_TONE(1);
           //     break;
           // }
          if((m>=x_set) && (m<(x_set+64*2))){ // Khong xac dinh
                m=n=0;FN_TONE(1);
                vr_select=6;
                F_Page_Set_Temp_Time_Ex=0;
               FN_Control_Page_Setup();
               break;
           }
       }
   }//end if dataAvailable()

 }//end while
 m=n=0;
 FN_Draw_Page_Menu();
 myGLCD.setColor(255,255,255); // nền của khung 
 myGLCD.fillRoundRect(x0+1+4, yy2+1+4, x1-1-4, yy4-1-4);
 myGLCD.setFont(GroteskBold24x48);
 myGLCD.setBackColor(255, 255,255 );  // nền sau của chữ
 myGLCD.setColor(0, 255, 0); // màu chữ
 myGLCD.print("START", 40, yy2+140);     
}
