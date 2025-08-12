// 2_Test_DHT11
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// PIN DEFINITIONS
const int DHT_PIN = 5;

// OBJECT INITIALIZATION
#define DHTTYPE DHT11
DHT dht(DHT_PIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("DHT11 Test...");
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds.
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Read temperature as Celsius

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.setCursor(0, 1);
    lcd.print("Sensor Read ERR!");
    return;
  }

  // Print to Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\tTemperature: ");
  Serial.print(t);
  Serial.println(" *C");

  // Print to LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t, 1); // "1" for one decimal place
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humi: ");
  lcd.print(h, 1);
  lcd.print(" %");

  delay(2000); // Wait 2 seconds between measurements
}