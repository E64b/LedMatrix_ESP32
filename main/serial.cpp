#include "main.h"

void Serial_In() {
  if (recived) {
    while (Serial.available() > 0) {
      char VAL = (char)Serial.read();
      if (VAL == '!') {
        break;
      }
      if (data.input_matrix_id) {
        data.matrix_id += VAL;
      }
      if (data.input_img_id) {
        data.img_id += VAL;
      }
    }
  }
}

void Serial_Out() { /* Тут будет ПонгПинг для головного модуля*/ }