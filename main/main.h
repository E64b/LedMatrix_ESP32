#pragma once

#include <Arduino.h>
#include <FastLED.h>
#include <Print.h>
#include <inttypes.h>
#include <stdio.h>
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

#define LED_TYPE WS2812
#define COLOR_ORDER GRB

/* ==SETUP== */
#define BRIGHTNESS 255
#define MAX_A 4
#define MAX_V 5

#define WIGTH 16
#define HEIGHT 16
#define NUM_LEDS (WIGTH * HEIGHT)
#define MAX_POWER (MAX_A * 1000)

typedef struct {
  uint8_t matrix_id = 0;
  uint8_t img_id = 0;
  bool update = false;
  bool reverse = false;
  uint8_t string = 0;
} Data;

extern CRGB matrix[MATRIX_COUNT][NUM_LEDS];
extern Data data;
extern uint8_t *GetImage(uint8_t c);

void Graphics();
void Serial_In();
void Serial_Out();