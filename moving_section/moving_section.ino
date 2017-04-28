/* This code was developed by Marc Bucchieri as an alternative to the
 *  WS2812 breakout example code. It shows a more intuitive way to 
 *  have a section of LEDs move back and forth along the strip.
 *  
 *  Hopefully this code can be built upon for future, more
 *  expressive code for the LED strip.
*/
#include <Adafruit_NeoPixel.h>
#include "Color_Definitions.h"

#define PIN 4
#define LED_COUNT 150

// Create an instance of the Adafruit_NeoPixel class called "leds".
// That'll be what we refer to from here on...
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  leds.begin();  // Call this to start up the LED strip.
  clearLEDs();   // This function, defined below, turns all LEDs off...
  leds.show();   // ...but the LEDs don't actually update until you call this.
}

void loop()
{
  // the static keyword means these variables will only be initialized 
  // on the first iteration of loop
  static int center = 2;
  static int center_shift = 1;      // increase this number and the section will move faster!
  static byte red = 0;
  static byte green = 0;
  static byte blue = 255;

  clearLEDs();
  for(int i=center-4;i<center+4;i++) {
    leds.setPixelColor(i,red,green,blue);
//    leds.setPixelColor(i,PEACHPUFF);
//    leds.setPixelColor(i,0xFFDAB9);   // red = FF = 255, green = DA = 218, blue = B9 = 185
  }
  leds.show();

  center += center_shift;
  if(center == LED_COUNT -2 || center == 2) {
    center_shift = -center_shift;
    red = random(0,255);
    green = random(0,0);
    blue = random(0,255);
  }
  delay(10);
}

// Sets all LEDs to off, but DOES NOT update the display;
// call leds.show() to actually turn them off after this.
void clearLEDs()
{
  for (int i=0; i<LED_COUNT; i++)
  {
    leds.setPixelColor(i, 0);
  }
}

