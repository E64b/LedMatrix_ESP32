#include "main.h"

uint32_t getPixel(const uint32_t *pChar, uint16_t index) {
  uint16_t num_row = 1 + index / WIDTH;
  uint16_t parity = num_row % 2;
  if (parity == 0) {
    return pChar[index];
  } else {
    uint16_t index_string_max = num_row * WIDTH;
    index %= WIDTH;
    /* Serial.print(index);
    Serial.print(";");
    Serial.print(index_string_max);
    Serial.print(";");
    Serial.print(num_row);
    Serial.print(" > ");
    Serial.println(index_string_max - 1 - index);
    */
    return pChar[index_string_max - 1 - index];
  }
}
void PrintHex(uint32_t x) {
  char buff[9];
  for (uint8_t i = 0; i < 8; i++) {
    uint8_t c = x & 0xF;
    buff[7 - i] = c <= 9 ? '0' + c : 'A' + (c - 10);
    x >>= 4;
  }
  buff[8] = 0;
  Serial.print(buff);
}

void PrintImg(const uint32_t *pBuff) {
  for (uint16_t i = 0; i < NUM_LEDS; i++) {
    PrintHex(pBuff[i]);
    if ((i + 1) % WIDTH == 0) {
      Serial.println();
    } else {
      Serial.print(' ');
    }
  }
}

void Graphics() {
  if (data.update) {
    const uint32_t *img = GetImage(data.img_id);
    Serial.println("SEND1");
    PrintImg(img);
    Serial.println("SEND2");
    for (uint16_t i = 0; i < NUM_LEDS; i++) {
      uint32_t pixel = getPixel(img, i);
      PrintHex(pixel);
      if ((i + 1) % WIDTH == 0) {
        Serial.println();
      } else {
        Serial.print(' ');
      }
      matrix[data.matrix_id][i] = pixel;
    }
    Serial.println("-----------");
    FastLED.show();
    data.update = false;
    data.received = true;
    data.input_matrix_id = true;
  }
}
