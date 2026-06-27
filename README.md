<!-- ============================== -->
<!-- ATmega2560 STEAM Development Board -->
<!-- ============================== -->
<h1 align="center">🧪 ATmega2560 STEAM Development Board</h1>

<p align="center">
<!-- NOTE: Replace this placeholder with an actual image of your board -->
<img src="Docs/images/TOP_2.png" alt="ATmega2560 STEAM Development Board" width="600">
</p>

<p align="center">
<a href="https://opensource.org/licenses/MIT"><img src="https://img.shields.io/badge/License-MIT-blue.svg" alt="License: MIT"></a>
<img src="https://img.shields.io/badge/Status-Complete-success" alt="Project Status">
<img src="https://img.shields.io/badge/Tech-ATmega2560%20%7C%20Arduino-00979D" alt="Technology Stack">
</p>

<p align="justify">
An all-in-one, feature-rich platform designed to accelerate learning and prototyping for students, educators, and makers. This board integrates a powerful ATmega2560 microcontroller with a curated set of sensors, actuators, and displays, allowing you to go from <strong>idea to a working prototype in minutes</strong> without the hassle of complex wiring.
</p>

<hr>

<!-- ============================== -->
<!-- 🌐 Overview -->
<!-- ============================== -->
<h2>🌐 Overview</h2>
<p align="justify">
The <strong>ATmega2560 STEAM Development Board</strong> eliminates the initial barrier of breadboarding and wiring common in electronics projects. By integrating essential components directly onto a single PCB, users can focus on what truly matters: <strong>programming, problem-solving, and creativity</strong>. It provides:
<ul>
<li>A powerful Arduino Mega-compatible core</li>
<li>A full suite of on-board sensors for environmental interaction</li>
<li>A variety of displays and actuators for immediate feedback</li>
<li>On-board memory (EEPROM) and a battery-backed real-time clock</li>
<li>A robust and expandable design for custom projects</li>
</ul>
Ideal for <strong>classroom labs, maker projects, interactive art</strong>, and <strong>rapid prototyping</strong>, this board is engineered for versatility, ease of use, and educational impact.
</p>

<hr>

<!-- ============================== -->
<!-- 🖼️ Project Visuals -->
<!-- ============================== -->
<h2>🖼️ Project Visuals</h2>
<h3>🔧 Board and Schematic</h3>
<table>
<tr>
<th align="center">Top View of the Board</th>
<th align="center">Schematic Overview</th>
</tr>
<tr>
<!-- NOTE: Replace these placeholders with your actual images -->
<td><img src="Docs/images/TOP_1.png" width="400"/></td>
<td><img src="Docs/images/Schematic.png" width="400"/></td>
</tr>
</table>

<hr>

<!-- ============================== -->
<!-- 🧠 System Architecture -->
<!-- ============================== -->
<h2>🧠 System Architecture</h2>
<p align="justify">
The system is built around the <strong>ATmega2560 microcontroller</strong>, which acts as the central brain. It interfaces with all on-board peripherals using standard communication protocols like I²C, SPI, UART, and digital/analog I/O. A modern USB-C port with a CP2102N bridge provides a seamless connection for programming and serial communication. The modular design ensures that all components work together harmoniously, managed by the user's Arduino code.
</p>

<p align="center">
<!-- NOTE: Replace this placeholder with an actual system diagram image -->
<a href="Docs/images/system_architecture_diagram.png" target="_blank">
<img
src="Docs/images/system_architecture_diagram.png"
alt="System Architecture Diagram"
width="700"
style="border: 1px solid #ddd; border-radius: 8px; box-shadow: 0 4px 10px rgba(0, 0, 0, 0.1);"
/>
</a>
</p>
<p align="center">
<em>Click the image to view it in full resolution.</em>
</p>

<ul>
<li><strong>Central Controller:</strong> ATmega2560 manages all peripherals.</li>
<li><strong>Power System:</strong> Accepts a 12V barrel jack or USB-C power, providing regulated 5V (LM78M05) and 3.3V (LP2985), with a fuse on the input rail.</li>
<li><strong>Communication:</strong> USB-C via CP2102N for programming and data transfer.</li>
<li><strong>On-board Memory & Time:</strong> AT24CS32 I²C EEPROM and a battery-backed RTC (32.768 kHz crystal, coin-cell holder).</li>
<li><strong>Expandability:</strong> Breakout headers and an ICSP header expose unused I/O for connecting external modules.</li>
</ul>

<hr>

<!-- ============================== -->
<!-- ⚙️ How It Works -->
<!-- ============================== -->
<h2>⚙️ How It Works</h2>
<ol>
<li><strong>Power Up:</strong> Connect the board via USB-C or a 12V DC barrel jack adapter.</li>
<li><strong>Program:</strong> Connect to a computer, select "Arduino Mega 2560" in the Arduino IDE, and upload your sketch.</li>
<li><strong>Sense:</strong> The microcontroller reads data from on-board sensors like the DHT11 (temp/humidity), LDR (light), potentiometer, IR receiver, and touch input.</li>
<li><strong>Actuate:</strong> Your code processes the sensor data and controls outputs like the LCD, 7-segment display, RGB LEDs, motors, stepper/relay drivers, audio amp, and buzzer.</li>
<li><strong>Interact:</strong> Use the on-board RFID reader, push-buttons, and RTC/EEPROM for input, timekeeping, and data storage.</li>
</ol>

<hr>

<!-- ============================== -->
<!-- 🛠️ Technical Specifications -->
<!-- ============================== -->
<h2>🛠️ Technical Specifications</h2>

<h3>🔩 Hardware Components & Interfaces</h3>
<p><em>Pin assignments depend on the final PCB net routing — verify against <code>STEAM_FAC.kicad_sch</code> before relying on a specific Arduino pin number in code.</em></p>
<table>
<tr>
<th>Component</th>
<th>Description</th>
<th>Interface</th>
</tr>
<!-- MCU & Comms -->
<tr>
<td><strong>ATmega2560</strong></td>
<td>8-bit AVR Microcontroller</td>
<td>Core Processor</td>
</tr>
<tr>
<td><strong>CP2102N</strong></td>
<td>USB-to-UART Bridge</td>
<td>UART0 via USB-C</td>
</tr>
<!-- Sensors -->
<tr>
<td><strong>DHT11</strong></td>
<td>Temperature & Humidity Sensor</td>
<td>Single-wire Digital</td>
</tr>
<tr>
<td><strong>LDR (Photoresistor)</strong></td>
<td>Light-Dependent Resistor</td>
<td>Analog</td>
</tr>
<tr>
<td><strong>10kΩ Potentiometer</strong></td>
<td>Variable Resistor</td>
<td>Analog</td>
</tr>
<tr>
<td><strong>TSOP34S40F</strong></td>
<td>38kHz IR Receiver</td>
<td>Digital</td>
</tr>
<tr>
<td><strong>Touch Sensor</strong></td>
<td>Capacitive Touch Input</td>
<td>Digital</td>
</tr>
<!-- Actuators & Displays -->
<tr>
<td><strong>16x2 LCD (WC1602A)</strong></td>
<td>Liquid Crystal Display</td>
<td>Parallel / I²C expander</td>
</tr>
<tr>
<td><strong>HDSP-5501</strong></td>
<td>7-Segment Display</td>
<td>Driven via 74HC595 shift register</td>
</tr>
<tr>
<td><strong>WS2812B LEDs</strong></td>
<td>Addressable RGB LEDs</td>
<td>Digital (single-wire)</td>
</tr>
<tr>
<td><strong>APA102 LED</strong></td>
<td>Addressable RGB LED</td>
<td>SPI-style (DI/CI)</td>
</tr>
<tr>
<td><strong>L293D-style Driver</strong></td>
<td>Dual H-Bridge DC Motor Driver</td>
<td>Digital</td>
</tr>
<tr>
<td><strong>ULN2003</strong></td>
<td>Darlington Array / Stepper Driver</td>
<td>Digital</td>
</tr>
<tr>
<td><strong>Relay (driven via opto)</strong></td>
<td>SFH617A opto-isolated switching</td>
<td>Digital</td>
</tr>
<tr>
<td><strong>PAM8301</strong></td>
<td>Mono Class-D Audio Amplifier</td>
<td>Analog / PWM</td>
</tr>
<tr>
<td><strong>Piezo Buzzer</strong></td>
<td>Sound Actuator</td>
<td>Digital / PWM</td>
</tr>
<!-- Memory & Time -->
<tr>
<td><strong>AT24CS32</strong></td>
<td>32 Kbit I²C EEPROM</td>
<td>I²C</td>
</tr>
<tr>
<td><strong>RTC (C9868 + 32.768kHz)</strong></td>
<td>Battery-backed Real-Time Clock</td>
<td>I²C</td>
</tr>
<!-- User I/O -->
<tr>
<td><strong>RFID Reader</strong></td>
<td>13.56MHz RFID Reader/Writer</td>
<td>SPI (via ICSP / SCK-MOSI-MISO)</td>
</tr>
<tr>
<td><strong>Push Buttons (x4)</strong></td>
<td>Momentary Switches</td>
<td>Digital</td>
</tr>
</table>

<h3>💻 Software Stack</h3>
<ul>
<li><strong>Programming Language:</strong> C / C++</li>
<li><strong>IDE / Framework:</strong>
<ul>
<li><a href="https://www.arduino.cc/en/software">Arduino IDE</a> (v2.0 or later recommended)</li>
<li>PlatformIO with Arduino Framework</li>
</ul>
</li>
<li><strong>Key Libraries:</strong>
<ul>
<li><code>LiquidCrystal_I2C</code> (for the LCD)</li>
<li><code>DHT sensor library</code> (for DHT11)</li>
<li><code>Adafruit NeoPixel</code> (for WS2812B)</li>
<li><code>FastLED</code> or <code>Adafruit DotStar</code> (for APA102)</li>
<li><code>MFRC522</code> (for RFID)</li>
<li><code>RTClib</code> (for the real-time clock)</li>
<li><code>Wire</code> (for I²C EEPROM / RTC / expander)</li>
</ul>
</li>
</ul>

<hr>

<!-- ============================== -->
<!-- 🚀 Getting Started -->
<!-- ============================== -->
<h2>🚀 Getting Started</h2>
<h3>🧰 Prerequisites</h3>
<ul>
<li>An ATmega2560 STEAM Development Board</li>
<li>A USB-C cable</li>
<li>A computer with the <a href="https://www.arduino.cc/en/software">Arduino IDE</a> installed</li>
<li>A 12V DC Power Supply (optional, but recommended for motor and relay use)</li>
</ul>

<h3>🔌 First-Time Setup</h3>
<ol>
<li><strong>Connect Board:</strong> Plug the board into your computer using the USB-C cable.</li>
<li><strong>Configure IDE:</strong>
<ul>
<li>Open the Arduino IDE.</li>
<li>Go to <b>Tools > Board</b> and select <b>"Arduino Mega or Mega 2560"</b>.</li>
<li>Go to <b>Tools > Port</b> and select the correct COM port.</li>
</ul>
</li>
<li><strong>Install Libraries:</strong> Open the Library Manager (<b>Tools > Manage Libraries...</b>) and install the libraries listed in the Software Stack section above.</li>
<li><strong>Upload Code:</strong> Copy the example sketch below, paste it into the Arduino IDE, and click the "Upload" button.</li>
</ol>

<h3>🌈 Example Code: RGB LED Rainbow Cycle</h3>
<p>This sketch creates a rainbow animation on the on-board WS2812B RGB LEDs, confirming your setup is working correctly. Set <code>LED_PIN</code> and <code>LED_COUNT</code> to match your board's net routing.</p>

<!--
  NOTE:
  1. Create your code image using carbon.now.sh
  2. Upload the image to a folder in your repository (e.g., "Docs/images/code_example.png")
  3. Replace the link below with the link to YOUR image.
-->
<p align="center">
  <img src="Docs/images/code_example.png" alt="Example Code Screenshot">
</p>

```cpp
#include <Adafruit_NeoPixel.h>

#define LED_PIN    6  // Digital pin connected to the WS2812B LEDs (verify in schematic)
#define LED_COUNT  8  // Number of LEDs on the board

// Declare our NeoPixel strip object
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set brightness to 50/255 (good for indoor use)
}

void loop() {
  rainbow(10); // Run a rainbow cycle with a 10ms delay between steps
}

// Helper function to generate a rainbow animation
void rainbow(int wait) {
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) {
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
    delay(wait);
  }
}
```

<hr>

<!-- ============================== -->
<!-- 📁 Repository Structure -->
<!-- ============================== -->
<h2>📁 Repository Structure</h2>
<pre>
📦 ATmega2560-STEAM-Board/
├── 📂 Docs/
│ ├── 📂 images/ # Project images and diagrams
│ └── 📂 datasheets/ # Datasheets for key components
├── 📂 Firmware/
│ ├── 📂 examples/ # Example Arduino sketches for all features
│ └── 📂 libraries/ # Custom or specific libraries (if any)
├── 📂 Hardware/
│ ├── STEAM_FAC.kicad_pro # KiCad project file
│ ├── STEAM_FAC.kicad_sch # KiCad schematic file
│ ├── STEAM_FAC.kicad_pcb # KiCad PCB layout file
│ └── Bill_of_Materials.csv # Component list for manufacturing
└── 📄 README.md # You are here!
</pre>
<p><em>Note: KiCad files require <a href="https://www.kicad.org/">KiCad v9.0 or later</a> to view and edit.</em></p>

<hr>

<!-- ============================== -->
<!-- 🤝 Contributing -->
<!-- ============================== -->
<h2>🤝 Contributing</h2>
<p>Contributions, issues, and feature requests are welcome! Please read our <code>CONTRIBUTING.md</code> file for guidelines on how to participate in this project. You can also open an issue or start a discussion on the repository's page.</p>

<hr>

<!-- ============================== -->
<!-- 📜 License -->
<!-- ============================== -->
<h2>📜 License</h2>
<p>This project is licensed under the <a href="https://opensource.org/licenses/MIT">MIT License</a>. See the <code>LICENSE</code> file for more details.</p>
