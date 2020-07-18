void FN_PAGE_ORIGIN()
{
 FN_Draw_Origin();
 while(1){
     if (myTouch.dataAvailable())
     {
          myTouch.read();
          m=myTouch.getX();
          n=myTouch.getY();
          if(n>=400 && n<480){ // BACK
            if(m>=600 && m<799)
            {
              FN_TONE(1);
              m=n=0;
              break;
            }
          }
     }
     
   }
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
   FN_Draw_Page_Menu();
  // myGLCD.setColor(255,255,255); // nền của khung 
  // myGLCD.fillRoundRect(x0+1+4, yy2+1+4, x1-1-4, yy4-1-4);
  // myGLCD.setFont(GroteskBold24x48);
  // myGLCD.setBackColor(255, 255,255 );  // nền sau của chữ
  // myGLCD.setColor(0, 255, 0); // màu chữ
  // myGLCD.print("START", 40, yy2+140);   
}

