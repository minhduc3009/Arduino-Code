void FN_Draw_Page_Menu()
{
    myGLCD.clrScr();// xóa màn hình
    myGLCD.fillScr(VGA_SILVER);
    //===================================================
    myGLCD.setColor(VGA_WHITE); // set màu nền của khung 
    myGLCD.fillRoundRect(x0+4, yy0+4, x1-1-4, yy0+90);// LOGO YUIN
    myGLCD.fillRoundRect(x2+1+4, 480-72, x3-1-4, 480);// LOGO IRIAT 
    // image logo
    myGLCD.drawBitmap (35, yy0+4+13, 130, 60, yuin, 1);
    myGLCD.drawBitmap (x2+6, 480-72, 200, 72, logo, 1);
    //===================================================
    myGLCD.setColor(VGA_WHITE);
    myGLCD.fillRoundRect(x0+1+4, yy2+1+4, x1-1-4, yy4-1-4);// Start
    myGLCD.setColor(VGA_GRAY);
    myGLCD.fillRoundRect(x0+1+4, yy4+1+4, x1-1-4, yy6-1-4);// Setup
    myGLCD.setColor(VGA_WHITE);
    myGLCD.fillRoundRect(x1+1+4, yy1+1+4, x2-1-4, yy3-1-4);// Nhietdo

    myGLCD.setColor(VGA_WHITE);
    myGLCD.fillRoundRect(x1+1+4, yy3+1+4, x2-1-4, yy4+1+4+60);// Timer

    myGLCD.setColor(VGA_GRAY);
    myGLCD.fillRoundRect(x1+1+4, yy4+1+4+62, x2-1-4, yy5);// Runing +mode

    myGLCD.setColor(VGA_NAVY);
    myGLCD.fillRoundRect(x2+1+4, yy1+1+4, x3-1-4, 480-72);// setting
//  myGLCD.setColor(VGA_TEAL);
//  myGLCD.fillRoundRect(x2+1+4, 430, 798, 478);// Code By
    myGLCD.setColor(VGA_GRAY); // nền của khung 
    myGLCD.drawRoundRect(x0+4, yy0+4, x1-1-4, yy0+90);// LOGO
    // myGLCD.drawRoundRect(x1+1+4, yy0+1+4, x3-1-4, yy1-1-4);// Title
    myGLCD.drawRoundRect(x0+1+4, yy2+1+4, x1-1-4, yy4-1-4);// Start
    myGLCD.drawRoundRect(x0+1+4, yy4+1+4, x1-1-4, yy6-1-4);// Setup
    myGLCD.drawRoundRect(x1+1+4, yy1+1+4, x2-1-4, yy3-1-4);// Nhietdo

    myGLCD.drawRoundRect(x1+1+4, yy3+1+4, x2-1-4, yy4+1+4+60);// Timer
    myGLCD.drawRoundRect(x1+1+4, yy4+1+4+62, x2-1-4, yy5);// Runing +mode

    myGLCD.drawRoundRect(x2+1+4, yy1+1+4, x3-1-4, 480-72);// setting


    myGLCD.setFont(SmallFont);
    myGLCD.setBackColor(VGA_WHITE);  // nền sau của chữ
    myGLCD.setColor(VGA_RED); // màu chữ
    myGLCD.print("Temperature", x1+20,yy1);
    myGLCD.print("Timer", x1+20,yy3);
//    myGLCD.print("Manufactured by", x1+20,427);
    
     // =====Start===================================================================
     // myGLCD.setFont(GroteskBold24x48);
     // myGLCD.setBackColor(VGA_OLIVE );  // nền sau của chữ
     // myGLCD.setColor(VGA_LIME); // màu chữ
     // myGLCD.print("START", 50, yy2+76);
    myGLCD.setFont(GroteskBold24x48);
    myGLCD.setBackColor(255, 255,255 );  // nền sau của chữ
    myGLCD.setColor(0, 255, 0); // màu chữ
    myGLCD.print("START", 40, yy2+140);  
    // =====Setup===================================================================
    myGLCD.setFont(UbuntuBold);    
    myGLCD.setBackColor(VGA_GRAY );  // nền sau của chữ
    myGLCD.setColor(0, 0, 0); // màu chữ
    myGLCD.print("SETUP", 48, yy4+85);
    // =====Title===================================================================
    myGLCD.setFont(GroteskBold24x48);    
    myGLCD.setBackColor(VGA_SILVER );  // nền sau của chữ
    myGLCD.setColor(255, 0, 0); // màu chữ
    myGLCD.print("AUTOCLAVE", 380, yy0+5);
    // =====Timer===================================================================
    myGLCD.setFont(GroteskBold24x48);    
    myGLCD.setBackColor(VGA_WHITE);  // nền sau của chữ
    myGLCD.setColor(0, 0, 0); // màu chữ
    myGLCD.print("00:00", x1+125, yy4+17);//yy4+1+4+51
    // =====Running===================================================================
    myGLCD.setFont(BigFont);    
    myGLCD.setBackColor(VGA_GRAY);  // nền sau của chữ
    myGLCD.setColor(0, 0, 255); // màu chữ
    myGLCD.print("Phase:", x1+15, yy4+90);//yy4+1+4+51
    myGLCD.print("Status:          ", x1+15, yy4+135);//yy4+1+4+51
//    myGLCD.setColor(0, 0, 255);
//    myGLCD.print("Heating & Purge", x1+15+16*6, yy4+90);
    myGLCD.setColor(VGA_GREEN);
    myGLCD.print("Ready          ", x1+15+16*7, yy4+135);
    // =====Temp===================================================================
    myGLCD.setFont(BigFont);    
    myGLCD.setBackColor(VGA_NAVY );  // nền sau của chữ
    myGLCD.setColor(VGA_WHITE); // màu chữ
    myGLCD.print("Settings", x2+50, 80);
    myGLCD.setFont(Ubuntu);    
    myGLCD.setBackColor(VGA_NAVY );  // nền sau của chữ
    myGLCD.setColor(VGA_WHITE); // màu chữ
//    myGLCD.print("Settings", x2+42, 80);
    myGLCD.print("SV Temp:", x2+7, 130); 
    myGLCD.print("Time(s):", x2+7, 230);  
    myGLCD.print("Exhaust:", x2+7, 330);
    myGLCD.print("(%)", x2+40+24*3, 330+40);
    
    myGLCD.setFont(Ubuntu);    
    myGLCD.setBackColor(VGA_NAVY );  // nền sau của chữ
    myGLCD.setColor(VGA_RED); // màu chữ
    myGLCD.print("000",x2+40,130+40);
    myGLCD.print("o",x2+40+24*3,130+35);
    myGLCD.print("C",x2+40+24*4,130+40);
    myGLCD.setColor(VGA_GREEN);
    myGLCD.print("0 :00",x2+40, 230+40); 
    myGLCD.setColor(VGA_OLIVE);
    myGLCD.print("0",x2+40, 330+40);

//    // =====Code By===================================================================
//    myGLCD.setFont(Ubuntu);    
//    myGLCD.setBackColor(VGA_TEAL );  // nền sau của chữ
//    myGLCD.setColor(255, 0, 0); // màu chữ
//    myGLCD.print("Origin", x2+45, 443);                
    // =====Nhietdo===================================================================
    myGLCD.setFont(SevenSeg_XXXL_Num);    
    myGLCD.setBackColor(VGA_WHITE );  // nền sau của chữ
    myGLCD.setColor(VGA_RED); // màu chữ
//    myGLCD.printNumI(1, 225, yy1+75);
//    myGLCD.printNumI(2, 225+64*1, yy1+75);
//    myGLCD.printNumI(3, 225+64*2, yy1+75);
//    myGLCD.printNumI(4, 200+64*4, yy1+75);
    myGLCD.setFont(GroteskBold24x48);
    myGLCD.print(",", 225+64*3, yy1+75+80);
    myGLCD.print("o", 200+64*5, yy1+75);
    myGLCD.print("C", 200+64*6-35, yy1+75);
}


