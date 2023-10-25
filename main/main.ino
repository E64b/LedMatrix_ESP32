#include "main.h"

CRGB matrix_1[NUM_LEDS];
CRGB matrix_2[NUM_LEDS];
CRGB matrix_3[NUM_LEDS];
CRGB matrix_4[NUM_LEDS];
CRGB matrix_5[NUM_LEDS];
CRGB matrix_6[NUM_LEDS];
CRGB matrix_7[NUM_LEDS];
CRGB matrix_8[NUM_LEDS];
CRGB matrix_9[NUM_LEDS];
CRGB matrix_10[NUM_LEDS];
CRGB matrix_11[NUM_LEDS];
CRGB matrix_12[NUM_LEDS];
CRGB matrix_13[NUM_LEDS];
CRGB matrix_14[NUM_LEDS];

void setup(){
	/*Init Serial*/
	Serial.begin(115200);
	while(!Serial){
		}
	Serial.print("Serial OK");

	/*Init 14 channels*/
	FastLED.addLeds<LED_TYPE, DATA1_PIN, COLOR_ORDER>(matrix_1, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA2_PIN, COLOR_ORDER>(matrix_2, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA3_PIN, COLOR_ORDER>(matrix_3, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA4_PIN, COLOR_ORDER>(matrix_4, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA5_PIN, COLOR_ORDER>(matrix_5, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA6_PIN, COLOR_ORDER>(matrix_6, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA7_PIN, COLOR_ORDER>(matrix_7, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA8_PIN, COLOR_ORDER>(matrix_8, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA9_PIN, COLOR_ORDER>(matrix_9, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA10_PIN, COLOR_ORDER>(matrix_10, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA11_PIN, COLOR_ORDER>(matrix_11, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA12_PIN, COLOR_ORDER>(matrix_12, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA13_PIN, COLOR_ORDER>(matrix_13, NUM_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.addLeds<LED_TYPE, DATA14_PIN, COLOR_ORDER>(matrix_14, NUM_LEDS).setCorrection(TypicalLEDStrip);

	FastLED.setBrightness(BRIGHTNESS);
	}

void loop(){
	for(uint16_t i=0; i<=NUM_LEDS; i++){
		matrix_1[i]=CRGB::Red;
		matrix_2[i]=CRGB::Red;
		matrix_3[i]=CRGB::Red;
		matrix_4[i]=CRGB::Red;
		matrix_5[i]=CRGB::Red;
		matrix_6[i]=CRGB::Red;
		matrix_7[i]=CRGB::Red;
		matrix_8[i]=CRGB::Red;
		matrix_9[i]=CRGB::Red;
		matrix_10[i]=CRGB::Red;
		matrix_11[i]=CRGB::Red;
		matrix_12[i]=CRGB::Red;
		matrix_13[i]=CRGB::Red;
		matrix_14[i]=CRGB::Red;
		FastLED.show();
		delay(100);
		}
	for(uint16_t i=0; i<=NUM_LEDS; i++){
		matrix_1[i]=CRGB::Black;
		matrix_2[i]=CRGB::Black;
		matrix_3[i]=CRGB::Black;
		matrix_4[i]=CRGB::Black;
		matrix_5[i]=CRGB::Black;
		matrix_6[i]=CRGB::Black;
		matrix_7[i]=CRGB::Black;
		matrix_8[i]=CRGB::Black;
		matrix_9[i]=CRGB::Black;
		matrix_10[i]=CRGB::Black;
		matrix_11[i]=CRGB::Black;
		matrix_12[i]=CRGB::Black;
		matrix_13[i]=CRGB::Black;
		matrix_14[i]=CRGB::Black;
		FastLED.show();
		delay(100);
		}
	}