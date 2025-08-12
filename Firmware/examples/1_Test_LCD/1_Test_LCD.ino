// 1_Test_LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// PIN DEFINITIONS
const int LCD_BACKLIGHT_PIN = 2;

// OBJECT INITIALIZATION
// Common I2C addresses are 0x27 or 0x3F. Change if needed.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(LCD_BACKLIGHT_PIN, OUTPUT);
  digitalWrite(LCD_BACKLIGHT_PIN, HIGH); // Turn backlight on

  Serial.begin(9600);
  Serial.println("LCD Test Initializing...");
  
  lcd.init();
  lcd.backlight(); // Ensure backlight is on via I2C command too

  lcd.setCursor(0, 0); // Column 0, Line 0
  lcd.print("Hello, mechembed!");

  lcd.setCursor(0, 1); // Column 0, Line 1
  lcd.print("LCD is working!");
  
  Serial.println("Text should be visible on the LCD.");
}

void loop() {
  // Nothing to do here, the test is in setup()
}