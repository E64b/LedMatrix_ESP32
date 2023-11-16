#include "main.h"

void Serial_In() {
  if (data.received) {
    while (Serial.available() > 0) {
      int VAL = (int)Serial.read();
      if (VAL == '!') {
        data.received = false;
        data.update = true;
        break;
      }
      if (data.input_matrix_id) {
        data.matrix_id = VAL;
        data.input_matrix_id = false;
        data.input_img_id = true;
      }
      if (data.input_img_id) {
        data.img_id = VAL;
        data.input_img_id = false;
      }
    }
  }
}

void Serial_Out() { /* Тут будет ПонгПинг для головного модуля*/
}