//Raymond
//ServoMotor controlled by a potentiometer 
//uses the Arduino Servo library
#include <Servo.h>


int ledPin = 5;
int buttonApin = 2; //on uno, pin 2 and 3 allow interrupts
volatile byte ledState = LOW; 
bool on = false;
/*A variable should be declared volatile 
whenever its value can be changed by something beyond the control 
of the code section in which it appears, such as a concurrently 
executing thread. In the Arduino, the only place 
that this is likely to occur is in sections of code associated with 
interrupts, called an interrupt service routine. */

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
  
  //read from POT
  int wiperValue = analogRead(wiper);  //note analogRead can return from 0 - 1023
  
  
  //map the wipeValue to the PWM control for the motor
  int motorControlValue = map(wiperValue, 5, 1023, 0, 180); //note: servo motor rotates from 0 to 180
  
  //write to control servoMotor
  servoObj.write(motorControlValue);
  //delay(100);
  Serial.println(motorControlValue);

}

void ISR_LED() {
  //ledState = !ledState;
  on = !on;
  
  Serial.print("Button Pressed\n");
}
