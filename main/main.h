#include <FastLED.h>
//#include <SmartMatrix.h>

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

#define BRIGHTNESS 175
#define LED_TYPE WS2812
#define COLOR_ORDER GRB
#define WIGTH 16
#define HEIGHT 16
#define NUM_LEDS (WIGTH * HEIGHT)

extern CRGB matrix_1[NUM_LEDS];
extern CRGB matrix_2[NUM_LEDS];
extern CRGB matrix_3[NUM_LEDS];
extern CRGB matrix_4[NUM_LEDS];
extern CRGB matrix_5[NUM_LEDS];
extern CRGB matrix_6[NUM_LEDS];
extern CRGB matrix_7[NUM_LEDS];
extern CRGB matrix_8[NUM_LEDS];
extern CRGB matrix_9[NUM_LEDS];
extern CRGB matrix_10[NUM_LEDS];
extern CRGB matrix_11[NUM_LEDS];
extern CRGB matrix_12[NUM_LEDS];
extern CRGB matrix_13[NUM_LEDS];
extern CRGB matrix_14[NUM_LEDS];

void Graphics();
void Serial_In();