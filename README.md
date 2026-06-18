# Handbrake Arduino

A minimal Arduino sketch that converts a potentiometer into a USB handbrake axis for sim racing. The board presents itself to the PC as a HID joystick, so no drivers or additional software are needed — it works out of the box with any simulator that supports DirectInput.

## Hardware

| Component | Notes |
|---|---|
| Arduino Pro Micro (or Leonardo) | Must have native USB HID support |
| 10 kΩ linear potentiometer | Attached to the handbrake mechanism |
| 3 wires | VCC, GND, wiper → A0 |

> Other ATmega32U4-based boards work too. Uno/Nano do **not** support native HID.

## Wiring

```
Potentiometer
  Pin 1 (VCC)   →  Arduino 5V
  Pin 2 (Wiper) →  Arduino A0
  Pin 3 (GND)   →  Arduino GND
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
3. Select your board under **Tools → Board** (e.g., *Arduino Leonardo*)
4. Upload — the board will appear as a joystick in your OS
5. Assign the brake axis in your simulator's controller settings

## License

MIT
