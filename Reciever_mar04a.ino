int incomingByte;
void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {
if (Serial.available() > 0) {
  incomingByte = Serial.read();

  Serial.print(incomingByte, DEC);
  Serial.print( ' ' );
  Serial.println(incomingByte, HEX);
}
}
