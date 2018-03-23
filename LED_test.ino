int buzzPin = 9;
int btnPin = 2;
int state;
int sysOnOff;
int turnSys;
int modeSys;
/* 1. Mode a
   2. mode running led
   3. mode led kedip
*/
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  for (int i = 2; i <= 2; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(buzzPin, OUTPUT);
  pinMode(btnPin, INPUT_PULLUP);
  digitalWrite(buzzPin, HIGH);
  for (int i = 2; i <= 5; i++) {
    digitalWrite(i, HIGH);
  }
  state = 0;
  sysOnOff = 0;
  turnSys = 0;
  modeSys = 0;
}

void loop() {
  // put your main code here, to run repeatedly:



  if (digitalRead(btnPin) == LOW) {
    delay(1000);
    if (digitalRead(btnPin) == LOW) {
      state++;
      if (state == 2) {
        if (turnSys == 0) {
          sysOnOff = 1;
          turnSys = 1;
        } else {
          turnSys = 0;
          for (int i = 2; i <= 2; i++) {
            digitalWrite(i, HIGH);
          }
          modeSys=0;
        }
        state = 0;
      }
    }
    else {
      state = 0;
    }
  } else {
    state = 0;
  }

  if (sysOnOff == 1) {
    init_sys();
    sysOnOff = 0;
  }


  if (turnSys == 1) {
    if (digitalRead(btnPin) == LOW) {
      if (modeSys == 2) {
        modeSys = 0;
      }
      modeSys++;
    }
    if (modeSys > 0) {
      if (modeSys == 1) {
        runningLED();
      } else if (modeSys == 2) {
        flashingLED();

      }
    }
  }


}
void init_sys() {
  for (int i = 2; i <= 2; i++) {
    Serial.println("Blink cuy");
  }
Serial.println("Blink cuy");
}
void runningLED() {
  Serial.println("Mati");
  delay(100);
}

void flashingLED() {
//  digitalWrite(2, HIGH);
//  digitalWrite(3, HIGH);
//  digitalWrite(4, HIGH);
//  digitalWrite(5, HIGH);
//  delay(100);
//  digitalWrite(2, LOW);
//  digitalWrite(3, LOW);
//  digitalWrite(4, LOW);
//  digitalWrite(5, LOW);
//  delay(100);
Serial.println("Nyala Blink");
}





