#include "main.h"

uint8_t getPixel(uint8_t *pChar, uint16_t index) {
  uint8_t string = ((index + 1) / 16) % 2;
  if (string == 0) // ������� ������ ������
  {
    return pChar[index + 16];
  } else // ������� �������� ������
  {
    return pChar[index];
  }
}

void Graphics() {
  uint8_t *img = GetImage(imgCode);

  if (data.update) {
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
      matrix[data.matrix_id][i] = getPixel(img, i);
    }
    FastLED.show();
    data.update = false;
  }
}
