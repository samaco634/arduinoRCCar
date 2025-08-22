/*
  
  JoystickArduinoBasicExample.pde
  
  A basic sketch to demonstrate reading values from the joystick shield
  
  How to use:
  
    * Connect joystick shield to your Arduino
    * Upload this sketch to your Arduino
    * Open the Arduino IDE Serial Monitor (set to 9600 baud)
    * Waggle joystick, push buttons
  
  Requires:
  
    * Arduino
    * SparkFun Joystick Shield

  Written for SparkFun Arduino Inventor's Kit CIRC-JOY

  Based on original example by Ryan Owens

 */
//#include <SoftwareSerial.h>

//SoftwareSerial mySerial(12, 13); // RX, TX  (bluebooth모듈 기준 TX, RX)


// Store the Arduino pin associated with each input
const byte PIN_BUTTON_SELECT = 6; // Select button is triggered when joystick is pressed //E
const byte PIN_BUTTON_CANCEL = 7;

const byte PIN_BUTTON_RIGHT = 3;
const byte PIN_BUTTON_UP = 2;
const byte PIN_BUTTON_DOWN = 4;
const byte PIN_BUTTON_LEFT = 5;

const byte PIN_ANALOG_X = 0;
const byte PIN_ANALOG_Y = 1;
const byte PIN_ANALOG_BUTTON = 8;

void setup() {
  Serial.begin(9600);

  // Specify each pin connected to a pushbutton as an input.
  // Also enable the Arduino's internal "pull-up" resistors
  // for each pushbutton we want to read--this means the shield
  // doesn't need to have resistors on it.
  // Note that when a pull-up resistor is used on a pin the
  // meaning of the values read are reversed compared to their
  // usual meanings:
  //    * HIGH = the button is not pressed
  //    * LOW = the button is pressed  

  for(int i= 2; i < 9; i++)
  {
  pinMode(2, INPUT);  
  digitalWrite(9, HIGH);
  }
}


void loop() {
  // Print the current values of the inputs (joystick and
  // buttons) to the console.
  if(digitalRead(PIN_BUTTON_UP) == LOW)
  {
     Serial.print("a");
  }
  else if(digitalRead(PIN_BUTTON_DOWN) == LOW)
  {
    Serial.print("c");
  }
  else if(digitalRead(PIN_BUTTON_LEFT) == LOW)
  {
     Serial.print("d");
  }
  else if(digitalRead(PIN_BUTTON_RIGHT) == LOW)
  {
    Serial.print("b");
  }
  else if(digitalRead(PIN_BUTTON_SELECT) == LOW)
  {
    Serial.print("e");
  }
  else if(digitalRead(PIN_BUTTON_CANCEL) == LOW)
  {
     Serial.print("f");
  }
  else if(digitalRead(PIN_ANALOG_BUTTON) == LOW)
  {
    Serial.print("q");
  }
  else if( analogRead(PIN_ANALOG_X) == 0 ){ Serial.print( "L" ); } //go
  else if( analogRead(PIN_ANALOG_X) > 550 ){ Serial.print( "R" ); } //stop

  else if( analogRead(PIN_ANALOG_Y) == 0 ){ Serial.print( "D"); } //down
  else  if( analogRead(PIN_ANALOG_Y) > 550 ){ Serial.print( "U" ); } //up
  else
  {Serial.print( "X" ); }

  delay(100); // 0.5초마다 새로운 명령어를 받아 들인다. 
}
