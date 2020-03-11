void setup() {
   pinMode(4, OUTPUT);
}

void loop() {
  buzz(4, 2500, 500);
  delay(1000);
}
void buzz(int targetPin, long frequency, long length){
  long delayValue = 1000000/frequency/2;
  long numCycles = frequency * length/1000;
  for (long i=0; i < numCycles; i++){
    digitalWrite(targetPin, HIGH);
    delayMicroseconds(delayValue);
    digitalWrite(targetPin, LOW);
    delayMicroseconds(delayValue);
  }
}
