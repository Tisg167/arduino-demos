
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.flush();
  Serial.println("$GPGGA,hhmmss.ss,llll.ll,a,yyyyy.yy,a,x,xx,x.x,x.x,M,x.x,M,x.x,xxxx*hh");
  delay(1000);
}

