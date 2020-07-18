void FN_Draw_Page_Select()
{
    myGLCD.clrScr();
    myGLCD.fillScr(VGA_SILVER);

    myGLCD.setFont(GroteskBold24x48);    
    myGLCD.setBackColor(VGA_SILVER );  // nền sau của chữ
    myGLCD.setColor(255, 0, 0); // màu chữ
    myGLCD.print("Mode of operation", 270, yy0+5);
    
    myGLCD.drawBitmap (x_dc, y_dc, 64, 64, blue_cut, 2);
    // myGLCD.drawBitmap (208+128, 74, 64, 64, bottle, 2);
    myGLCD.drawBitmap (x_set, y_set-200, 64, 64, dungdich, 2);
    myGLCD.drawBitmap (x_dc, y_dc+200, 64, 64, vai, 2);
    // myGLCD.drawBitmap (208+128, 74*2+128, 64, 64, cao_su, 2);
    myGLCD.drawBitmap (x_set, y_set, 64, 64, icon_setup, 2);
    
//    myGLCD.setColor(230,230,230); // nền của khung 
//    myGLCD.fillRoundRect(312+128+128, 74*2+128,312+128+128+128, 74*2+128+128);// Select
//    myGLCD.setColor(200,200,200); // nền của khung 
//    myGLCD.fillRoundRect(312+128+128+5, 74*2+128+5,312+128+128+128-5, 74*2+128+128-5);// Select    
//    myGLCD.setColor(0,0,0); 
//    myGLCD.drawRoundRect(312+128+128+5, 74*2+128+5,312+128+128+128-5, 74*2+128+128-5);// Select  
//    // =====Select=========================================
//    myGLCD.setFont(UbuntuBold);
//    myGLCD.setBackColor(200, 200,200 );  // nền sau của chữ
//    myGLCD.setColor(255, 0, 0); // màu chữ
//    myGLCD.print("SET", 312+128+128+20,74*2+128+50);
    // =======Back=========================================
    myGLCD.setColor(128, 179, 255);
    myGLCD.fillRoundRect(1, 1, 180, 55);
    myGLCD.setColor(255, 255,255);
    myGLCD.drawRoundRect(1, 1, 180, 55);
    myGLCD.setFont(UbuntuBold);
    myGLCD.setColor(VGA_WHITE);
    myGLCD.setBackColor(128, 179, 255);
    myGLCD.print("< BACK",35,10);
}


