#include <Joystick.h>

Joystick_ Joystick(
  0x04,
  JOYSTICK_TYPE_JOYSTICK,
  0, 0,                 // no buttons, no hat switch
  false, false, false,  // no X, Y, Z axes
  false, false, false,  // no Rx, Ry, Rz axes
  false,                // no throttle
  false, true, false    // no accelerator, brake enabled, no steering
);

// Potentiometer input range — adjust upper bound to match your physical travel
const int POT_MIN = 0;
const int POT_MAX = 1000;

void setup() {
  pinMode(A0, INPUT);
  Joystick.begin();
}

void loop() {
  int raw = analogRead(A0);
  int brakeValue = map(raw, POT_MIN, POT_MAX, 0, 255);
  Joystick.setBrake(constrain(brakeValue, 0, 255));
}
