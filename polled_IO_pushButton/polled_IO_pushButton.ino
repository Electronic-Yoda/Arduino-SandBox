//Single button to turn LED on and off

int ledPin = 5;
int buttonApin = 9;
bool on;
void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  on = false;
}

void loop() 
{
  
    
    if (digitalRead(buttonApin) == LOW)
    {
      if (!on){
        
        digitalWrite(ledPin, HIGH);
        delay(500); // delay 0.5 s
        on = true;
      }
      else {
        digitalWrite(ledPin, LOW);
        delay(500); // delay
        on = false;
      }
      //on = true;
    }
    
}
