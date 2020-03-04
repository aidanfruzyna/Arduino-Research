void setup() {
  Serial.begin(9600);

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
    pack += power;}
  else if(direct == '-'){
    pack -= power;}
  else{
    Serial.println("Error selecting direction");
    }
//Send serial to motor controller
  Serial.write(pack);
}

void stopMotors(){
  Serial.write(0x00);
}

void loop() {
  setMotor('R','+',63);
  delay(2000);
  setMotor('L','+',63);
  delay(2000);
  stopMotors();
  delay(2000);
  setMotor('R','-', 40);
  setMotor('L','-', 40);
  delay(2000);
  stopMotors();
  delay(5000); 

}
