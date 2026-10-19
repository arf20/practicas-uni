#include <LiquidCrystal.h>
#include <DHT.h>

#define RS  10  // 4
#define EN  11  // 6
#define D4  8   // 11
#define D5  7   // 12
#define D6  6   // 13
#define D7  5   // 14

#define DHT_PIN 12  // dht
                //
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
DHT dht11(DHT_PIN, DHT11);

void setup() {
  lcd.begin(16, 2);
  dht11.begin();
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("asdf");

  float temp = dht11.readTemperature();
  float hum = dht11.readHumidity();
  lcd.setCursor(0,1);
  lcd.print((int)temp);
  lcd.setCursor(2,1);
  lcd.print("C");
  lcd.setCursor(5,1);
  lcd.print((int)hum);
  lcd.setCursor(7,1);
  lcd.print("%");

  Serial.println(temp);
  Serial.println(hum);

  delay(2000);
}

