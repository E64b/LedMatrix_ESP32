#include "main.h"

UIState uiState;

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

	FastLED.setMaxPowerInVoltsAndMilliamps(5, 20000);

	FastLED.setBrightness(BRIGHTNESS);
	}

void loop(){
	Graphics();
	Serial_In();
	}