#include "main.h"

#define BUFF_SIZE 32

uint8_t buff[BUFF_SIZE];

uint8_t CRC8(uint8_t *data, int length) {
  uint8_t crc = 0x00;
  uint8_t extract;
  uint8_t sum;
  for (int i = 0; i < length; i++) {
    extract = *data;
    for (uint8_t tempI = 8; tempI; tempI--) {
      sum = (crc ^ extract) & 0x01;
      crc >>= 1;
      if (sum) {
        crc ^= 0x8C;
      }
      extract >>= 1;
    }
    data++;
  }
  return crc;
}
#define STATE_HS_UNKNOWN 0
#define STATE_HS_HEADER 1
#define STATE_HS_ID 2
#define STATE_HS_SRC 3
#define STATE_HS_PROTO 4
#define STATE_HS_FOOTER 5

uint8_t hsState = STATE_HS_UNKNOWN;
String hsId;
String hsProto;

void Serial_In() {
  while (Serial.available() > 0) {
    char val = (char)Serial.read();

    switch (hsState) {
    case STATE_HS_UNKNOWN:
      if (val == '>') {
        hsState = STATE_HS_HEADER;
      } else {
        /*TODO добавлять val в текущий читаемый пакет*/
      }
      break;

    case STATE_HS_HEADER:
      if (val == '>') {
        hsId = "";
        hsState = STATE_HS_ID;
      } else {
        hsState = STATE_HS_UNKNOWN;
        /*
         * добавить '>' текущий читаемый пакет
         *  TODO добавлять val в текущий читаемый пакет
         */
      }
      break;

    case STATE_HS_ID:
      if (val == ':') {
        hsState = STATE_HS_SRC;
      } else if (val >= 'A' && val <= 'F' || val >= 'a' && val <= 'f' ||
                 val >= '0' && val <= '9' || val == '.' || val == '-') {
        hsId += val;
      } else {
        hsState = STATE_HS_UNKNOWN;
      }
      break;

    case STATE_HS_SRC:
      if (val == ':') {
        hsProto = "";
        hsState = STATE_HS_PROTO;
      } else if (val != '0') {
        hsState = STATE_HS_UNKNOWN;
      }
      break;

    case STATE_HS_PROTO:
      if (val == '<') {
        hsState = STATE_HS_FOOTER;
      } else {
        hsProto += val;
      }
      break;

    case STATE_HS_FOOTER:
      if (val == '<') {
        if (hsProto == "nlic-v1") {
          String str("<<");
          str += hsId + ":" + String(DEVICE_ID, HEX) + ":1:" + FEATURE_ID;
          str += ">>";
          Serial.print(str);
        }
      }
      hsState = STATE_HS_UNKNOWN;
      break;
    }
  }
}
void Serial_Out() {
  if (data.pong) {
    PongMessage msg;
    msg.Send();
    data.pong = false;

    /*uint8_t pong_msg[] = {0x04, 0x11, 0x00, DEVICE_ID, crc};
    uint8_t crc = CRC8(pong_msg, sizeof(pong_msg) - 1);
    Serial.write(pong_msg, sizeof(pong_msg));*/
  }
}