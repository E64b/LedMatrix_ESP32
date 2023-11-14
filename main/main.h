#pragma once

#include <FastLED.h>
#include <Arduino.h>
#include <stdio.h>
#include <stdint.h>
#include <Print.h>
#include <inttypes.h>
#include <cstdint>

// #include <LEDMatrix.h>

#define MATRIX_COUNT 14

#define DATA1_PIN 23
#define DATA2_PIN 22
#define DATA3_PIN 21
#define DATA4_PIN 19
#define DATA5_PIN 18
#define DATA6_PIN 5
#define DATA7_PIN 17
#define DATA8_PIN 16
#define DATA9_PIN 4
#define DATA10_PIN 0
#define DATA11_PIN 2
#define DATA12_PIN 15
#define DATA13_PIN 27
#define DATA14_PIN 14

#define BRIGHTNESS 255
#define LED_TYPE WS2812
#define COLOR_ORDER GRB
#define WIGTH 16
#define HEIGHT 16
#define NUM_LEDS (WIGTH * HEIGHT)

typedef struct {
  uint8_t matrix = 0;
  uint8_t picture = 0;
  bool update = false;
} UIState;

extern CRGB matrix[MATRIX_COUNT][NUM_LEDS];
extern UIState uiState;
extern uint8_t *GetImage(uint8_t c);

void Graphics();
void Serial_In();