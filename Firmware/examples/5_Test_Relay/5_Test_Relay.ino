// 5_Test_Relay
const int RELAY_PIN = 27;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  Serial.println("Relay will toggle every 2 seconds.");
}

void loop() {
  Serial.println("Relay ON (clicking sound)");
  digitalWrite(RELAY_PIN, HIGH);
  delay(2000);

  Serial.println("Relay OFF (clicking sound)");
  digitalWrite(RELAY_PIN, LOW);
  delay(2000);
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
