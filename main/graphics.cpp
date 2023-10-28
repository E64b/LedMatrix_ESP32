#include "main.h"

void Graphics(){
		fill_solid(matrix_1, 256, CRGB::Red);
		fill_solid(matrix_2, 256, CRGB::Green);
		fill_solid(matrix_3, 256, CRGB::Blue);
		fill_solid(matrix_4, 256, CRGB::Aqua);
		fill_solid(matrix_5, 256, CRGB::Amethyst);
		fill_solid(matrix_6, 256, CRGB::Lime);
		fill_solid(matrix_7, 256, CRGB::LimeGreen);
		fill_solid(matrix_8, 256, CRGB::Orange);
		fill_solid(matrix_9, 256, CRGB::Pink);
		fill_solid(matrix_10, 256, CRGB::Silver);
		fill_solid(matrix_11, 256, CRGB::Yellow);
		fill_solid(matrix_12, 256, CRGB::GreenYellow);
		fill_solid(matrix_13, 256, CRGB::White);
		fill_solid(matrix_14, 256, CRGB::Purple);
		FastLED.show();
		delay(2500);
		

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
		Serial.print("Current LED OFF ");
		Serial.println(i);
		FastLED.show();
		delay(10);
		}
	}