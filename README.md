# ATmega2560 STEAM Development Board

![Board Photo](Docs/images/board_top_view.jpg)

An all-in-one development board based on the ATmega2560 microcontroller, designed for STEAM (Science, Technology, Engineering, Arts, and Mathematics) education. This board integrates a wide variety of sensors, actuators, and displays, making it a perfect platform for learning electronics and programming without the need for extensive breadboarding.

## Features

-   **Microcontroller:** ATmega2560 (compatible with Arduino Mega)
-   **Connectivity:** USB-C for programming and communication (via CP2102)
-   **Power:** On-board 12V to 5V and 3.3V regulators.
-   **Displays:**
    -   16x2 I2C LCD Display
    -   Single-digit 7-Segment Display (driven by 74HC595)
-   **Actuators & Outputs:**
    -   DC Motor Driver (L293D) for 2 motors
    -   Stepper Motor Driver (ULN2003)
    -   5V Relay for controlling external devices
    -   Piezo Buzzer for audio feedback
-   **Sensors:**
    -   DHT11 Temperature & Humidity Sensor
    -   TSOP IR Receiver
    -   Capacitive Touch Sensor
-   **Inputs:**
    -   Header for 4x4 Keypad
    -   Headers for 3 user buttons
-   **Communication:**
    -   SPI header for RFID (MFRC522) or other devices
    -   I2C bus with headers for Real-Time Clock (DS1307) and EEPROM (AT24C)
    -   Headers for two extra UART ports (UART1, UART2)
-   **Lighting:**
    -   Individually addressable RGB LEDs (WS2812B "NeoPixel" and APA102)
    -   A bank of 8 general-purpose LEDs for debugging.

## Hardware

All hardware design files were created in KiCad 8. You can find the schematic, PCB layout, and project files in the `/Hardware` directory.

-   [Schematic File (`.kicad_sch`)](./Hardware/STEAM_FAC.kicad_sch)
-   [PCB Layout File (`.kicad_pcb`)](./Hardware/STEAM_FAC.kicad_pcb)
-   [Bill of Materials (`.csv`)](./Hardware/Bill_of_Materials.csv)

### Schematic Overview
![Schematic Image](Docs/images/schematic_overview.png)

## Pin Mapping

The following table details the ATmega2560 pin connections for all on-board peripherals.

| Functional Block      | Component           | ATmega2560 Pin(s)                                | "Arduino" Label(s)   |
| --------------------- | ------------------- | ------------------------------------------------ | -------------------- |
| **I2C Bus**           | LCD, RTC, EEPROM    | `PD0` (SCL), `PD1` (SDA)                         | SCL (20), SDA (21)   |
| **SPI Bus**           | RFID Header (J1)    | `PB0-PB3` (SS, SCK, MOSI, MISO)                  | 53, 52, 51, 50       |
| **USB/Serial**        | CP2102              | `PE0` (RXD0), `PE1` (TXD0)                       | RX0 (0), TX0 (1)     |
| **Motor Driver**      | L293D (U7)          | `PK0-PK3` (A8-A11), `PB5` (D11), `PB6` (D12)     | A8-A11, 11, 12       |
| **Stepper Driver**    | ULN2003 (U6)        | `PC1-PC4` (D36-D33)                              | 36, 35, 34, 33       |
| **7-Segment Display** | 74HC595 (U3)        | `PH6` (D9), `PB7` (D13), `PB4` (D10)             | 9, 13, 10            |
| **LCD Control**       | Backlight & Contrast| `PE4` (D2), `PL7` (D42), `PK7` (A15)             | 2, 42, A15           |
| **Relay**             | Relay Driver (Q3)   | `PH2`                                            | 27                   |
| **Buzzer**            | BZ1                 | `PG5`                                            | 4                    |
| **DHT11 Sensor**      | DHT11 (U8)          | `PE3`                                            | 5                    |
| **IR Sensor**         | TSOP (U8)           | `PE5`                                            | 3                    |
| **Touch Sensor**      | U10                 | `PG0`                                            | 40                   |
| **WS2812B LEDs**      | D16, D17            | `PG2` (D41), `PL5` (D44)                         | 41, 44               |
| **APA102 LED**        | APA102              | `PH5` (Data), `PH4` (Clock)                      | 8, 7                 |
| **Keypad Header**     | J6                  | `PA0-PA7`                                        | 22-29                |

## Getting Started

### 1. Powering the Board
-   Connect a 12V DC power supply to the barrel jack (`J12`).
-   Alternatively, power the board via the USB-C connector (`J11`). This is sufficient for programming and low-power peripherals.

### 2. Programming
-   This board is compatible with the **Arduino Mega 2560** board profile.
-   Connect the board to your computer via the USB-C cable.
-   In the Arduino IDE, select:
    -   **Board:** "Arduino Mega or Mega 2560"
    -   **Processor:** "ATmega2560 (Mega 2560)"
    -   **Port:** The COM port that appears when you connect the board.
-   Upload an example sketch from the `/Firmware/examples` directory to test the functionalities.

### 3. Required Libraries
You may need to install the following libraries via the Arduino Library Manager to use all peripherals:
-   `LiquidCrystal_I2C` by Frank de Brabander
-   `DHT sensor library` by Adafruit
-   `Adafruit NeoPixel` by Adafruit
-   `RTClib` by Adafruit
-   `MFRC522` by GithubCommunity

## License
This project is licensed under the **MIT License**. See the [LICENSE](./LICENSE) file for details.
