#include <LiquidCrystal.h>

#define RS  10  // 4
#define EN  11  // 6
#define D4  8   // 11
#define D5  7   // 12
#define D6  6   // 13
#define D7  5   // 14

void setup() {
  LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("asdf");
}

void loop() {
  delay(100);
}

