// 6_Test_DC_Motors
const int MOTOR1_A = A8;
const int MOTOR3_A = A11;
const int EN12_PIN = 11;
const int EN34_PIN = 12;

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR1_A, OUTPUT);
  pinMode(MOTOR3_A, OUTPUT);
  pinMode(EN12_PIN, OUTPUT);
  pinMode(EN34_PIN, OUTPUT);
}

void loop() {
  Serial.println("Motors Forward");
  digitalWrite(MOTOR1_A, HIGH); // Assuming HIGH is forward
  digitalWrite(MOTOR3_A, HIGH);
  analogWrite(EN12_PIN, 200);   // Set speed (0-255)
  analogWrite(EN34_PIN, 200);
  delay(3000);

  Serial.println("Motors Stop");
  analogWrite(EN12_PIN, 0);
  analogWrite(EN34_PIN, 0);
  delay(2000);
  
  Serial.println("Motors Reverse");
  digitalWrite(MOTOR1_A, LOW); // Assuming LOW is reverse
  digitalWrite(MOTOR3_A, LOW);
  analogWrite(EN12_PIN, 200);
  analogWrite(EN34_PIN, 200);
  delay(3000);
  
  Serial.println("Motors Stop");
  analogWrite(EN12_PIN, 0);
  analogWrite(EN34_PIN, 0);
  delay(2000);
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
