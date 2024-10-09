#include <AFMotor.h>
#include <Arduino.h>
#include <SoftwareSerial.h>

char  Command = 0;
int   Speed = 0;

AF_DCMotor motor1(1);

AF_DCMotor motor4(4);

AF_DCMotor motor2(2);

AF_DCMotor motor3(3);

#define LED1 A0
#define LED2 A1

void Left (){
  motor1.setSpeed(Speed);
   motor1.run(1);
  motor4.setSpeed(Speed);
   motor4.run(1);
  motor2.setSpeed(0);
   motor2.run(RELEASE);
  motor3.setSpeed(0);
   motor3.run(RELEASE);

}

void Right (){
  motor2.setSpeed(Speed);
   motor2.run(1);
  motor3.setSpeed(Speed);
   motor3.run(1);
  motor1.setSpeed(0);
   motor1.run(RELEASE);
  motor4.setSpeed(0);
   motor4.run(RELEASE);

}
void Stop (){
  motor1.setSpeed(0);
   motor1.run(RELEASE);
  motor2.setSpeed(0);
   motor2.run(RELEASE);
  motor3.setSpeed(0);
   motor3.run(RELEASE);
  motor4.setSpeed(0);
   motor4.run(RELEASE);

}
void Forward (){
  motor1.setSpeed(Speed);
   motor1.run(1);
  motor2.setSpeed(Speed);
   motor2.run(1);
  motor3.setSpeed(Speed);
   motor3.run(1);
  motor4.setSpeed(Speed);
   motor4.run(1);

}
void Backward (){
  motor1.setSpeed(Speed);
   motor1.run(2);
  motor2.setSpeed(Speed);
   motor2.run(2);
  motor3.setSpeed(Speed);
   motor3.run(2);
  motor4.setSpeed(Speed);
   motor4.run(2);

}
SoftwareSerial BTSerial(A4,A5);

void setup() {
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);

  digitalWrite(LED1,LOW); // LED off
  digitalWrite(LED2,LOW); // LED off

  Speed = 150;
  Stop();
}

//  char buffer[20];


void loop() {
      if(BTSerial.available()){
          Command = BTSerial.read();
          // Serial.println(Command);
          if((Command == 'S') || (Command == 'D')) {
              Stop();
          }
          else if(Command == 'F'){
              Forward();

          }
          else if(Command == 'B'){
              Backward();

          }
          else if(Command == 'R'){
              Right();

          }
          else if(Command == 'L'){
              Left();

          }
          else if(Command == 'W'){
              digitalWrite(LED1,HIGH); // LED on
              digitalWrite(LED2,HIGH); // LED on
          }
          else if(Command == 'w'){
              digitalWrite(LED1,LOW); // LED off
              digitalWrite(LED2,LOW); // LED off
          }
          else if(Command == 'q')
          {
              Speed = 255;
          }
          else if((Command >= '0') && (Command <= '9'))
          {
              Speed = (int)map((Command - 48) * 10, 0, 90, 100, 240);
          }
      }
}
