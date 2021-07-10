const int motorA1  = 6;
const int motorA2  = 11;
const int motorB1  = 10;
const int motorB2  = 5;
int state;
int vSpeed = 255;
void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
  }
  if (state == '0') {
    vSpeed = 0;
  }
  else if (state == '1') {
    vSpeed = 100;
  }
  else if (state == '2') {
    vSpeed = 180;
  }
  else if (state == '3') {
    vSpeed = 200;
  }
  else if (state == '4') {
    vSpeed = 255;
  }
  if (state == 'F') {
    analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);
    analogWrite(motorB1, vSpeed);      analogWrite(motorB2, 0);
  }
  else if (state == 'G') {
    analogWrite(motorA1, vSpeed ); analogWrite(motorA2, 0);
    analogWrite(motorB1, 100);    analogWrite(motorB2, 0);
  }
  else if (state == 'I') {
    analogWrite(motorA1, 100); analogWrite(motorA2, 0);
    analogWrite(motorB1, vSpeed);      analogWrite(motorB2, 0);
  }
  else if (state == 'B') {
    analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed);
    analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed);
  }
  else if (state == 'H') {
    analogWrite(motorA1, 0);   analogWrite(motorA2, 100);
    analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed);
  }
  else if (state == 'J') {
    analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed);
    analogWrite(motorB1, 0);   analogWrite(motorB2, 100);
  }
  else if (state == 'L') {
    analogWrite(motorA1, vSpeed);   analogWrite(motorA2, 150);
    analogWrite(motorB1, 0); analogWrite(motorB2, 0);
  }
  else if (state == 'R') {
    analogWrite(motorA1, 0);   analogWrite(motorA2, 0);
    analogWrite(motorB1, vSpeed);   analogWrite(motorB2, 150);
  }
  else if (state == 'S') {
    analogWrite(motorA1, 0);  analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
  }
}
