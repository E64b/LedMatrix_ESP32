#include "main.h"

UIState uiState;

CRGB matrix[MATRIX_COUNT][NUM_LEDS];

void setup() {

  /*Init Serial*/
  Serial.begin(115200);
  while (!Serial) {
  }
  Serial.print("Serial OK");

  /*Init 14 channels*/
  FastLED.addLeds<LED_TYPE, DATA1_PIN, COLOR_ORDER>(matrix[0], NUM_LEDS)
      .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA2_PIN, COLOR_ORDER>(matrix[1], NUM_LEDS)
      .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA3_PIN, COLOR_ORDER>(matrix[2], NUM_LEDS)
      .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA4_PIN, COLOR_ORDER>(matrix[3], NUM_LEDS)
      .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA5_PIN, COLOR_ORDER>(matrix[4], NUM_LEDS)
      .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA6_PIN, COLOR_ORDER>(matrix[5], NUM_LEDS)
      .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA7_PIN, COLOR_ORDER>(matrix[6], NUM_LEDS)
      .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA8_PIN, COLOR_ORDER>(matrix[7], NUM_LEDS)
      .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA9_PIN, COLOR_ORDER>(matrix[8], NUM_LEDS)
      .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA10_PIN, COLOR_ORDER>(matrix[9], NUM_LEDS)
      .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA11_PIN, COLOR_ORDER>(matrix[10], NUM_LEDS)
      .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA12_PIN, COLOR_ORDER>(matrix[11], NUM_LEDS)
      .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA13_PIN, COLOR_ORDER>(matrix[12], NUM_LEDS)
      .setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE, DATA14_PIN, COLOR_ORDER>(matrix[13], NUM_LEDS)
      .setCorrection(TypicalLEDStrip);

  //FastLED.setMaxPowerInVoltsAndMilliamps(5, 20000);

  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  Graphics();
  Serial_In();
}