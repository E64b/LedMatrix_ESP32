#include "main.h"

uint8_t getPixel(uint8_t *pChar, uint16_t index) {
  uint8_t num_string = index / WIDTH;
  uint8_t parity = (1 + num_string) % 2;
  if (parity == 0) // —читаем четные строки
  {
    return pChar[index];
  } else // —читаем нечетные строки
  {
    uint16_t index_string_max = num_string * WIDTH;
    return pChar[index_string_max - 1 - index];
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
