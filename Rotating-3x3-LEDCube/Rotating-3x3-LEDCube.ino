// Written by Kevin L. Turner
// The Pennsylvania State University, Dept. of Biomedical Engineering
// https://github.com/KL-Turner

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2); // generates instance in the LCD screen

const int LCD_Pin = 6;
const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;

void setup() {
  // LCD setup
  lcd.begin(16,2);
  pinMode(LCD_Pin, INPUT);
  // Write to the first line of the screen
  lcd.print("...But why is");
  // Change the Cursor to continue writing in the second row
  lcd.setCursor(0,1);
  lcd.print("   the rum gone?");

  // DC motor setup
  pinMode(switchPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Read if the switch has been pushed
  switchState = digitalRead(switchPin);
  if(switchState == HIGH) {
    // If the switch has been pushed, make the motor spin.
    digitalWrite(motorPin, HIGH);
  }
  else {
    // If the switch hasn't been pushed, don't make the motor spin.
    digitalWrite(motorPin, LOW);    
  }
}
