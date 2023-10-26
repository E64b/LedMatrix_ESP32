#include "main.h"

void Graphics(){
	for(uint16_t i=0; i<=NUM_LEDS; i++){
		matrix_1[i]=CRGB::Red;
		matrix_2[i]=CRGB::Green;
		matrix_3[i]=CRGB::Blue;
		matrix_4[i]=CRGB::Aqua;
		matrix_5[i]=CRGB::Amethyst;
		matrix_6[i]=CRGB::Lime;
		matrix_7[i]=CRGB::LimeGreen;
		matrix_8[i]=CRGB::Orange;
		matrix_9[i]=CRGB::Pink;
		matrix_10[i]=CRGB::Silver;
		matrix_11[i]=CRGB::Yellow;
		matrix_12[i]=CRGB::GreenYellow;
		matrix_13[i]=CRGB::White;
		matrix_14[i]=CRGB::Purple;
		FastLED.show();
		Serial.print("Current LED ");
		Serial.println(i);
		delay(50);
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
		Serial.print("Current LED OFF ");
		Serial.println(i);
		FastLED.show();
		delay(10);
		}
	}