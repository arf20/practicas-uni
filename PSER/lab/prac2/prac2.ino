#include <LiquidCrystal.h>
#include <DHT.h>

#define RS  10  // 4
#define EN  11  // 6
#define D4  8   // 11
#define D5  7   // 12
#define D6  6   // 13
#define D7  5   // 14

#define DHT_PIN 12  // dht

#define BTN_PIN 4

#define US_TRIG_PIN 13
#define US_ECHO_PIN 9

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
DHT dht11(DHT_PIN, DHT11);

int count = 0;

float temp = 0.0f, hum = 0.0f, dist = 0.0f;

int sel = 0;
int btn0 = 0;

void setup() {
  lcd.begin(16, 2);
  dht11.begin();
  Serial.begin(9600);

  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(US_TRIG_PIN, OUTPUT);
  pinMode(US_ECHO_PIN, INPUT);
}

void loop() {
  if (count % 20 == 0) {
    temp = dht11.readTemperature();
    hum = dht11.readHumidity();

    digitalWrite(US_TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(US_TRIG_PIN, LOW);
    float duration_us = pulseIn(US_ECHO_PIN, HIGH);
    dist = 0.017 * duration_us;
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("asdf");

  if (sel == 0) {
    lcd.setCursor(0,1);
    lcd.print((int)temp);
    lcd.setCursor(3,1);
    lcd.print("C");
  } else if (sel == 1) {
    lcd.setCursor(0,1);
    lcd.print((int)hum);
    lcd.setCursor(3,1);
    lcd.print("%");
  } else if (sel == 2) {
    lcd.setCursor(0,1);
    lcd.print(dist);
    lcd.setCursor(5,1);
    lcd.print("cm");
  }


  int btn = digitalRead(BTN_PIN);
  if (btn0 == 1 && btn == 0)
    sel++;
  if (sel > 2)
    sel = 0;
  btn0 = btn;
  lcd.setCursor(7,0);
  lcd.print("btn");
  lcd.setCursor(11,0);
  lcd.print(btn);

  Serial.println(temp);
  Serial.println(hum);
  Serial.println(btn);

  delay(100);
  count++;
}

