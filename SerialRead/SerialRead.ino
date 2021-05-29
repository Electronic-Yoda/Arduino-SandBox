String incomingString; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming string:
    incomingString = Serial.readString();

    // print to serial monitor
    Serial.print("Received: ");
    Serial.println(incomingString);
  }
}
