#include <LiquidCrystal.h>

LiquidCrystal lcd (12, 11, 2, 3, 4, 5);

const int toggle_pin = 7;
int flag = 0;
bool toggle_state = 0;
int state = 0;
int count = 0;

void setup() {
  lcd.begin(16,2); 
  pinMode(toggle_pin,INPUT);
}


void loop() {
  int buttonState = digitalRead(toggle_pin);

  if (buttonState == HIGH) {
    if (state == 0) {
      delay(10);
      state = 1;
    }
  }

  if (buttonState == LOW) {
    if (state == 1) {
      count += 1;
      lcd.clear();
      delay(10);
      state = 0;
    }
  }

  lcd.setCursor(0,0);
  if (count % 3 == 0) {
    lcd.print("current location");
    lcd.setCursor(0,1);
    lcd.print("is 5E208A");
  }
  else if (count % 3 == 1) {
    lcd.print("left classroom");
    lcd.setCursor(0,1);
    lcd.print("is 5E211");
  } 
  else {
    lcd.print("right classroom");
    lcd.setCursor(0,1);
    lcd.print("is 5E206B");
  }
}
