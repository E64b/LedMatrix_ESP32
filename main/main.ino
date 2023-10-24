#include <FastLED.h>
//#include <SmartMatrix.h>

#define NUM_LEDS 1792
#define DATA_PIN 1
#define DATA2_PIN 3

#define BRIGHTNESS 100
#define LED_TYPE WS2812
#define COLOR_ORDER GRB

CRGB ledsL[NUM_LEDS];
CRGB ledsR[NUM_LEDS];

void setup(){
	FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(ledsL, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA2_PIN, COLOR_ORDER>(ledsR, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.setBrightness(BRIGHTNESS);
	}

void loop(){
	for(uint32_t i=0; i<=NUM_LEDS; i++){
		ledsL[i]=CRGB::Red;
		FastLED.show();
		delay(100);
		ledsL[i]=CRGB::Black;
		FastLED.show();
		delay(100);
		}
	for(uint32_t i=0; i<=NUM_LEDS; i++){
		ledsR[i]=CRGB::Red;
		FastLED.show();
		delay(100);
		ledsR[i]=CRGB::Black;
		FastLED.show();
		delay(100);
		}
	}