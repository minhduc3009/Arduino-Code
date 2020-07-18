void FN_Draw_Origin()
{
  myGLCD.clrScr();
  myGLCD.fillScr(0,0,0);
  // myGLCD.setColor(VGA_RED); // nền của khung 
//   myGLCD.drawRoundRect(150, 80,650,400);// LOGO
    
// myGLCD.drawBitmap (200, 100, 400, 117, logo_mini, 1);

  myGLCD.setFont(BigFont);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.setBackColor(0,0,0);
  myGLCD.print("Indochina Research Institute of",190,230);
    myGLCD.print("Applied Advanced Technology(IRIAT)",175,255);
    myGLCD.setColor(200,0,0);
      myGLCD.print("Tel: 043.641.1545",200,285);
        myGLCD.print("Email: vienkhcndongduong@gmail.com",200,305);

  // BACK
  myGLCD.setColor(128, 179, 255);
  myGLCD.fillRoundRect(600, 400, 799, 479);
  myGLCD.setColor(255, 255,255);
  myGLCD.drawRoundRect(600, 400, 799, 479);
  myGLCD.setFont(UbuntuBold);
  myGLCD.setColor(VGA_WHITE);
  myGLCD.setBackColor(128, 179, 255);
  myGLCD.print("BACK",675-24*2,423);
   
//   FN_Draw_Page_Menu();
  
    
}

