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
  // MACRO_1 - DISCORD MUTE - i3 KEYCODE 198 //
  if (digitalRead(MACRO_1) == LOW) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F20);
    delay(5);
    Keyboard.releaseAll();
    delay(2000);
  }
  // MACRO_2 - i3 KEYCODE 199 //
  if (digitalRead(MACRO_2) == LOW) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F21);
    delay(5);
    Keyboard.releaseAll();
    delay(2000);
  }
  // MACRO_3 - VM STARTUP - i3 KEYCODE 200//
  if (digitalRead(MACRO_3) == LOW) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F22);
    delay(5);
    Keyboard.releaseAll();
    delay(2000);
  }
  // MACRO_4 - UPDATE DISTRO - i3 KEYCODE 201//
  if (digitalRead(MACRO_4) == LOW) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F23);
    delay(5);
    Keyboard.releaseAll();
    delay(2000);
  }
}
