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

// Variables for the Switch state of Switches 3, 4, and 5
int Switch3State = 0;
int LastSwitch3State = 0;
int Switch4State = 0;
int LastSwitch4State = 0;
int Switch5State = 0;
int LastSwitch5State = 0;

// Creating variables for counting how many times Switches 3 and 4 are activated
int Switch3Count = 0;
int Switch4Count = 0;

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

  // Set up serial communication
  Serial.begin(9600);
}

void loop() {
  // First interaction (open door)
  if (digitalRead(Switch1) == HIGH) {
    Servo1.write(90);
  }

  // Second interaction (close door)
  if (digitalRead(Switch2) == HIGH) {
    Servo1.write(0);
  }

  // Third interaction (cutting tree 1)
  Switch3State = digitalRead(Switch3);
  if (Switch3State != LastSwitch3State) {
    if (Switch3State == HIGH) {
      Switch3Count++;
    }
  }
  LastSwitch3State = Switch3State;
  if (Switch3Count == 4) {
    Servo2.write(180);
  }

  // Fourth interaction (cutting tree 2)
  Switch4State = digitalRead(Switch4);
  if (Switch4State != LastSwitch4State) {
    if (Switch4State == HIGH) {
      Switch4Count++;
    }
  }
  LastSwitch4State = Switch4State;
  if (Switch4Count == 4) {
    Servo3.write(180);
  }

  // Fifth and sixth interactions (backdrop change and ignoring Lorax) + enclosure reset
  Switch5State = digitalRead(Switch5);
  if (digitalRead(Switch6) == HIGH) {
    Servo4.write(180);
  } else {
    if (Switch5State == HIGH) {
      Servo4.write(90);
      LastSwitch5State = Switch5State;
    } else {
      if (Switch5State != LastSwitch5State) {
        if (digitalRead(Switch6) == LOW) {
          delay(2000);
          Servo4.write(0);
          Servo3.write(0);
          Servo2.write(0);
        }
      }
    }
  }
}
