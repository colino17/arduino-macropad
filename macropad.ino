// Macropad.ino

#include <Keyboard.h>

// Defining Pins
#define MACRO_1 4
#define MACRO_2 5
#define MACRO_3 6
#define MACRO_4 7

void setup() {
  pinMode(MACRO_1, INPUT_PULLUP);
  pinMode(MACRO_2, INPUT_PULLUP);
  pinMode(MACRO_3, INPUT_PULLUP);
  pinMode(MACRO_4, INPUT_PULLUP);

  Keyboard.begin();
}

void loop() {
// Alternatively the flow here could be press, delay, release within the same if statement
// This would be an option if the catchall release is not effective 
  // MACRO_1 - DISCORD MUTE //
  if (digitalRead(MACRO_1) == LOW) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press('m');
  }
  // MACRO_2  //
  if (digitalRead(MACRO_2) == LOW) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F22);
  }
  // MACRO_3 - VM STARTUP //
  if (digitalRead(MACRO_3) == LOW) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F23);
  }
  // MACRO_4 - UPDATE DISTRO//
  if (digitalRead(MACRO_4) == LOW) {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(KEY_F24);
  }
  else {
    Keyboard.releaseAll();
  }
}
