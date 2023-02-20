// Счет игроков
int player1Score = 0;
int player2Score = 0;


// Возвращает точку по двум координатам
 TPoint point(float x, float y){
    TPoint pt;
    pt.x = x;
    pt.y = y;
    return pt;
}


// Проверка столкновения
bool ObjectCollision(TObject o1, TObject o2){
    return ((o1.pos.x + o1.size.x) > o2.pos.x) && (o1.pos.x < (o2.pos.x + o2.size.x)) &&
           ((o1.pos.y + o1.size.y) > o2.pos.y) && (o1.pos.y < (o2.pos.y + o2.size.y));
}


// Инициализация объекта
void ObjectInit(TObject *obj, float xPos, float yPos, float width, float height, char objType){
   obj->pos = point(xPos, yPos);
   obj->size = point(width, height);
   obj->speed = point(0, 0);
   obj->oType = objType;
   obj->isDel = false;
}


// Выводит спрайт с прозрачным фоном
void DrawBitmapTransparent(char monster[], int xstart, int ystart, int sizeX, int sizeY, int scale){
    int x = xstart;
    int y = ystart;

    for(int i = 0; i < sizeY; i++){
        for(int scaleY = scale; scaleY > 0; scaleY--){
        for(int j = 0; j < sizeX; j++){
            if(monster[i*sizeX + j] == 'p'){
                for(int scaleX = scale; scaleX > 0; scaleX--){
                //PutPixel(x + j, y + i, CC);
                display.drawPixel(x + j, y + i, BLACK);
                if(scaleX > 1) x++;
                }
            }
            else{
                for(int scaleX = scale; scaleX > 0; scaleX--){
                //PutPixel(x + j, y + i, BC);
                if(scaleX > 1) x++;
                }
            }
        }
        x = xstart;
        if(scaleY > 1) y++;
        }
    }
}


// Рисование объекта
void ObjectShow(TObject obj){

    char monster1[] = \
    "   pp   "
    "  pppp  "
    " pppppp "
    "pp pp pp"
    "pppppppp"
    "  p  p  "
    " p pp p "
    "p p  p p"
    ;//8x8
    char monster2[] = \
    "    pppp    "
    " pppppppppp "
    "pppppppppppp"
    "ppp  pp  ppp"
    "pppppppppppp"
    "   pp  pp   "
    "  pp    pp  "
    "pp        pp"
    ;//12x8
    char monster3[] = \
    "  p     p  "
    "   p   p   "
    "  ppppppp  "
    " pp ppp pp "
    "ppppppppppp"
    "p ppppppp p"
    "p p     p p"
    "   pp pp   "
    ;//11x8

    
    if(obj.oType == 'p'){
      DrawBitmapTransparent(monster3, (int)(obj.pos.x), (int)(obj.pos.y), (int)(obj.size.x), (int)(obj.size.y), 1);
    }
    if(obj.oType == 'e'){
      DrawBitmapTransparent(monster1, (int)(obj.pos.x), (int)(obj.pos.y), (int)(obj.size.x), (int)(obj.size.y), 1);     
    }
    if(obj.oType == 'x'){
      DrawBitmapTransparent(monster2, (int)(obj.pos.x), (int)(obj.pos.y), (int)(obj.size.x), (int)(obj.size.y), 1); 
    }

    display.setTextSize(1);  // установка размера шрифта
    display.setTextColor(BLACK); // установка цвета текста
    char playerScoreStr[3];
    
    itoa(player1Score, playerScoreStr, 10); // Преобразуем число в строку
    display.setCursor(70, 5);
    display.print(playerScoreStr);
    
    itoa(player2Score, playerScoreStr, 10);  // Преобразуем число в строку
    display.setCursor(70, 20);
    display.print(playerScoreStr);
}


// Движение врагов
void ObjectSetDestPoint(TObject *obj, float xPos1, float yPos1, float xPos2, float yPos2, float vecSpeed){
    // Находим расстояние между объектом и точкой назначения
    float dx;
    float dy;
    if((xPos1 - obj->pos.x) < (xPos2 - obj->pos.x)) dx = xPos1 - obj->pos.x;
    else dx = xPos2 - obj->pos.x;
    if((yPos1 - obj->pos.y) < (yPos2 - obj->pos.y)) dy = yPos1 - obj->pos.y;
    else dy = yPos2 - obj->pos.y;

    TPoint xyLen = point(dx, dy);

    // Находим расстояние по прямой
    float dxy = sqrt(xyLen.x*xyLen.x + xyLen.y*xyLen.y);
    // Задаем скорость по каждой оси
    obj->speed.x = xyLen.x/dxy*vecSpeed;
    obj->speed.y = xyLen.y/dxy*vecSpeed;
}


TObject player1; // Создаем персонажа 1
TObject player2; // Создаем персонажа 2
PObject mas = NULL; // массив врагов
int masCnt = 0; // Счетчик количества врагов


// Перемещение объектов
void ObjectMove(TObject *obj){
    if(obj->oType == 'e')
        if(rand()%40 == 1){
            static float enemySpeed = -1.5;
            ObjectSetDestPoint(obj, player1.pos.x, player1.pos.y, player2.pos.x, player2.pos.y, enemySpeed);
        }

    if(!(((obj->pos.x + obj->speed.x) < 0) || ((obj->pos.x + obj->speed.x + obj->size.x) > 84)))
        obj->pos.x += obj->speed.x;
    if(!(((obj->pos.y + obj->speed.y) < 0) || ((obj->pos.y + obj->speed.y + obj->size.y) > 48)))
        obj->pos.y += obj->speed.y;




    for(int i = 0; i < masCnt; i++){
        //client.println("4 " + String((int)mas[i].speed.x) + " " + String((int)mas[i].speed.y) + " " + String(i)); 
        
        if((obj->oType == 'p')   && (ObjectCollision(*obj, mas[i]))){
            player1Score++;
            mas[i].isDel = true;
            client.println("3 " + String(i));
            client.println("1 " + String(player1Score) + " " + String(player2Score));
            client.println("0 0 0");            
            MelodyLevelUp();
        }
        if((obj->oType == 'x')  && (ObjectCollision(*obj, mas[i]))){
            player2Score++;
            mas[i].isDel = true;
            client.println("3 " + String(i));
            client.println("1 " + String(player1Score) + " " + String(player2Score)); 
            client.println("0 0 0");
            MelodyGameOver();
        }
    }
}


// Создает элементы массива врагов
PObject NewObject(){
    masCnt++;
    mas = realloc(mas, sizeof(*mas)*masCnt);
    return mas + masCnt - 1;
}


// Генерация новых врагов
void GenNewEnemy(){
    int pos1 = rand()%60;
    int pos2 = rand()%30;
    int k = rand()%100;
    if(k == 1) {
      AddEnemy(pos1, pos2);
      client.println("2 " + String(pos1) + " " + String(pos2));       
    }
}


// Удаляет помеченные объекты
void DelObject(){
    int i = 0;
    while(i < masCnt){
        if(mas[i].isDel){
            masCnt--;
            mas[i] = mas[masCnt];
            mas = realloc(mas, sizeof(*mas)*masCnt);
        }
        else{
            i++;
        }
    }
}


// Обработчик клавиш
void PlayerControl(){
    if (digitalRead(swPin) != HIGH) Serial.println ("CLICK!");
    int X = analogRead(pinX);              // считываем значение оси Х
    int Y = analogRead(pinY);              // считываем значение оси Y

    int len = client.available();
    if (len > 0) {
      char buffer[10];
      client.read(buffer, len);
      char *mes_str = strtok(buffer, " \n");
      player1.speed.x = atoi(mes_str);      
      mes_str = strtok(NULL, "\n");
      player1.speed.y = atoi(mes_str);
      
    Serial.print("X = ");
    Serial.print(player1.speed.x);
    Serial.print("\t");                    // табуляция
    Serial.print("Y = ");
    Serial.println(player1.speed.y);
    }

    
    /*Serial.print("X = ");
    Serial.print(X);
    Serial.print("\t");                    // табуляция
    Serial.print("Y = ");
    Serial.println(Y);*/
  
    static int playerSpeed = 4;
    player2.speed.x = 0;
    player2.speed.y = 0;
    if(Y > 634) player2.speed.y = -playerSpeed;
    if(Y < 334) player2.speed.y = playerSpeed;
    if(X < 387) player2.speed.x = -playerSpeed;
    if(X > 587) player2.speed.x = playerSpeed;
    if((player2.speed.x != 0) && (player2.speed.y != 0)) player2.speed = point(player2.speed.x * 0.7, player2.speed.y * 0.7);


    client.println("0 " + String((int)player2.speed.x) + " " + String((int)player2.speed.y));   
}


// Инициализация игры
void GameInit(){
    ObjectInit(&player1, 12, 12, 11, 8, 'p');
    ObjectInit(&player2, 62, 12, 12, 8, 'x');
    /*ObjectInit(NewObject(), 50, 12, 8, 8, 'e');
    client.println("2 " + String(50) + " " + String(12));
    ObjectInit(NewObject(), 50, 37, 8, 8, 'e');
    client.println("2 " + String(50) + " " + String(37));*/
}


// Перемещение объектов
void GameMove(){
    PlayerControl();
    ObjectMove(&player1);
    ObjectMove(&player2);

    for(int i = 0; i < masCnt; i++){
        ObjectMove(mas + i);
    }

    GenNewEnemy();
    DelObject();

    // Очищаем экран
    display.clearDisplay();

    ObjectShow(player1);
    ObjectShow(player2);

    for(int i = 0; i < masCnt; i++)
        ObjectShow(mas[i]);

    display.display();
    delay(70);
}
