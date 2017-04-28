/* This example for the Ws2812 LED strip was developed by Marc Bucchieri
 *  as an alternative to the somewhat confusing WS2812_Breakout_Example.ino
 *  
 *  This code fades a section of the strip on and off in red
*/
#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"

#define PIN 4
#define LED_COUNT 75

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

  for(int j=0; j<255; j++) {
    for(int i=15;i<20;i++) {
      leds.setPixelColor(i,j,0,0);
    }
    leds.show();
    delay(1);
  }
  for(int j=255; j>=0; j--) {
    for(int i=15;i<20;i++) {
      leds.setPixelColor(i,j,0,0);
    }
    leds.show();
    delay(1);
  }
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

