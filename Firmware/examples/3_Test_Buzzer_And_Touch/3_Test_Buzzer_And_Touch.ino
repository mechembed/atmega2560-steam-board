// 3_Test_Buzzer_And_Touch
const int BUZZER_PIN = 4;
const int TOUCH_PIN = 40;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(TOUCH_PIN, INPUT);
  Serial.println("Touch sensor to activate buzzer.");
}

void loop() {
  int touchValue = digitalRead(TOUCH_PIN);
  
  if (touchValue == HIGH) {
    digitalWrite(BUZZER_PIN, HIGH); // Turn buzzer ON
    Serial.println("Touch detected! Beeping.");
  } else {
    digitalWrite(BUZZER_PIN, LOW); // Turn buzzer OFF
  }
  delay(10); // Small delay to prevent flickering
}