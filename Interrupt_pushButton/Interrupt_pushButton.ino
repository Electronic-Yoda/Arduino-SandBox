//Raymond
//Single button to turn LED on and off

int ledPin = 5;
int buttonApin = 2; //on uno, pin 2 and 3 allow interrupts
volatile byte ledState = LOW; 
/*A variable should be declared volatile 
whenever its value can be changed by something beyond the control 
of the code section in which it appears, such as a concurrently 
executing thread. In the Arduino, the only place 
that this is likely to occur is in sections of code associated with 
interrupts, called an interrupt service routine. */

//ISR function declaration
void ISR_LED();

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  Serial.begin(9600);
  //set up interrupts
  attachInterrupt(digitalPinToInterrupt(buttonApin), ISR_LED, FALLING);
  //Note: FALLING is for when the pin goes from high to low.
}

void loop() 
{   
    digitalWrite(ledPin, ledState);  
}

void ISR_LED() {
  ledState = !ledState;
  Serial.print("Button Pressed\n");
}
