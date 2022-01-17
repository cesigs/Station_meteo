/*#include <Arduino.h>
#include <SoftwareSerial.h>
#include "avr8-stub.h"
#include <stdio.h>
#include <ChainableLED.h>
#include <SPI.h> //sd card
#include <Wire.h>*/
#include "bme280.h"
#include "LED.h"
#include "lum.h"
#include "clock.h"
#include "GPS.h"
#include "SDconf.h"
int mode;
int temptotal;
int time1;
int LOG_INTERVAL;




void boutonv(){ //bouton vert
  //Serial.println("boutonvert");
  static unsigned long tempsv=0;

  if (tempsv==0){
    Serial.println("appui sur le bouton vert");
    tempsv=millis();
  }
  else{
    if (mode == 0){
      if ((millis()-tempsv)<1000){ 
        Serial.println("rebond sur le bouton vert");
      }
      else{
        //Serial.println(millis()-tempsv);
        if((millis()-tempsv)>2000){
          //instruction appui long
          mode = 2;

          colorR = 0;
          colorG = 0;
          colorB = 255;

          tempsv=0;
          Serial.println("appui long");
          tempsv=0;
        }
        else{
          //instruction appui court
          tempsv=0;
        }

      }
    }
  }
  leds.setColorRGB(0, colorR, colorG, colorB);
}

void boutonr(){
if (millis() < 160000){
  static unsigned long temps=0;

  if (temps==0){
    Serial.println("appui sur le bouton rouge");
    temps=millis();
  }
  else{
    if ((millis()-temps)<1000){ 
      //Serial.println("rebond sur le bouton rouge");
    }
    else{
      
      if((millis()-temps)>2000){
        Serial.println("appui long rouge");
        if (mode == 0){
          mode = 3;
          colorR = 0;
          colorG = 255;
          colorB = 0;
          temps = 0;
        }
        
      }
      else{
        //instruction appui court
        temps=0;
      }

    }
  }
  leds.setColorRGB(0, colorR, colorG, colorB);
}
  static unsigned long temps=0;

  if (temps==0){
    Serial.println("appui sur le bouton rouge");
    temps=millis();
  }
    else{
    if ((millis()-temps)<1000){ 
      //Serial.println("rebond sur le bouton rouge");
    }
    else{
      
      if((millis()-temps)>2000){
      Serial.println("appui long rouge");
        if (mode == 0){
          mode = 1;

          colorR = 255; //orange
          colorG = 128;
          colorB = 0;

          Serial.println("ca marche");
        }
          else {
            if (mode == 1){
              mode = 0;

              colorR = 0; //vert
              colorG = 255;
              colorB = 0;              
            }
            else{
              if (mode == 2){
              mode = 0;

              colorR = 0; //vert
              colorG = 255;
              colorB = 0; 

              }
              else {
                if (mode == 3){
                mode = 0;
                colorR = 0; //vert
                colorG = 255;
                colorB = 0; 

                /*colorR = 255; //jaune
                colorG = 255;
                colorB = 0;*/
              }
            }
          }
        }
        temps = 0;
      }
      else{
        //instruction appui court
        temps=0;
      }

    }
    }
  leds.setColorRGB(0, colorR, colorG, colorB);
}


void setup() {
  Serial.begin(9600);
  SoftSerial.begin(9600);                 // the SoftSerial baud rate
  LOG_INTERVAL = 5000; //temps entre les 

  pinMode(A0,OUTPUT);

  pinMode(2,INPUT);
  pinMode(3,INPUT);

  pinMode(interruptPin,INPUT_PULLUP);
  attachInterrupt(0,boutonr,CHANGE);
  attachInterrupt(1,boutonv,CHANGE);
  mode = 0;
/* //initialisation de la clock
      clock.begin();
      clock.fillByYMD(2021,10,21);//Oct 18,2021
      clock.fillByHMS(20,42,00);//15:52 00"
      clock.fillDayOfWeek(THU);
      clock.setTime();//write time to the RTC chip
*/
}


void loop() { 
  leds.setColorRGB(0, colorR, colorG, colorB);
  if (mode == 0){ //mode Standard
    //Serial.println();
  Serial.println("");
  sysclock();
  bme();
  lum();
  GPS();
  delay(LOG_INTERVAL);
  }
  if (mode == 1){ //mode Maintenance
  Serial.println("");
  sysclock();
  bme();
  lum();
  GPS();
  delay(LOG_INTERVAL); 
  }
  if (mode == 2){ //mode Economie
  Serial.println("");
  sysclock();
  bme();
  lum();
  GPS();
  delay(2*LOG_INTERVAL); 
  Serial.println("");
  sysclock();
  bme();
  lum();
  delay(2*LOG_INTERVAL); 
  }
  if (mode == 3){ //mode Configuration
    Serial.println("3");
  }
}

