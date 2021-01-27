// Macropad.ino

#include <Keyboard.h>

// Defining Pins
#define MACRO_1 4
#define MACRO_2 5
#define MACRO_3 6
#define MACRO_4 7

void setup() {
  pinMode (MACRO_1, INPUT_PULLUP);
  pinMode (MACRO_2, INPUT_PULLUP);
  pinMode (MACRO_3, INPUT_PULLUP);
  pinMode (MACRO_4, INPUT_PULLUP);

  Keyboard.begin();
}

void loop() {
  // MACRO_1 //
  if (digitalRead(MACRO_1) == LOW)
  {
    Keyboard.press(KEY_LEFT_ALT);
  }
  if (digitalRead(MACRO_1) == HIGH)
    {
     Keyboard.release(KEY_LEFT_ALT);
  }
  // MACRO_2 //
  if (digitalRead(MACRO_2) == LOW)
  {
    Keyboard.press(KEY_UP_ARROW);
  }
  if (digitalRead(MACRO_2) == HIGH)
  {
    Keyboard.release(KEY_UP_ARROW);
  }
  // MACRO_3 //
  if (digitalRead(MACRO_3) == LOW)
  {
    Keyboard.press(KEY_LEFT_CTRL);
  }
  if (digitalRead(MACRO_3)==HIGH)
  {
    Keyboard.release(KEY_LEFT_CTRL);
  }
  // MACRO_4 //
  if (digitalRead(MACRO_4) == LOW)
  {
    Keyboard.press(KEY_LEFT_ARROW);
  }
  if (digitalRead(MACRO_4) == HIGH)
  {
    Keyboard.release(KEY_LEFT_ARROW);
  }
  }
