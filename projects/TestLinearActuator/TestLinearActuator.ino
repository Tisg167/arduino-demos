/*
  TestLinearActuator.ino
  
  Wiring:
  Blue wire --> Arduino Digital PWM Pin
  Purple wire --> Arduino Analog Pin
  Red wire --> 12V power
  Black wire --> Ground
 
 */
/* --- Header --- */
#define BAUD 9600
#define ACTUATOR_POSITION_PIN 0
#define ACTUATOR_PWM_PIN 10

/* --- Global Declarations --- */
int actuator_position = 0; // Temporary value for storing the position feedback
int actuator_retracted = 0; // Value for storing position feedback of the retracted position

/* --- Setup --- */
void setup() {
  Serial.begin(BAUD); // initialize serial communications at 9600 bps:
}

void loop() {
  
  // Fully extend the actuator.
  for (int i = 0; i < 255; i++) {
    
    // Control actuator and get position feedback.
    analogWrite(ACTUATOR_PWM_PIN, i);
    actuator_position = analogRead(ACTUATOR_POSITION_PIN);
    if (i == 0) {
      actuator_retracted = actuator_position;
    }
    
    // Wait 2 milliseconds before for the analog-to-digital converter to settle.
    delay(100);
    
    // Display values to serial monitor.
    Serial.print("Position: ");
    Serial.print(i);
    delay(100);
    Serial.print("\t Corresponding Value: " );                       
    Serial.print(actuator_position); 
  }    

  // Fully retract the actuator.
  analogWrite(ACTUATOR_PWM_PIN, 0);
  while (analogRead(ACTUATOR_POSITION_PIN) != actuator_retracted) {
    delay(100); // wait until the actuator has returned to the starting position.
  }
}
