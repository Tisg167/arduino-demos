/*
  License: Creative Commons 2013, Trevor Stanhope
  Updated: 2013-06-13
  
  Tests two standard servos (servos which can turn 180 deg).
  As it changes the position of the servos, the position is printed
  to the serial monitor.
  
  Wiring:
  Black servo wire --> Arduino GND 
  Red servo wire --> Arduino 5V
  Yellow (or sometimes white) servo wire --> Arduino Digital PWM Pin (see Headers)
  
*/

/* --- Headers --- */
#include "SoftwareSerial.h"
#include "stdio.h"
#include "Servo.h"
#define BAUD 9600 // Baud rate (rate of USB data transmission) for the serial monitor
#define LEFT_SERVO_PIN 9 // Digital pin number for left servo
#define RIGHT_SERVO_PIN 10 // Digital pin number for right servo

/* --- Declarations --- */
Servo left_servo;
Servo right_servo;

/* --- Setup --- */
// This runs once whenever the board is reset.
void setup() {
  
  // Start the servos on their respective pins
  left_servo.attach(LEFT_SERVO_PIN);
  right_servo.attach(RIGHT_SERVO_PIN);
  
  // Start the serial monitor with the proper baud rate
  Serial.begin(BAUD);
  
}

/* --- Loop --- */
// This loop runs continously.
void loop() {
  
  // Set the servos to the center position
  left_servo.write(90);
  right_servo.write(90);
  delay(1000); // wait 1000 milliseconds
  
  // Set the servos to the full counter clockwise position
  left_servo.write(0);
  right_servo.write(0);
  delay(1000); // wait 1000 milliseconds
  
  // Set the servos to the full clockwise position
  left_servo.write(180);
  right_servo.write(180);
  delay(1000); // wait 1000 milliseconds
  
}
