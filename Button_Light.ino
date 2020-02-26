const int led1=12;
const int led2=10;
const int button1=13;
const int button2=12;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop() {
  int button1State=digitalRead(button1);
  int button2State=digitalRead(button2);

  if(button1State==LOW) {
    digitalWrite(led1, HIGH);
  } else{
    digitalWrite(led1,LOW);
}
if(button2State==LOW) {
    digitalWrite(led2, HIGH);
  } else{
    digitalWrite(led2,LOW);
  }
}
