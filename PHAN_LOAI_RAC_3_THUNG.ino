#include <Servo.h>
Servo Servo1;
Servo Servo2;
Servo Servo3;
#define cb1 A0
#define cb2 A1
#define cb3 A2
#define relay 7
#define cbquang 2
#define den 3
long time1,time2,time3;
long thoigian = 5000;
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(A3, A4); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  delay(1000); 
  Serial.println(F("DFPlayer Mini online."));
  Servo1.attach(4);
  Servo2.attach(5);
  Servo3.attach(6);
  Servo1.write(0);
  Servo2.write(0);
  Servo3.write(0);
  pinMode(cb1, INPUT_PULLUP);
  pinMode(cb2, INPUT_PULLUP);
  pinMode(cb3, INPUT_PULLUP);
  pinMode(cbquang, INPUT_PULLUP);
  pinMode(relay, OUTPUT);
  pinMode(den, OUTPUT);
  myDFPlayer.volume(30);
  Serial.println(F("DFPlayer Mini online."));
  
}
void phatnhac(){
  myDFPlayer.play(1); 
  delay(5500);
}
void loop() {
  ///Điều khiển servo 1
  if(digitalRead(cb1) == 0){
    if(millis() - time1 >= thoigian){
      Servo1.write(90);
      phatnhac();
    }
  }
  else {
    Servo1.write(0);
    time1 = millis();
  }

  ///Điều khiển servo 2
  if(digitalRead(cb2) == 0){
    if(millis() - time2 >= thoigian){
      Servo2.write(90);
      phatnhac();
    }
  }
  else {
    Servo2.write(0);
    time2 = millis();
  }

  ///Điều khiển servo 3
  if(digitalRead(cb3) == 0){
    if(millis() - time3 >= thoigian){
      Servo3.write(90);
      digitalWrite(relay, HIGH);
      phatnhac();
      
    }
  }
  else {
    Servo3.write(0);
    time3 = millis();
    digitalWrite(relay, LOW);
  }
  if(digitalRead(cbquang) == 1){
    digitalWrite(den, HIGH);
  }
  else digitalWrite(den, LOW);

  

}
