char mystr[5] = "200";
char mystr2[5] = "100";//String data

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {
  Serial.write(200); //Write the serial data
  delay(1000);
  Serial.write(100); //Write the serial data
  delay(1000);
}
