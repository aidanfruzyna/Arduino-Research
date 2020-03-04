const int led1=9;
const int led2=8;
int light;

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);}

void loop() {{
  Serial.println(light); //Print data on Serial Monitor
}
  if (Serial.available()>0) {
    light=Serial.read();
  }
  delay(1000);
  if (light == 200){
  digitalWrite(led1, HIGH);
  } 
  else {
    digitalWrite(led1, LOW);
    }
    if (light == 100){
      digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
    }
  }
