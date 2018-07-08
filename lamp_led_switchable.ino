#include "FastLED.h"

#define NUM_LEDS 288
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() {
LEDS.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
LEDS.setBrightness(64);
}

void red() {
fill_solid(leds,NUM_LEDS,CRGB(0,255,0)); 
}

void red_shift_random() { 

red();

for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0,i*random8()+45,0);
    FastLED.show();
    delay(10);
}

delay(3000);

for(int i = (NUM_LEDS-1); i>= 0; i--) {
    leds[i] = CRGB(0,255,0);
    FastLED.show();
    delay(10);
}

}

void loop() {
//red();
red_shift_random();
}
