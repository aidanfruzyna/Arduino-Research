int forward = 10;
int reverse = 9;
int button = 3;

void setup() {
  Serial.begin(9600);
  pinMode(forward,OUTPUT);
  pinMode(reverse,OUTPUT);
  pinMode(button,INPUT);
}

void setMotor(char select, char direct, int power)//Select: R/L, Direct: +/-, Speed: 0-63
{  int pack;
//Select motor
  if(select == 'R'){
    pack = 64;
  }
  else if(select == 'L'){
    pack = 192;
  }
  else{
    Serial.println("Error selecting motor");
    }
//Check that speed is with in allowed range
  if(power>63||power<0){
    Serial.println("Error too high of speed");
  }
//Apply speed based on direction 
  if(direct == '+'){
    digitalWrite(forward,HIGH);
    digitalWrite(reverse,LOW);
    pack += power;}
  else if(direct == '-'){
    digitalWrite(reverse,HIGH);
    digitalWrite(forward,LOW);
    pack -= power;}
  else{
    Serial.println("Error selecting direction");
    }
    if(power==0){
      digitalWrite(forward,LOW);
      digitalWrite(reverse,LOW);
    }
//Send serial to motor controller
  Serial.write(pack);
}

void stopMotors(){
  Serial.write(0x00);
  digitalWrite(forward,LOW);
  digitalWrite(reverse,LOW);
}

void loop() {
  while(digitalRead(button)==1){
  setMotor('R','+',5);
  setMotor('L','+',5);
  delay(1500);
  stopMotors();
  delay(500);
  setMotor('R','-', 5);
  setMotor('L','-', 5);
  delay(1500);
  setMotor('R','+',0);
  setMotor('L','+',0);
  delay(500); 
  }
}
