#include "main.h"

void Serial_In() {
  if (data.received) {
    while (Serial.available() > 0) {
      uint8_t VAL = (uint8_t)Serial.parseInt();
      if (VAL == 200) {
        data.received = false;
        data.update = true;
        break;
      }
      if (data.input_matrix_id) {
        data.matrix_id = VAL;
        data.input_matrix_id = false;
        data.input_img_id = true;
        Serial.print("MATRIX ID ");
        Serial.println(data.matrix_id);
      } else if (data.input_img_id) {
        data.img_id = VAL;
        data.input_img_id = false;
        Serial.print("IMG ID ");
        Serial.println(data.img_id);
      }
    }
  }
}

void Serial_Out() { /* Тут будет ПонгПинг для головного модуля*/
}