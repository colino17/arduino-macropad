//Code made by Foster Phillips
//March-April 2018
//Created for Instuctables, username: FosterP
//Instagram: Lego_Rocket_08
//File Name: ArrowKeypad

#include <Adafruit_NeoPixel.h>
#include <Adafruit_SSD1306.h>
#include <Mouse.h>
#include <Keyboard.h>

// Defining each pin, with a unique name
#define LUp 4
#define Up 5
#define RUp 6
#define Left 7
#define Down 8
#define Right 9
#define LedData 10
#define Switch 18
#define OLED_RESET 4
#define NumLed 6
boolean OledClear = true;

//Setting up the OLED display and Neopixel Libraries
Adafruit_SSD1306 display(OLED_RESET);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NumLed, LedData, NEO_GRB + NEO_KHZ800);

void setup() {
  // Telling the Arduino that the switches are inputs, and the Leds are output //
  pinMode (LUp, INPUT_PULLUP);
  pinMode (Up, INPUT_PULLUP);
  pinMode (RUp, INPUT_PULLUP);
  pinMode (Left, INPUT_PULLUP);
  pinMode (Down, INPUT_PULLUP);
  pinMode (Right, INPUT_PULLUP);
  pinMode (Switch, INPUT_PULLUP);
  pinMode (LedData, OUTPUT);
  //starting the strip
  strip.begin();
  strip.show();

  Keyboard.begin();
  Mouse.begin();

  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  //First Layer Programming// //First Layer Programming// //First Layer Programming// //First Layer Programming//
  if (digitalRead(Switch) == HIGH)
  {
        //Setting the colours (Led number, Red, Green, Blue) max amount that each RGB value can have is 255, min is 0//
    strip.setPixelColor(0, 0, 255, 255);
    strip.setPixelColor(1, 0, 255, 255);
    strip.setPixelColor(2, 0, 255, 255);
    strip.setPixelColor(3, 255, 0, 128);
    strip.setPixelColor(4, 0, 255, 255);
    strip.setPixelColor(5, 255, 0, 128);
    strip.show();
    //Boolean Checks to make sure that we haven't done this before//
    if (OledClear == true) {
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("Layer 1");
      display.println("Hello World!");
      display.display();
      OledClear = false;
    }
    //Up Arrow//
    if (digitalRead(Up) == LOW)
    {
      Keyboard.press(KEY_UP_ARROW);
    }
    if (digitalRead(Up) == HIGH)
    {
      Keyboard.release(KEY_UP_ARROW);
    }

    //Down Arrow//
    if (digitalRead(Down) == LOW)
    {
      Keyboard.press(KEY_DOWN_ARROW);
    }
    if (digitalRead(Down) == HIGH)
    {
      Keyboard.release(KEY_DOWN_ARROW);
    }

    //Right Arrow//
    if (digitalRead(Right) == LOW)
    {
      Keyboard.press(KEY_RIGHT_ARROW);
    }
    if (digitalRead(Right) == HIGH)
    {
      Keyboard.release(KEY_RIGHT_ARROW);
    }

    //Left Arrow//
    if (digitalRead(Left) == LOW)
    {
      Keyboard.press(KEY_LEFT_ARROW);
    }
    if (digitalRead(Left) == HIGH)
    {
      Keyboard.release(KEY_LEFT_ARROW);
    }

    //Top Right Button//
    if (digitalRead(RUp) == LOW)
    {
      Keyboard.press(KEY_LEFT_CTRL);
    }
    if (digitalRead(RUp)==HIGH)
    {
      Keyboard.release(KEY_LEFT_CTRL);
    }

    //Top Right Button//
    if (digitalRead(LUp) == LOW)
    {
      Keyboard.press(KEY_LEFT_ALT);
    }
    if (digitalRead(LUp) == HIGH)
    {
      Keyboard.release(KEY_LEFT_ALT);
    }
  }

  //Second Layer Programming// //Second Layer Programming// //Second Layer Programming// //Second Layer Programming// //Second Layer Programmed//

  else if (digitalRead(Switch) == LOW)
  {
    //Setting the colours (Led number, Red, Green, Blue) max amount that each RGB value can have is 255, min is 0//
    strip.setPixelColor(0, 255, 0, 255);
    strip.setPixelColor(1, 255, 0, 255);
    strip.setPixelColor(2, 255, 0, 255);
    strip.setPixelColor(3, 255, 255, 255);
    strip.setPixelColor(4, 255, 0, 255);
    strip.setPixelColor(5, 255, 255, 255);
    strip.show();

    //Make sure that we aren't constantly clearing the display//
    if (OledClear == false)
    {
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("Layer 2");
      display.println("Hello World!");
      display.display();
      OledClear = true;
    }
    //Mouse Functions, first value is horizontal, second value is vertical//
    //Movement is by pixels (we have a small amount because it is contantly going)//
    if (digitalRead(Down) == LOW)
    {
      Mouse.move(0, 2);
    }
    if (digitalRead(Up) == LOW)
    {
      Mouse.move(0, -2);
    }
    if (digitalRead(Right) == LOW)
    {
      Mouse.move(2, 0);
    }
    if (digitalRead(Left) == LOW)
    {
      Mouse.move(-2, 0);
    }
    if (digitalRead(LUp) == LOW)
    {
      Mouse.click(MOUSE_LEFT);
      delay(250);
    }
    if (digitalRead(RUp) == LOW)
    {
      Mouse.click(MOUSE_RIGHT);
      delay(250);
    }
  }
}
