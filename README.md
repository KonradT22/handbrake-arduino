# Handbrake Arduino

A minimal Arduino sketch that converts a potentiometer into a USB handbrake axis for sim racing. The board presents itself to the PC as a HID joystick, so no drivers or additional software are needed — it works out of the box with any simulator that supports DirectInput.

## Hardware

| Component | Part | Notes |
|---|---|---|
| Arduino Pro Micro | ATmega32U4, 5V/16MHz | Must have native USB HID support — Uno/Nano do **not** |
| Slide potentiometer | Bourns PTA4543-2010CPB103 | 10 kΩ, 45mm linear travel |

## Wiring

The slide pot has three pins. With the pot oriented so the slider faces up:

```
Slide Potentiometer
  Left pin  (GND)   →  Arduino GND  [black]
  Middle pin (Wiper) →  Arduino A0   [yellow]
  Right pin  (VCC)  →  Arduino VCC  [red]
```

## Dependencies

Install via the Arduino Library Manager:

- [ArduinoJoystickLibrary](https://github.com/MHeironimus/ArduinoJoystickLibrary) by Matthew Heironimus

## Calibration

The sketch maps the raw ADC reading to the brake axis range (0–255). If your potentiometer doesn't sweep the full 0–1023 range due to limited physical travel, adjust `POT_MAX` in the sketch to match the actual maximum reading you observe:

```cpp
const int POT_MIN = 0;
const int POT_MAX = 1000; // lower this if your pot tops out early
```

You can find the right value by opening the Arduino Serial Monitor and printing `analogRead(A0)` while moving the handle through its full range.

## Usage

1. Install the Joystick library via Library Manager
2. Open `handbrake_arduino/handbrake_arduino.ino` in the Arduino IDE
3. Select your board under **Tools → Board → SparkFun AVR Boards → SparkFun Pro Micro**
4. Upload — the board will appear as a joystick in your OS
5. Assign the brake axis in your simulator's controller settings

## License

MIT
