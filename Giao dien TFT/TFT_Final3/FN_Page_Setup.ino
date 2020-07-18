void FN_Control_Page_Setup()
{
  // Thiet lap 3 thong so Nhiet do , Thoi gian , Phan tram
 FN_Draw_Page_Setup();
 F_Page_Set_Temp_Time_Ex=0;
 while(1)
 {
  switch (F_Page_Set_Temp_Time_Ex) {
      case 0:// Page set temperature
          myGLCD.setFont(SevenSeg_XXXL_Num); //64x100
          myGLCD.setBackColor(0, 0, 0);
          myGLCD.setColor(255, 255, 255);
          myGLCD.printNumI(x,420,180);
          myGLCD.printNumI(y,420+64*1,180);
          myGLCD.printNumI(z,420+64*2,180);
          myGLCD.printNumI(t,405+64*4,180);

          myGLCD.setFont(Grotesk24x48);
          myGLCD.print(",", 612 ,240 );
          myGLCD.print("o", 735 ,175 );
          myGLCD.print("C", 770 ,180 );

          // myGLCD.setFont(Grotesk24x48);
          myGLCD.setBackColor(1, 58, 200); 
          myGLCD.setColor(255, 255, 255);
          myGLCD.print("Setup Temperature",200,10);          
        break;
      case 1: // Page set Timer
          myGLCD.setFont(SevenSeg_XXXL_Num);
          myGLCD.setBackColor(0, 0, 0);
          myGLCD.setColor(255, 255, 255);
          myGLCD.printNumI(vr_time_1,420+64,180);
          myGLCD.printNumI(vr_time_2,420+64*2,180);

          myGLCD.setFont(Grotesk24x48);
          myGLCD.print("(m)", 437+64*3 ,220 );

          // myGLCD.setFont(Grotesk24x48);
          myGLCD.setBackColor(1, 58, 200); 
          myGLCD.setColor(255, 255, 255);
          myGLCD.print("    Setup Time   ",200,10);
        break;
      case 2: // Page set Exhaust
          myGLCD.setFont(SevenSeg_XXXL_Num); //64x100
          myGLCD.setBackColor(0, 0, 0);
          myGLCD.setColor(255, 255, 255);
          // myGLCD.printNumI(vr_exhaust_1,420+64,180);
          // myGLCD.printNumI(vr_exhaust_2,420+64*2,180);

          myGLCD.setFont(Grotesk24x48);
          myGLCD.print("(%)", 437+64*3 ,220 );  
          
          // myGLCD.setFont(Grotesk24x48);
          myGLCD.setBackColor(1, 58, 200); 
          myGLCD.setColor(255, 255, 255);
          myGLCD.print("  Setup Exhaust  ",200,10);     
        break;
  }

   if (myTouch.dataAvailable())
   {
       myTouch.read();
       m=myTouch.getX();
       n=myTouch.getY();
       Serial.print("m:=");Serial.println(m);
       Serial.print("n:=");Serial.println(n);
         if ((m>=1) && (m<=133)) 
         {
           if ((n>=70) && (n<=177))  // 1
           {
             waitForIt(1, 70, 133, 177); FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(1); // F_Page_Set_Temp_Time_Ex để phân biệt đang ở thiết lập nhiệt độ hay là timer
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(1);
             else FN_SET_EXHAUST(1);
           
           }
           if ((n>177) && (n<=284))  // 4
           {
             waitForIt(1, 177, 133, 284);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(4);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(4);
             else FN_SET_EXHAUST(4);
           }
           if ((n>284) && (n<=391))  // 7
           {
             waitForIt(1, 284, 133, 391);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(7);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(7);
             else FN_SET_EXHAUST(7);
           }
           if ((n>391) && (n<=479))  // ","
           {
             waitForIt(1, 391, 133, 479);FN_TONE(1);

           }
         }// end if ((m>=1) && (m<=133))
         if ((m>133) && (m<=266))
         {
           if ((n>=70) && (n<=177))  // 2
           {
             waitForIt(133, 70, 266, 177); FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(2);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(2);
             else FN_SET_EXHAUST(2);
           }
           if ((n>177) && (n<=284))  // 5
           {
             waitForIt(133, 177, 266, 284);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(5);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(5);
             else FN_SET_EXHAUST(5);
           }
           if ((n>284) && (n<=391))  // 8
           {
             waitForIt(133, 284, 266, 391);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(8);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(8);
             else FN_SET_EXHAUST(8);
           }
           if ((n>391) && (n<=479))  // 0
           {
             waitForIt(133, 391, 266, 479);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(0);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(0);
             else FN_SET_EXHAUST(0);
           }
         }//end 133<m<266
         if ((m>266) && (m<=399))
         {
           if ((n>=70) && (n<=177))  // 3
           {
             waitForIt(266, 70, 399, 177); FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(3);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(3);
             else FN_SET_EXHAUST(3);
           }
           if ((n>177) && (n<=284))  // 6
           {
             waitForIt(266, 177, 399, 284);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(6);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(6);
             else FN_SET_EXHAUST(6);
           }
           if ((n>284) && (n<=391))  // 9
           {
             waitForIt(266, 284, 399, 391);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(9);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(9);
             else FN_SET_EXHAUST(9);
           }
           if ((n>391) && (n<=479))  // Clear
           {
             waitForIt(266, 391, 399, 479);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)
             {
               x=y=z=t=0;
               myGLCD.setColor(0, 0, 0); 
               myGLCD.fillRect(400, 70, 799, 391);
               myGLCD.setFont(SevenSeg_XXXL_Num); //64x100
               myGLCD.setBackColor(0, 0, 0);
               myGLCD.setColor(255, 255, 255);
               myGLCD.printNumI(x,420,180);
               myGLCD.printNumI(y,420+64*1,180);
               myGLCD.printNumI(z,420+64*2,180);
               myGLCD.printNumI(t,405+64*4,180);
               myGLCD.setFont(Grotesk24x48);
               myGLCD.print(",", 612 ,240 );
               myGLCD.print("o", 735 ,175 );
               myGLCD.print("C", 770 ,180 );
             }
             else if(F_Page_Set_Temp_Time_Ex==1) 
             {
               vr_time_1=vr_time_2=0;
               myGLCD.setColor(0, 0, 0); 
               myGLCD.fillRect(400, 70, 799, 391);
               myGLCD.setFont(SevenSeg_XXXL_Num);
               myGLCD.setBackColor(0, 0, 0);
               myGLCD.setColor(255, 255, 255);
               myGLCD.printNumI(vr_time_1,420+64,180);
               myGLCD.printNumI(vr_time_2,420+64*2,180);

               myGLCD.setFont(Grotesk24x48);
               myGLCD.print("(m)", 437+64*3 ,220 );
             }
             else 
             {
               vr_exhaust_0=vr_exhaust_1=vr_exhaust_2=0;
               myGLCD.setColor(0, 0, 0); 
               myGLCD.fillRect(400, 70, 799, 391);
               // myGLCD.setFont(SevenSeg_XXXL_Num);
               myGLCD.setBackColor(0, 0, 0);
               myGLCD.setColor(255, 255, 255);
               // myGLCD.printNumI(vr_exhaust_1,420+64,180);
               // myGLCD.printNumI(vr_exhaust_2,420+64*2,180);

               myGLCD.setFont(Grotesk24x48);
               myGLCD.print("(%)", 437+64*3 ,220 );              
             }
             index_digit=0;

           }            
         }//end 266<m<399 
         if ((m>399) && (m<=600))
         {     
           if ((n>391) && (n<=479)) // BACK
           {
              index_digit=0;
              waitForIt(399, 391, 600, 479);FN_TONE(1);
              // Vr_Setup_Tem=x*100+y*10+z;
              // Vr_Setup_Timer = vr_time_1*10+ vr_time_2;
              // Vr_Setup_Exhaust = vr_exhaust_0*100 + vr_exhaust_1*10 +vr_exhaust_2;
              break;
           }            
         }
         if ((m>600) && (m<=799)) // NEXT
         {     
           index_digit=0;
           if ((n>391) && (n<=479))  
           {
             waitForIt(600, 391, 799, 479);FN_TONE(1);
             F_Page_Set_Temp_Time_Ex++;

             if(F_Page_Set_Temp_Time_Ex==3) // OUT về màn hình chính
             {
               if(vr_select==0)vr_select=6;
               Vr_Setup_Tem=x*100+y*10+z;
               Vr_Setup_Timer = vr_time_1*10+ vr_time_2;
               Vr_Setup_Exhaust = vr_exhaust_tmp;
               
                dueFlashStorage.write(9,Vr_Setup_Tem);
                dueFlashStorage.write(10,Vr_Setup_Timer);
                dueFlashStorage.write(11,Vr_Setup_Exhaust);

               Serial.println(Vr_Setup_Tem);
               Serial.println(Vr_Setup_Timer);
               Serial.println(Vr_Setup_Exhaust);

               F_Page_Set_Temp_Time_Ex=0;
               break;
             }
               myGLCD.setColor(0, 0, 0); 
               myGLCD.fillRect(400, 70, 799, 391);
           }              
         }
      } // end if (myTouch.dataAvailable())
 }// end While(1)
m=n=0;
}






















void FN_Control_Page_Setup2()
{
  // Thiet lap 3 thong so Nhiet do , Thoi gian , Phan tram
  FN_Draw_Page_Setup();
  myGLCD.setFont(Grotesk24x48);
  myGLCD.setColor(255, 0, 0);
  myGLCD.setBackColor(255, 255, 0);
  myGLCD.print("BACK",445,418);
  myGLCD.print(" OK ",440+210,418);
 while(1)
 {
  switch (F_Page_Set_Temp_Time_Ex) {
      case 0:// Page set temperature
          myGLCD.setFont(SevenSeg_XXXL_Num); //64x100
          myGLCD.setBackColor(0, 0, 0);
          myGLCD.setColor(255, 255, 255);
          myGLCD.printNumI(x,420,180);
          myGLCD.printNumI(y,420+64*1,180);
          myGLCD.printNumI(z,420+64*2,180);
          myGLCD.printNumI(t,405+64*4,180);

          myGLCD.setFont(Grotesk24x48);
          myGLCD.print(",", 612 ,240 );
          myGLCD.print("o", 735 ,175 );
          myGLCD.print("C", 770 ,180 );

          // myGLCD.setFont(Grotesk24x48);
          myGLCD.setBackColor(1, 58, 200); 
          myGLCD.setColor(255, 255, 255);
          myGLCD.print("Setup Temperature",200,10);          
        break;
      case 1: // Page set Timer
          myGLCD.setFont(SevenSeg_XXXL_Num);
          myGLCD.setBackColor(0, 0, 0);
          myGLCD.setColor(255, 255, 255);
          myGLCD.printNumI(vr_time_1,420+64,180);
          myGLCD.printNumI(vr_time_2,420+64*2,180);

          myGLCD.setFont(Grotesk24x48);
          myGLCD.print("(min)", 437+64*3 ,220 );

          // myGLCD.setFont(Grotesk24x48);
          myGLCD.setBackColor(1, 58, 200); 
          myGLCD.setColor(255, 255, 255);
          myGLCD.print("    Setup Time   ",200,10);
        break;
      case 2: // Page set Exhaust
          myGLCD.setFont(SevenSeg_XXXL_Num); //64x100
          myGLCD.setBackColor(0, 0, 0);
          myGLCD.setColor(255, 255, 255);

          // myGLCD.printNumI(vr_exhaust_0,420,180);
          // myGLCD.printNumI(vr_exhaust_1,420+64,180);
          // myGLCD.printNumI(vr_exhaust_2,420+64*2,180);

          myGLCD.setFont(Grotesk24x48);
          myGLCD.print("(%)", 437+64*3 ,220 );  
          
          // myGLCD.setFont(Grotesk24x48);
          myGLCD.setBackColor(1, 58, 200); 
          myGLCD.setColor(255, 255, 255);
          myGLCD.print("  Setup Exhaust  ",200,10);     
        break;
  }

   if (myTouch.dataAvailable())
   {
       myTouch.read();
       m=myTouch.getX();
       n=myTouch.getY();
       Serial.print("m:=");Serial.println(m);
       Serial.print("n:=");Serial.println(n);
         if ((m>=1) && (m<=133)) 
         {
           if ((n>=70) && (n<=177))  // 1
           {
             waitForIt(1, 70, 133, 177); FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(1); // F_Page_Set_Temp_Time_Ex để phân biệt đang ở thiết lập nhiệt độ hay là timer
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(1);
             else FN_SET_EXHAUST(1);
           
           }
           if ((n>177) && (n<=284))  // 4
           {
             waitForIt(1, 177, 133, 284);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(4);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(4);
             else FN_SET_EXHAUST(4);
           }
           if ((n>284) && (n<=391))  // 7
           {
             waitForIt(1, 284, 133, 391);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(7);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(7);
             else FN_SET_EXHAUST(7);
           }
           if ((n>391) && (n<=479))  // ","
           {
             waitForIt(1, 391, 133, 479);FN_TONE(1);

           }
         }// end if ((m>=1) && (m<=133))
         if ((m>133) && (m<=266))
         {
           if ((n>=70) && (n<=177))  // 2
           {
             waitForIt(133, 70, 266, 177); FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(2);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(2);
             else FN_SET_EXHAUST(2);
           }
           if ((n>177) && (n<=284))  // 5
           {
             waitForIt(133, 177, 266, 284);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(5);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(5);
             else FN_SET_EXHAUST(5);
           }
           if ((n>284) && (n<=391))  // 8
           {
             waitForIt(133, 284, 266, 391);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(8);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(8);
             else FN_SET_EXHAUST(8);
           }
           if ((n>391) && (n<=479))  // 0
           {
             waitForIt(133, 391, 266, 479);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(0);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(0);
             else FN_SET_EXHAUST(0);
           }
         }//end 133<m<266
         if ((m>266) && (m<=399))
         {
           if ((n>=70) && (n<=177))  // 3
           {
             waitForIt(266, 70, 399, 177); FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(3);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(3);
             else FN_SET_EXHAUST(3);
           }
           if ((n>177) && (n<=284))  // 6
           {
             waitForIt(266, 177, 399, 284);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(6);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(6);
             else FN_SET_EXHAUST(6);
           }
           if ((n>284) && (n<=391))  // 9
           {
             waitForIt(266, 284, 399, 391);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)FN_SET_TEMP(9);
             else if(F_Page_Set_Temp_Time_Ex==1) FN_SET_TIMER(9);
             else FN_SET_EXHAUST(9);
           }
           if ((n>391) && (n<=479))  // Clear
           {
             waitForIt(266, 391, 399, 479);FN_TONE(1);
             if(F_Page_Set_Temp_Time_Ex==0)
             {
               x=y=z=t=0;
               myGLCD.setColor(0, 0, 0); 
               myGLCD.fillRect(400, 70, 799, 391);
               myGLCD.setFont(SevenSeg_XXXL_Num); //64x100
               myGLCD.setBackColor(0, 0, 0);
               myGLCD.setColor(255, 255, 255);
               myGLCD.printNumI(x,420,180);
               myGLCD.printNumI(y,420+64*1,180);
               myGLCD.printNumI(z,420+64*2,180);
               myGLCD.printNumI(t,405+64*4,180);
               myGLCD.setFont(Grotesk24x48);
               myGLCD.print(",", 612 ,240 );
               myGLCD.print("o", 735 ,175 );
               myGLCD.print("C", 770 ,180 );
             }
             else if(F_Page_Set_Temp_Time_Ex==1) 
             {
               vr_time_1=vr_time_2=0;
               myGLCD.setColor(0, 0, 0); 
               myGLCD.fillRect(400, 70, 799, 391);
               myGLCD.setFont(SevenSeg_XXXL_Num);
               myGLCD.setBackColor(0, 0, 0);
               myGLCD.setColor(255, 255, 255);
               myGLCD.printNumI(vr_time_1,420+64,180);
               myGLCD.printNumI(vr_time_2,420+64*2,180);

               myGLCD.setFont(Grotesk24x48);
               myGLCD.print("(m)", 437+64*3 ,220 );
             }
             else 
             {
               vr_exhaust_0=vr_exhaust_1=vr_exhaust_2=0;
               myGLCD.setColor(0, 0, 0); 
               myGLCD.fillRect(400, 70, 799, 391);
               // myGLCD.setFont(SevenSeg_XXXL_Num);
               myGLCD.setBackColor(0, 0, 0);
               // myGLCD.setColor(255, 255, 255);
               // myGLCD.printNumI(vr_exhaust_1,420+64,180);
               // myGLCD.printNumI(vr_exhaust_2,420+64*2,180);

               myGLCD.setFont(Grotesk24x48);
               myGLCD.print("(%)", 437+64*3 ,220 );              
             }
             index_digit=0;

           }            
         }//end 266<m<399 
         if ((m>399) && (m<=600))
         {     
           if ((n>391) && (n<=479)) // BACK
           {
            index_digit=0;
            x=y=z=t=0;
            vr_time_1=vr_time_2=0;
            vr_exhaust_0=vr_exhaust_1=vr_exhaust_2=0;
              waitForIt(399, 391, 600, 479);FN_TONE(1);
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
         if ((m>600) && (m<=799)) // OK
         {     
          
           if ((n>391) && (n<=479))  
           {
             waitForIt(600, 391, 799, 479);FN_TONE(1);
             switch (vr_state_select) {
                 case 1:
                        if(F_Page_Set_Temp_Time_Ex==0)
                        {
                          Vr_Cut_Tem=x*100+y*10+z;
                          dueFlashStorage.write(0,Vr_Cut_Tem);
                        }
                        else if(F_Page_Set_Temp_Time_Ex==1) 
                        {
                          Vr_Cut_Timer = vr_time_1*10+ vr_time_2;
                          dueFlashStorage.write(1,Vr_Cut_Timer);
                        }
                        else {
                          Vr_Cut_Exhaust = vr_exhaust_tmp;
                          dueFlashStorage.write(2,Vr_Cut_Exhaust);
                        } 
                        vr_select=1;
                        
                   break;
                 case 3:
                        if(F_Page_Set_Temp_Time_Ex==0)
                        {
                          Vr_DD_Tem=x*100+y*10+z;
                          dueFlashStorage.write(3,Vr_DD_Tem);
                        }
                        else if(F_Page_Set_Temp_Time_Ex==1) 
                        {
                          Vr_DD_Timer = vr_time_1*10+ vr_time_2;
                          dueFlashStorage.write(4,Vr_DD_Timer);
                        }
                        else {
                          Vr_DD_Exhaust = vr_exhaust_tmp;
                          dueFlashStorage.write(5,Vr_DD_Exhaust); 
                        } 
                        vr_select=3;   
                                                                 
                   break;
                 case 4:
                        if(F_Page_Set_Temp_Time_Ex==0)
                        {
                          Vr_Vai_Tem=x*100+y*10+z;
                          dueFlashStorage.write(6,Vr_Vai_Tem);
                        }
                        else if(F_Page_Set_Temp_Time_Ex==1) 
                        {
                          Vr_Vai_Timer = vr_time_1*10+ vr_time_2;
                          dueFlashStorage.write(7,Vr_Vai_Timer);
                        }
                        else {
                          Vr_Vai_Exhaust = vr_exhaust_tmp;
                          dueFlashStorage.write(8,Vr_Vai_Exhaust); 
                        }   
                        vr_select=4;                                              
                   break;
                 case 6:
                        if(F_Page_Set_Temp_Time_Ex==0)
                        {
                          Vr_Setup_Tem=x*100+y*10+z;
                          dueFlashStorage.write(9,Vr_Setup_Tem);
                        }
                        else if(F_Page_Set_Temp_Time_Ex==1) 
                        {
                          Vr_Setup_Timer = vr_time_1*10+ vr_time_2;
                          dueFlashStorage.write(10,Vr_Setup_Timer);
                        }
                        else {
                          Vr_Setup_Exhaust = vr_exhaust_tmp;
                          dueFlashStorage.write(11,Vr_Setup_Exhaust);
                        }                   
                        vr_select=6;                                             
                   break;                   
             }
             x=y=z=t=0;
            vr_time_1=vr_time_2=0;
            vr_exhaust_0=vr_exhaust_1=vr_exhaust_2=0;
              break;
           }
           index_digit=0;              
         }
      } // end if (myTouch.dataAvailable())
 }// end While(1)
m=n=0;
}



















void FN_SET_TIMER(uint8_t Number)
{
   index_digit++;
   if(index_digit>2) index_digit=1;
   switch (index_digit) {
       case 1:
         vr_time_1=Number;
         break;
       case 2:
         vr_time_2=Number;
         break;                   
   }
   myGLCD.setFont(SevenSeg_XXXL_Num);
   myGLCD.setBackColor(0, 0, 0);
   myGLCD.setColor(255, 255, 255);
   myGLCD.printNumI(vr_time_1,420+64,180);
   myGLCD.printNumI(vr_time_2,420+64*2,180);
}
void FN_SET_TEMP(uint8_t Number)
{ // <=130
   index_digit++;
   if(index_digit>4) index_digit=1;
   switch (index_digit) {
       case 1:
         x=Number;
         break;
       case 2:
         y=Number;
         break;
       case 3:
         z=Number;
         break;
       case 4:
         t=Number;
         break;                    
   }
   if(x>1) x=1;
   if(x==1 && y>3)y=3;
   if(x==1 && y==3)z=0;
   myGLCD.setFont(SevenSeg_XXXL_Num); //64x100
   myGLCD.setBackColor(0, 0, 0);
   myGLCD.setColor(255, 255, 255);
   myGLCD.printNumI(x,420,180);
   myGLCD.printNumI(y,420+64*1,180);
   myGLCD.printNumI(z,420+64*2,180);
   myGLCD.printNumI(t,405+64*4,180);
}
void FN_SET_EXHAUST(uint8_t Number)
{ // Chon chuc
   index_digit++;
   if(index_digit>3) index_digit=1;
   switch (index_digit) {
       case 1:
         vr_exhaust_0=Number;
         break;
       case 2:
         vr_exhaust_1=Number;
         break;   
       case 3:
         vr_exhaust_2=Number;
         break;                 
   }

   myGLCD.setColor(0, 0, 0); 
   myGLCD.fillRect(400, 70, 437+64*3, 391);
   myGLCD.setFont(SevenSeg_XXXL_Num); //64x100
   myGLCD.setBackColor(0, 0, 0);
   myGLCD.setColor(255, 255, 255);

   if(index_digit==1){
       vr_exhaust_tmp=vr_exhaust_0;
       myGLCD.printNumI(vr_exhaust_0,420+64*2,180);
   }
   else if(index_digit==2){
    vr_exhaust_1=0;
    vr_exhaust_2=0;
    vr_exhaust_tmp=vr_exhaust_0*10;
      myGLCD.printNumI(vr_exhaust_0,420+64,180);
      myGLCD.printNumI(vr_exhaust_1,420+64*2,180);
   }
   else if(index_digit==3){
    vr_exhaust_0=1;
    vr_exhaust_1=0;
    vr_exhaust_2=0;
    vr_exhaust_tmp=vr_exhaust_0*100;
   myGLCD.printNumI(vr_exhaust_0,420,180);
   myGLCD.printNumI(vr_exhaust_1,420+64,180);
   myGLCD.printNumI(vr_exhaust_2,420+64*2,180);
   }

   // myGLCD.printNumI(vr_exhaust_0,420,180);
   // myGLCD.printNumI(vr_exhaust_1,420+64,180);
   // myGLCD.printNumI(vr_exhaust_2,420+64*2,180);
}

