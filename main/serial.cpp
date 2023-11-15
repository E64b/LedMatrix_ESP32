#include "main.h"

void Serial_In() {
  while (Serial.available() > 0) {
    char VAL = (char)Serial.read();
    data.matrix_id = VAL;
    break;
  }
}

void Serial_Out() {
}