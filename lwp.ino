#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include <SD.h>
#include <SPI.h>

File file;

RTC_DS1307 rtc;
LiquidCrystal_I2C lcdekran(0x27,20,4);
int dy,mnth,yr,hr,mnt,scnd;
int randNumber;
long oldnumber;
int randarray;
const int button1pin=7;
const int button2pin=6;
const int button3pin=5;
int myarray[49]={};
int x;

void setup () {
  Serial.begin(9600);
  lcdekran.init(); 
  lcdekran.backlight();

  while (!Serial); 
  delay(100);
  if (! rtc.begin()) {
    lcdekran.print("Couldn't find RTC");
    delay(1000);
    lcdekran.clear();
    Serial.flush();
    while (1) delay(10);
  }else{
    lcdekran.print("RTC is ready");
    delay(1000);
    lcdekran.clear();
    }
  
  if(SD.begin(10)){
    lcdekran.print("SD Card is ready");
    delay(1000);
    lcdekran.clear();
    
    }else{
      lcdekran.print("Error");
    delay(1000);
    lcdekran.clear();
         }
         for(int i=0;i<=50;i++){
      myarray[i]=randNumber;
      File file = SD.open("ticketss.txt",FILE_WRITE);
      file.print(i);
      file.print(". Bilet =");
      file.print(myarray[i]);
      file.print("\n");
      randNumber= random(1000,9999);
      file.close();
      }
    
    

    mainmenu();
   
}
void mainmenu(){
   lcdekran.clear();
   lcdekran.setCursor(1,0);
   lcdekran.print("Lottery Winner");
   lcdekran.setCursor(4,1);
   lcdekran.print("Project!");

  }

void number(){
  
  lcdekran.clear();
  randarray= random(0,50);
  x=myarray[randarray];
  delay(100);
  lcdekran.setCursor(0,0);
  lcdekran.print("Winner: ");
  lcdekran.print(x);
  lcdekran.print(" ");
  lcdekran.print(randarray);
  
  }
void date(){
    DateTime now = rtc.now();
    dy= now.day();
    mnth = now.month();
    yr=now.year();
    hr=now.hour();
    mnt=now.minute();
    scnd=now.second();
    lcdekran.setCursor(0,1);
    lcdekran.print(dy);
    lcdekran.print(".");
    lcdekran.print(mnth);
    lcdekran.print(".");
    lcdekran.print(yr-2000);
    lcdekran.print(" ");
    lcdekran.print(hr);
    lcdekran.print(":");
    lcdekran.print(mnt);
    lcdekran.print(":");
    lcdekran.print(scnd);
    
  }
void save(){
    lcdekran.clear();
    if(oldnumber==randarray){
      lcdekran.print("Please draw lot!");
      delay(1000);
      return mainmenu();
      }
    File file = SD.open("lw.txt",FILE_WRITE);
    delay(500);
    file.print("Winner: ");
    file.print(x);
    file.print(" ");
    file.print("DateTime: ");
    file.print(dy);
    file.print(".");
    file.print(mnth);
    file.print(".");
    file.print(yr-2000);
    file.print(" ");
    file.print(hr);
    file.print(":");
    file.print(mnt);
    file.print(":");
    file.print(scnd);
    file.print(" Bilet sayısı:");
    file.print(randarray);
    file.print("\n");
    file.close();
    for(int i=0;i<=99;i++){
      delay(20);
      lcdekran.setCursor(5,0);
      lcdekran.print("Saving");
      lcdekran.setCursor(7,1);
      lcdekran.print("%");
      lcdekran.print(i);  
    }
    delay(100);
    lcdekran.clear();
    lcdekran.setCursor(3,0);
    lcdekran.print("Data saved");
    lcdekran.setCursor(2,1);
    lcdekran.print("Succesfully!");
    delay(1000);
    mainmenu();
  }
  void oku(){

    file = SD.open("lw.txt");
    while(file.available()){
      Serial.write(file.read());
      }
    file.close();
    delay(500);
    
    }

void loop () {
    if(digitalRead(button1pin)==1){
      number();
      date();
      
    }
    if(digitalRead(button2pin)==1){
      save();
      }
      if(digitalRead(button3pin)==1){
        oku();
        }
    

}
