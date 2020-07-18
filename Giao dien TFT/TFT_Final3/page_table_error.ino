void FN_Draw_TABLE_ERROR()
{
    myGLCD.clrScr();
    myGLCD.fillScr(VGA_SILVER);
    myGLCD.setColor(128, 179, 255); // nền của khung 
    myGLCD.fillRect(x0, yy0, x3, yy1);// 
    myGLCD.setColor(VGA_WHITE); 
    myGLCD.drawRoundRect(x0, yy0, x3, yy1);// 
    myGLCD.setFont(UbuntuBold);
    myGLCD.setColor(VGA_RED);
    myGLCD.setBackColor(128, 179, 255);
    myGLCD.print("TABLE ERROR",290,10);

    myGLCD.setFont(Ubuntu);
    myGLCD.setColor(VGA_RED);
    myGLCD.setBackColor(VGA_SILVER);
    myGLCD.print("1. Loi Qua Nhiet",x1,120);
    myGLCD.print("2. Cua Mo",x1,120+50);
    myGLCD.print("3. Loi Van",x1,120+50+50);
    myGLCD.print("4. Sensor RTD",x1,120+50+50+50);
    myGLCD.print("5. Nuoc",x1,120+50+50+50+50);

      // BACK
  myGLCD.setColor(128, 179, 255);
  myGLCD.fillRoundRect(600, 400, 799, 479);
  myGLCD.setColor(255, 255,255);
  myGLCD.drawRoundRect(600, 400, 799, 479);
  myGLCD.setFont(UbuntuBold);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.setBackColor(128, 179, 255);
  myGLCD.print("BACK",675-24*2,423);
    
}

