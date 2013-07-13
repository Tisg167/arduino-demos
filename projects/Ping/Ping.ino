/*
  Ping.ino
  Simply prints 'ping' continously to serial port.
*/

/* --- Headers --- */
#define BAUD 9600
#define INTERVAL 1000

/* --- Setup --- */
void setup(){
  Serial.begin(BAUD);
}

/* --- Loop --- */
void loop(){
  Serial.println("ping");
  delay(INTERVAL);
  Serial.flush();
}

