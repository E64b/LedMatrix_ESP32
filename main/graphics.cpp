#include "main.h"

uint8_t getPixel(uint8_t *pChar, uint16_t index) { return pChar[index]; }

void Graphics() {
  uint8_t *img = GetImage(imgCode);

  if (uiState.update) {

    for (uint16_t i = 0; i < NUM_LEDS; i++) {
      matrix[id][i] = getPixel(img, i);
    }

    FastLED.show();
  }
}
