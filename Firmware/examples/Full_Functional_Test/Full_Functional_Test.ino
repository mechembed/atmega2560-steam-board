/*
 *  Full Functional Test Sketch for the ATmega2560 STEAM Development Board
 *
 *  This sketch provides a demonstration and test for every major
 *  peripheral on the custom ATmega2560 board.
 *
 *  How to use:
 *  1. Install all the required libraries (see list above).
 *  2. Select "Arduino Mega or Mega 2560" as your board in the IDE.
 *  3. Select the correct COM port.
 *  4. Upload the sketch.
 *  5. Open the Serial Monitor at 9600 baud to see test results and sensor data.
 *
 *  Created for: mechembed (Noch Kakada)
 */

// -- INCLUDE LIBRARIES --
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_DotStar.h>
#include <SPI.h>
#include <RTClib.h>
#include <Keypad.h>
#include <IRremote.h>

// -- PIN DEFINITIONS --
// Match these to your schematic

// 7-Segment Display (via 74HC595 Shift Register)
const int LATCH_PIN = 10;  // PB4 (RCLK)
const int CLOCK_PIN = 13;  // PB7 (SRCK)
const int DATA_PIN  = 9;   // PH6 (SER)

// Motor Driver (L293D)
const int MOTOR1_A = A8;   // PK0
const int MOTOR2_A = A9;   // PK1
const int MOTOR3_A = A11;  // PK3
const int MOTOR4_A = A10;  // PK2 (used as second pin for Stepper)
const int EN12_PIN = 11;   // PB5
const int EN34_PIN = 12;   // PB6

// Stepper Driver (ULN2003)
const int STEPPER_IN1 = 36; // PC1
const int STEPPER_IN2 = 35; // PC2
const int STEPPER_IN3 = 34; // PC3
const int STEPPER_IN4 = 33; // PC4

// Sensors
const int DHT_PIN      = 5;   // PE3
const int IR_PIN       = 3;   // PE5
const int TOUCH_PIN    = 40;  // PG0

// Actuators
const int RELAY_PIN    = 27;  // PH2
const int BUZZER_PIN   = 4;   // PG5

// Addressable LEDs
const int NEOPIXEL_PIN_1 = 41;  // PG2 (WS2812B #1)
const int NEOPIXEL_PIN_2 = 44;  // PL5 (WS2812B #2)
const int DOTSTAR_DATA_PIN = 8; // PH5 (APA102 Data)
const int DOTSTAR_CLOCK_PIN = 7; // PH4 (APA102 Clock)

// LCD Control
const int LCD_BACKLIGHT_PIN = 2; // PE4

// Keypad
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {29, 28, 27, 26}; // PA7-PA4
byte colPins[COLS] = {25, 24, 23, 22}; // PA3-PA0


// -- OBJECT INITIALIZATIONS --

// LCD (common I2C address is 0x27, might be 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// DHT Sensor
#define DHTTYPE DHT11
DHT dht(DHT_PIN, DHTTYPE);

// NeoPixel (WS2812B) Strips
Adafruit_NeoPixel strip1(1, NEOPIXEL_PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(1, NEOPIXEL_PIN_2, NEO_GRB + NEO_KHZ800);

// DotStar (APA102) LED
Adafruit_DotStar dotstar(1, DOTSTAR_DATA_PIN, DOTSTAR_CLOCK_PIN, DOTSTAR_BRG);

// Real-Time Clock
RTC_DS1307 rtc;

// Keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// IR Receiver
IRrecv irrecv(IR_PIN);
decode_results results;

// 7-Segment character map (0-9) for common cathode
byte seven_seg_digits[] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};


// -- SETUP FUNCTION --
void setup() {
  Serial.begin(9600);
  Serial.println("--- ATmega2560 STEAM Board Test Initializing ---");

  // Initialize Pin Modes
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(TOUCH_PIN, INPUT);
  pinMode(LCD_BACKLIGHT_PIN, OUTPUT);
  pinMode(MOTOR1_A, OUTPUT);
  pinMode(MOTOR2_A, OUTPUT);
  pinMode(MOTOR3_A, OUTPUT);
  pinMode(MOTOR4_A, OUTPUT);
  pinMode(EN12_PIN, OUTPUT);
  pinMode(EN34_PIN, OUTPUT);
  pinMode(STEPPER_IN1, OUTPUT);
  pinMode(STEPPER_IN2, OUTPUT);
  pinMode(STEPPER_IN3, OUTPUT);
  pinMode(STEPPER_IN4, OUTPUT);

  // Turn on LCD Backlight
  digitalWrite(LCD_BACKLIGHT_PIN, HIGH);
  
  // Initialize Peripherals
  lcd.init();
  dht.begin();
  strip1.begin(); strip1.show(); // Initialize all pixels to 'off'
  strip2.begin(); strip2.show();
  dotstar.begin(); dotstar.show();
  irrecv.enableIRIn();

  // Initialize I2C for RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    lcd.print("RTC Not Found");
    //while (1); // Uncomment to halt if RTC is essential
  }
  if (!rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    // Set RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // --- Initial Startup Sequence ---
  Serial.println("Startup sequence...");
  lcd.setCursor(0,0);
  lcd.print("STEAM Board OK!");
  lcd.setCursor(0,1);
  lcd.print("System Test...");
  
  digitalWrite(BUZZER_PIN, HIGH);
  delay(100);
  digitalWrite(BUZZER_PIN, LOW);
  delay(200);

  Serial.println("Initialization Complete.");
  lcd.clear();
}


// -- MAIN LOOP --
void loop() {
  readSensors();     // Read and display data from DHT11 and Touch sensor
  checkKeypad();       // Check for keypad presses
  checkIRReceiver();   // Check for IR signals
  test7Segment();      // Cycle 0-9 on the display
  testAddressableLEDs(); // Cycle colors on RGB LEDs
  testRelayAndBuzzer(); // Toggle the relay and beep
  testDCMotors();      // Run DC motors forward and backward
  testStepperMotor();  // Rotate the stepper motor
  
  lcd.clear();
  delay(1000); // Wait a second before restarting the full loop
}


// -- HELPER FUNCTIONS --

void readSensors() {
  Serial.println("\n--- Reading Sensors ---");
  lcd.setCursor(0, 0);
  
  // Read DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.print("DHT11 Error");
  } else {
    Serial.print("Humidity: "); Serial.print(h); Serial.print("%\t");
    Serial.print("Temperature: "); Serial.print(t); Serial.println(" *C");
    lcd.print("T:"); lcd.print(t, 1); lcd.print("C H:"); lcd.print(h, 1); lcd.print("%");
  }

  // Read Touch Sensor
  lcd.setCursor(0, 1);
  int touchValue = digitalRead(TOUCH_PIN);
  Serial.print("Touch Sensor: "); Serial.println(touchValue);
  if (touchValue == HIGH) {
    lcd.print("Touch: PRESSED!");
  } else {
    lcd.print("Touch: not press");
  }

  // Read RTC
  DateTime now = rtc.now();
  Serial.print("RTC Time: ");
  Serial.print(now.year(), DEC); Serial.print('/');
  Serial.print(now.month(), DEC); Serial.print('/');
  Serial.print(now.day(), DEC); Serial.print(" ");
  Serial.print(now.hour(), DEC); Serial.print(':');
  Serial.print(now.minute(), DEC); Serial.print(':');
  Serial.println(now.second(), DEC);

  delay(2000);
}

void checkKeypad() {
  char key = keypad.getKey();
  if (key) {
    Serial.print("\nKeypad Pressed: "); Serial.println(key);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Keypad: ");
    lcd.print(key);
    digitalWrite(BUZZER_PIN, HIGH); delay(50); digitalWrite(BUZZER_PIN, LOW);
    delay(500);
  }
}

void checkIRReceiver() {
  if (irrecv.decode(&results)) {
    Serial.print("\nIR Code Received: 0x"); Serial.println(results.value, HEX);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("IR Code Received!");
    lcd.setCursor(0,1);
    lcd.print("0x"); lcd.print(results.value, HEX);
    delay(1000);
    irrecv.resume(); // Receive the next value
  }
}

void test7Segment() {
  Serial.println("\n--- Testing 7-Segment Display (0-9) ---");
  lcd.clear();
  lcd.print("Testing 7-Seg...");
  for (int i = 0; i < 10; i++) {
    update7Segment(seven_seg_digits[i]);
    delay(250);
  }
  update7Segment(0b00000000); // Turn off
}

void update7Segment(byte digit) {
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, digit);
  digitalWrite(LATCH_PIN, HIGH);
}


void testAddressableLEDs() {
  Serial.println("\n--- Testing Addressable LEDs ---");
  lcd.clear();
  lcd.print("Testing RGB LEDs");

  // Red
  strip1.setPixelColor(0, strip1.Color(50, 0, 0)); strip1.show();
  strip2.setPixelColor(0, strip2.Color(50, 0, 0)); strip2.show();
  dotstar.setPixelColor(0, 50, 0, 0); dotstar.show();
  delay(500);
  
  // Green
  strip1.setPixelColor(0, strip1.Color(0, 50, 0)); strip1.show();
  strip2.setPixelColor(0, strip2.Color(0, 50, 0)); strip2.show();
  dotstar.setPixelColor(0, 0, 50, 0); dotstar.show();
  delay(500);
  
  // Blue
  strip1.setPixelColor(0, strip1.Color(0, 0, 50)); strip1.show();
  strip2.setPixelColor(0, strip2.Color(0, 0, 50)); strip2.show();
  dotstar.setPixelColor(0, 0, 0, 50); dotstar.show();
  delay(500);

  // Turn off
  strip1.clear(); strip1.show();
  strip2.clear(); strip2.show();
  dotstar.clear(); dotstar.show();
}

void testRelayAndBuzzer() {
  Serial.println("\n--- Testing Relay and Buzzer ---");
  lcd.clear(); lcd.print("Relay ON");
  Serial.println("Relay ON");
  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(BUZZER_PIN, HIGH); delay(200); digitalWrite(BUZZER_PIN, LOW);
  delay(1000);
  
  lcd.clear(); lcd.print("Relay OFF");
  Serial.println("Relay OFF");
  digitalWrite(RELAY_PIN, LOW);
  delay(1000);
}

void testDCMotors() {
  Serial.println("\n--- Testing DC Motors ---");
  lcd.clear();
  
  // Motor 1 & 3 Forward
  lcd.print("DC Motors FWD");
  Serial.println("Motors 1 & 3 Forward");
  digitalWrite(MOTOR1_A, HIGH); // Assuming one pin controls direction
  digitalWrite(MOTOR3_A, HIGH);
  analogWrite(EN12_PIN, 200); // Speed control
  analogWrite(EN34_PIN, 200);
  delay(2000);

  // Stop
  lcd.clear(); lcd.print("DC Motors STOP");
  Serial.println("Motors Stop");
  analogWrite(EN12_PIN, 0);
  analogWrite(EN34_PIN, 0);
  delay(1000);

  // Motor 1 & 3 Backward
  lcd.clear(); lcd.print("DC Motors REV");
  Serial.println("Motors 1 & 3 Reverse");
  digitalWrite(MOTOR1_A, LOW);
  digitalWrite(MOTOR3_A, LOW);
  analogWrite(EN12_PIN, 200);
  analogWrite(EN34_PIN, 200);
  delay(2000);

  // Stop
  analogWrite(EN12_PIN, 0);
  analogWrite(EN34_PIN, 0);
}


void testStepperMotor() {
  Serial.println("\n--- Testing Stepper Motor ---");
  lcd.clear();
  lcd.print("Stepper Test...");

  // Rotate one direction (e.g., 200 steps for one revolution)
  for(int i = 0; i < 200; i++) {
    stepperStep(i % 4);
    delay(20);
  }
  
  // Turn off coils
  digitalWrite(STEPPER_IN1, LOW);
  digitalWrite(STEPPER_IN2, LOW);
  digitalWrite(STEPPER_IN3, LOW);
  digitalWrite(STEPPER_IN4, LOW);
}

void stepperStep(int step) {
  switch(step) {
    case 0:
      digitalWrite(STEPPER_IN1, HIGH);
      digitalWrite(STEPPER_IN2, LOW);
      digitalWrite(STEPPER_IN3, LOW);
      digitalWrite(STEPPER_IN4, LOW);
      break;
    case 1:
      digitalWrite(STEPPER_IN1, LOW);
      digitalWrite(STEPPER_IN2, HIGH);
      digitalWrite(STEPPER_IN3, LOW);
      digitalWrite(STEPPER_IN4, LOW);
      break;
    case 2:
      digitalWrite(STEPPER_IN1, LOW);
      digitalWrite(STEPPER_IN2, LOW);
      digitalWrite(STEPPER_IN3, HIGH);
      digitalWrite(STEPPER_IN4, LOW);
      break;
    case 3:
      digitalWrite(STEPPER_IN1, LOW);
      digitalWrite(STEPPER_IN2, LOW);
      digitalWrite(STEPPER_IN3, LOW);
      digitalWrite(STEPPER_IN4, HIGH);
      break;
  }
}