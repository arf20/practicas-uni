void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
}

void loop() {
#if 0
  for (int i = 1; i < 100; i++) {
    int step = 1000/(i*i);
    Serial.print("T = ");
    Serial.println(step);
    for (int j = 0; j < 1000; j += step) {
      delay(step);
      digitalWrite(2, LOW);
      delay(step);
      digitalWrite(2, HIGH);
    }
  }
#endif
  int vfs = analogRead(0);
  float v = (float)vfs * (5.0f/1023.0f);
  Serial.print("vfs = ");
  Serial.println(vfs);
  Serial.print("v = ");
  Serial.print(v);
  Serial.println("V");
  delay(200);
}

