#define BAUD 9600
void setup() {
  Serial.begin(BAUD);
}

void loop() {
  Serial.println(1);
}
