#include "game.h"

#include <SPI.h>

#include <Adafruit_GFX.h>     // Библиотеки работы с дисплеем Nokia 5110
#include <Adafruit_PCD8544.h> //
Adafruit_PCD8544 display = Adafruit_PCD8544(3, 4, 5, 6, 7); // Инициализация пинов дисплея

#include <Ethernet.h>
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
char server[] = "192.168.0.101";
IPAddress ip(192, 168, 0, 102);
IPAddress myDns(192, 168, 0, 1);
EthernetClient client;

#define pinX    A2  // ось X джойстика
#define pinY    A1  // ось Y джойстика
#define swPin    8  // кнопка джойстика
#define ledPin  13  // светодиод на Pin 13

#define pinTone 9  // динамик
#define tonePin 9  // для playUSSR


// подключаем SD-карту
//#include <SD.h>
//File myFile;  // файл


double t = 0; // Для движения волны



void setup() {
  pinMode(ledPin, OUTPUT);
     
  pinMode(pinX, INPUT);       // джойстик
  pinMode(pinY, INPUT);       //
  pinMode(swPin, INPUT);      //
  digitalWrite(swPin, HIGH);  //

  pinMode(pinTone, OUTPUT);   // динамик
    
  // инициализация и очистка дисплея
  display.begin();
  display.clearDisplay();
  display.display();

  display.setContrast(50); // установка контраста
  delay(1000);

  Serial.begin(9600); // Открываем COM-порт, скорость 9600 bps
  while (!Serial); // Ждем пока Serial будет готов
  Serial.println("LCD start");


  MelodyLevelUp();


/*
pinMode(10, OUTPUT);
if (!SD.begin(10)) {
  Serial.println("initialization failed!");
  return;
}
Serial.println("initialization done.");
// открываем файл для считывания данных:
myFile = SD.open("Flag.txt");

if (myFile) {
  Serial.println("test.txt:");
  // считываем все данные из файла:
  while (myFile.available()) {
    Serial.write(myFile.read());
  }
  // закрываем файл:
  myFile.close();
} else {
  // если файл не открылся, отображаем сообщение об ошибке:
  Serial.println("error opening Flag.txt");
}*/


 


  // start the Ethernet connection:
  Serial.println("Initialize Ethernet with DHCP:");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // Check for Ethernet hardware present
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
      while (true) {
        delay(1); // do nothing, no point running without Ethernet hardware
      }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    // try to configure using IP address instead of DHCP:
    Ethernet.begin(mac, ip, myDns);
  } else {
    Serial.print("  DHCP assigned IP ");
    Serial.println(Ethernet.localIP());
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);
  Serial.print("connecting to ");
  Serial.print(server);
  Serial.println("...");

  // if you get a connection, report back via serial:
  if (client.connect(server, 1234)) {
    Serial.print("connected to ");
    Serial.println(client.remoteIP());
    // Make a HTTP request:
    client.println("300");
    //client.println("Host: www.google.com");
    //client.println("Connection: close");
    //client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }

  

  MelodyGameOver(); 

  GameInit(); // Инициализация игры
}


void loop() {
  boolean ledState = digitalRead(swPin); // считываем состояние кнопки
  digitalWrite(ledPin, ledState);        // вкл./выкл. светодиод

  /*int X = analogRead(pinX);              // считываем значение оси Х
  int Y = analogRead(pinY);              // считываем значение оси Y


  client.println(X/2);*/
  //Serial.print("X = ");
  //Serial.print(X);
  //Serial.print("-");
  //Serial.print((int)(84.*X/1023.));                       // выводим в Serial Monitor
  //Serial.print("\t");                    // табуляция
  //Serial.print("Y = ");
  //Serial.print(Y);
  //Serial.print("-");
  //Serial.print((int)(48.-48.*Y/1023.));
  //Serial.print("\t");                    // табуляция
  // Состояние кнопки
  //Serial.print("button = ");
  //if (digitalRead(swPin) != HIGH) Serial.println ("CLICK!");

  
  GameMove();


  /*t += 20;
  if(t > 1000) t = 0;
  Flag(5, 5, (int)t); */ 

  // окружность в центре
  /*display.drawCircle((int)(84.*X/1023.), (int)(48.-48.*Y/1023.), 2, BLACK);
  display.display();
  
  delay(70); */
/*
  // пиксел
    display.clearDisplay();
    display.drawPixel(10, 10, BLACK);
    display.display();
    delay(1000);

    // линия
    display.clearDisplay();
    display.drawLine(0, 0, 50, 30, BLACK);
    display.display();
    delay(1000); 

    // прямоугольник
    display.clearDisplay();
    display.drawRect(0, 0, 10, 10, BLACK);
    display.display();
    delay(1000); 

    // прямоугольник залитый
    display.clearDisplay();
    display.fillRect(0, 0, 10, 10, BLACK);
    display.display();
    delay(1000); 

    // треугольник
    display.clearDisplay();
    display.drawTriangle(0, 0, 40, 40, 30, 20, BLACK);
    display.display();
    delay(1000); 

    // окружность в центре
    display.clearDisplay();
    display.drawCircle(display.width()/2, 
                       display.height()/2, 10, BLACK);
    display.display();
    delay(1000); 
    */
}
