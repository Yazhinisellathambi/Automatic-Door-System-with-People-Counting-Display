#include <LiquidCrystal.h>
#include <Servo.h>

// LCD (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(7, 6, 5, 4, 8, 11);

// Servos
Servo entryServo;
Servo exitServo;

// IR Sensors
int entryIR = 2;
int exitIR  = 3;

// Counters
int inCount = 0;
int outCount = 0;

void setup() {
  pinMode(entryIR, INPUT);
  pinMode(exitIR, INPUT);

  entryServo.attach(9);
  exitServo.attach(10);

  entryServo.write(0);
  exitServo.write(0);

  lcd.begin(16, 2);
  lcd.print("IN : 0");
  lcd.setCursor(0,1);
  lcd.print("OUT: 0");
}

void loop() {

  // ENTRY
  if (digitalRead(entryIR) == LOW) {
    entryServo.write(90);
    inCount++;

    lcd.setCursor(5,0);
    lcd.print(inCount);

    delay(2000);
    entryServo.write(0);
    delay(1000);
  }

  // EXIT
  if (digitalRead(exitIR) == LOW) {
    exitServo.write(90);
    outCount++;

    lcd.setCursor(5,1);
    lcd.print(outCount);

    delay(2000);
    exitServo.write(0);
    delay(1000);
  }
}
