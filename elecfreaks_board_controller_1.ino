#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(13, 12);

int up_button     = 2;//4; // Boton Amarillo - A
int down_button   = 4;//5; // Boton Amarillo - C 
int left_button   = 5;//6; // Boton Azul     - D 
int right_button  = 3; // Boton Azul     - B
int start_button  = 6; // Boton F
int select_button = 2; // Boton E
int analog_button = 8; // 
int x_axis = A0;
int y_axis = A1;
int buttons[]={up_button, down_button,left_button,
               right_button,start_button,select_button,analog_button};


const uint64_t pipe = 0xE8E8F0F0E1LL;
//RF24 radio(CE_PIN,CSN_PIN);
char msg[20] = "";

void setup(){
     for(int i = 2; i <7 ; i++)
     {
         pinMode(buttons[i],INPUT);
         digitalWrite(buttons[i],HIGH);  
     } 
     Serial.begin(9600);
     Bluetooth.begin(9600);
//     radio.begin();
//     radio.openWritingPipe(pipe);
}

void loop(){
     //한번에 하나의 명령어만 처리한다.
      if(digitalRead(up_button)==LOW)
      {        
        Serial.print("W");
        Bluetooth.write("W");
      }
      else if(digitalRead(down_button)==LOW)
       {
        Serial.print("S");
        Bluetooth.write("S");
      }
      else if(digitalRead(left_button)==LOW)
      {
        Serial.print("A");
        Bluetooth.write("A");
      }
      else if(digitalRead(right_button)==LOW)
       {
        Serial.print("D");
        Bluetooth.write("D");
      }
      else if(digitalRead(start_button)==LOW)
       {
        Serial.print("m"); // 조종 모드
        Bluetooth.write("m");
      }
      else if(digitalRead(select_button)==LOW)
       {
        Serial.print("x"); // 자율주행 모드
        Bluetooth.write("x");
      }
      else if( analogRead(x_axis) < 100 )
      { 
        Serial.print( "L" ); 
        Bluetooth.write("L");
      } //Left
      else if( analogRead(x_axis) > 600 )
      { 
        Serial.print( "R" );
        Bluetooth.write("R");
       } //right
      else if( analogRead(y_axis) < 100 )
      { 
        Serial.print( "B");
        Bluetooth.write("B");
       } //backward
      else  if( analogRead(y_axis) > 600 )
      {
        Serial.print( "F" );
        Bluetooth.write("F");
      } //forward
      else if(digitalRead(analog_button)==LOW)
       {
        Serial.print("X"); // 조종 모드
        Bluetooth.write("X");
      }
      else
      {
        Serial.print( "X" ); //stop
        Bluetooth.write("X"); 
      }

    delay(100); // 0.1초마다 새로운 명령어를 받아 들인다. 
}
