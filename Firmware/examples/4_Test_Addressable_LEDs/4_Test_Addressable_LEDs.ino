// 4_Test_Addressable_LEDs
#include <Adafruit_NeoPixel.h>
#include <Adafruit_DotStar.h>

// PIN DEFINITIONS
const int NEOPIXEL_PIN_1 = 41;  // WS2812B #1
const int NEOPIXEL_PIN_2 = 44;  // WS2812B #2
const int DOTSTAR_DATA_PIN = 8; // APA102 Data
const int DOTSTAR_CLOCK_PIN = 7;// APA102 Clock

// OBJECT INITIALIZATION
// Parameter 1 = number of pixels
Adafruit_NeoPixel strip1(1, NEOPIXEL_PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(1, NEOPIXEL_PIN_2, NEO_GRB + NEO_KHZ800);
Adafruit_DotStar dotstar(1, DOTSTAR_DATA_PIN, DOTSTAR_CLOCK_PIN, DOTSTAR_BRG);

void setup() {
  strip1.begin();
  strip2.begin();
  dotstar.begin();
  
  strip1.setBrightness(40); // Set brightness to a safe level
  strip2.setBrightness(40);
  dotstar.setBrightness(40);

  strip1.clear(); strip1.show(); // Initialize all pixels to 'off'
  strip2.clear(); strip2.show();
  dotstar.clear(); dotstar.show();
}

void loop() {
  // RED
  setColor(255, 0, 0);
  delay(1000);
  
  // GREEN
  setColor(0, 255, 0);
  delay(1000);

  // BLUE
  setColor(0, 0, 255);
  delay(1000);
}

void setColor(byte r, byte g, byte b) {
  strip1.setPixelColor(0, r, g, b);
  strip1.show();

  strip2.setPixelColor(0, r, g, b);
  strip2.show();
  
  dotstar.setPixelColor(0, r, g, b); // DotStar takes RGB in that order
  dotstar.show();
}