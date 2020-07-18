void FN_Draw_Page_Setup()
{
  myGLCD.clrScr();
  myGLCD.setColor(255, 255, 255); 
  myGLCD.drawRect(1, 1, 799, 70);
  myGLCD.setColor(1, 58, 200); 
  myGLCD.fillRect(1, 1, 799, 70);
  for(int j=1;j<=3;j++)
  {
		for(int i=1; i<=4; i++){
      myGLCD.setColor(189, 189, 189); 
         myGLCD.fillRect(1+ (j-1)*133, 70+ 107*(i-1), 133*j, 70+107*i );
      myGLCD.setColor(255, 255, 255); 
			   myGLCD.drawRect(1+ (j-1)*133, 70+ 107*(i-1), 133*j, 70+107*i );


      myGLCD.setColor(220, 116, 1);
      myGLCD.fillRoundRect(16+ (j-1)*133, 85+ 107*(i-1), 133*j-15, 55+107*i );
      myGLCD.setColor(0, 0, 0); 
      myGLCD.drawRoundRect(16+ (j-1)*133, 85+ 107*(i-1), 133*j-15, 55+107*i );

    }
  }
  myGLCD.setColor(189, 189, 189); 
  myGLCD.fillRect(400, 391, 600, 479);
  myGLCD.fillRect(600, 391, 799, 479);

  myGLCD.setColor(255, 255, 255); 
  myGLCD.drawLine(1, 479, 400, 479);
  myGLCD.drawRect(400, 70, 799, 391);
  myGLCD.drawRect(400, 391, 600, 479);
  myGLCD.drawRect(600, 391, 799, 479);

  myGLCD.setColor(255, 255, 0);
  myGLCD.fillRoundRect(415, 391+15, 600-15, 479);
  myGLCD.fillRoundRect(600+15, 391+15, 799-15, 479);
  myGLCD.setColor(0, 0, 0);
  myGLCD.drawRoundRect(415, 391+15, 600-15, 479);
  myGLCD.drawRoundRect(600+15, 391+15, 799-15, 479);

  myGLCD.setFont(SevenSegNumFont);
  myGLCD.setBackColor(220, 116, 1);
  myGLCD.setColor(255, 255, 255);
  myGLCD.printNumI(1,56,100);
  myGLCD.printNumI(2,56+133,100);
  myGLCD.printNumI(3,56+133*2,100);
  myGLCD.printNumI(4,56,206);
  myGLCD.printNumI(5,56+133,206);
  myGLCD.printNumI(6,56+133*2,206);
  myGLCD.printNumI(7,56,312);
  myGLCD.printNumI(8,56+133,312);
  myGLCD.printNumI(9,56+133*2,312);  
  myGLCD.printNumI(0,56+133,418);
  myGLCD.setFont(Grotesk24x48);
  myGLCD.print(",",56,415);
  myGLCD.print("X",56+133*2,418);

  myGLCD.setFont(Grotesk24x48);
  myGLCD.setColor(255, 0, 0);
  myGLCD.setBackColor(255, 255, 0);
  myGLCD.print("BACK",445,418);
  myGLCD.print("Next",440+210,418);

}

