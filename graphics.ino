// Флаг Горячев
void Flag(int x, int y, int t){
    char flag[] = \
    "                                                              "
    "                                                              "
    "   ppppppp    pp    ppppp    ppppp  p    p  pppppp  ppppp     "
    "   ppppppp  pppppp  pppppp  pppppp  p    p  pppppp  pppppp    "
    "   p        p    p  p    p  p    p  p    p  p       p    p    "
    "   p        p    p  p    p  p    p  p    p  p       p    p    "
    "   p        p    p  p    p  p    p  p    p  pppppp  ppppp     "
    "   p        p    p  pppppp  pppppp  p    p  pppppp  ppppp     "
    "   p        p    p  ppppp    ppppp   ppppp  p       p    p    "
    "   p        p    p  p          p p       p  p       p    p    "
    "   p        pppppp  p         p  p       p  pppppp  pppppp    "
    "   p         pppp   p       p    p       p  pppppp  ppppp     "
    "                                                              "
    "                                                              "
    ;    
  
    int xstart = x;
    int ystart = y;
    int dy = 0;
    display.clearDisplay();    
    for(int i = 0; i < 14; i++){
        for(int j = 0; j < 62; j++){
                if(flag[i*62 + j] == 'p'){
                    //PutPixel(x + j, (int)(y + i + 2*sin(j/12.+t)), 0xFFFF00+(int)(0x0000FF*(sin(2*j/12.+t))));
                    display.drawPixel((int)(x + j + 5*cos(i/12.-t)), (int)(y + i + 3*sin(j/12.-t)), WHITE);                    
                }
                else{                                                                  //*(2*sin(j/12.+t))
                    //PutPixel(x + j, (int)(y + i + 2*sin(j/12.+t)), 0xFF0000+(int)(0x00FFFF*(sin(2*j/12.+t))));
                    display.drawPixel((int)(x + j + 5*cos(i/12.-t)), (int)(y + i + 3*sin(j/12.-t)), BLACK);                    
                }
                //x += 2;
                if(x%4 == 0) y++;
        }
        //x = xstart;
        dy += 0;
        y = ystart + dy;
    }
    //display.display();
}


