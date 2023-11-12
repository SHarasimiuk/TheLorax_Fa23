#include <Servo.h>

// Creating a variable for each Servo
Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;

// Creating variables for each Switch and assigning them an Arduino pin
const int Switch1 = 13;
const int Switch2 = 12;
const int Switch3 = 8;
const int Switch4 = 7;
const int Switch5 = 4;
const int Switch6 = 2;

void setup() {
  // Assigning each Servo an Arduino pin
  Servo1.attach(9);
  Servo2.attach(6);
  Servo3.attach(5);
  Servo4.attach(3);

  // Making sure each Switch is an input
  pinMode(Switch1, INPUT);
  pinMode(Switch2, INPUT);
  pinMode(Switch3, INPUT);
  pinMode(Switch4, INPUT);
  pinMode(Switch5, INPUT);
  pinMode(Switch6, INPUT);

  // Setting all Servos to 0 degrees at the beginning
  Servo1.write(0);
  Servo2.write(0);
  Servo3.write(0);
  Servo4.write(0);
}

void loop() {
  // First interaction (open door)
  if (digitalRead(Switch1) == HIGH){
    Servo1.write(90);
  }
  // Second interaction (close door)
  if (digitalRead(Switch2) == HIGH){
    Servo1.write(0);
  }
}
