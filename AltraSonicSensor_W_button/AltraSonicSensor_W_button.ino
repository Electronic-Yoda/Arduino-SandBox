//Raymond
//ServoMotor controlled by a potentiometer 
//uses the Arduino Servo library
#include "Servo.h"
#include "SR04.h"

#define TRIG_PIN 11
#define ECHO_PIN 10

int ledPin = 5;
int buttonApin = 2; //on uno, pin 2 and 3 allow interrupts
bool on = false;

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

Servo servoObj;
const byte motorControl = 9;
const byte motorPower = 4;
const byte wiper = A0;

//ISR function declaration
void ISR_LED();

void setup() {
  // put your setup code here, to run once:
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  Serial.begin(9600);

  //set up interrupts
  attachInterrupt(digitalPinToInterrupt(buttonApin), ISR_LED, FALLING);
  //Note: FALLING is for when the pin goes from high to low.

  servoObj.attach(motorControl);//connect pin 9 with the control line(the middle line of Servo) 
  //servoObj.write(90);// move servos to center position -> 90°
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!on) {
    digitalWrite(ledPin, LOW);  
    return; 
  }
  
  digitalWrite(ledPin, HIGH);  
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");//The difference between "Serial.print" and "Serial.println" 
                        //is that "Serial.println" can change lines.
   delay(1000);


}

void ISR_LED() {
  on = !on;
  
  Serial.print("Button Pressed\n");
}
