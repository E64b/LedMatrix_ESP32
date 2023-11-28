#include "main.h"

#define BUFF_SIZE 256

uint16_t buffIndex = 0;
uint8_t buff[BUFF_SIZE];

MessageAPI *pMsg = NULL;

#define STATE_HS_UNKNOWN 0
#define STATE_HS_HEADER 1
#define STATE_HS_ID 2
#define STATE_HS_SRC 3
#define STATE_HS_PROTO 4
#define STATE_HS_FOOTER 5
#define STATE_PKG_READING_HEADER 6
#define STATE_PKG_READING_DATA 7
#define STATE_PKG_READING_CRC 8

uint8_t hsState = STATE_HS_UNKNOWN;
String hsId;
String hsProto;

void Serial_In() {
  while (Serial.available() > 0) {
    char val = (char)Serial.read();
  checkState:
    switch (hsState) {
    case STATE_HS_UNKNOWN:
      if (val == '>') {
        hsState = STATE_HS_HEADER;
      } else {
        if (buffIndex == 0 && val == 0x04 || buffIndex == 1 && val == 0x11) {
          buff[buffIndex++] = val;
          if (buffIndex == 2) {
            hsState = STATE_PKG_READING_HEADER;
          }
        } else {
          buffIndex = 0;
        }
      }
      break;

    case STATE_HS_HEADER:
      if (val == '>') {
        hsId = "";
        hsState = STATE_HS_ID;
        buffIndex = 0;
        pMsg = NULL;
      } else {
        hsState = STATE_HS_UNKNOWN;
        buff[buffIndex++] = '>';
        buff[buffIndex++] = val;
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

    case STATE_PKG_READING_HEADER:
      if (buffIndex >= sizeof(MessageHeader)) {
        pMsg = (MessageAPI *)buff;
        if (pMsg->header.size <= 0x7fff && pMsg->header.target == DEVICE_ID) {
          if (pMsg->header.size == 0) {
            hsState = STATE_PKG_READING_CRC;
            goto checkState;
          } else {
            hsState = STATE_PKG_READING_DATA;
            goto checkState;
          }
        } else {
          hsState = STATE_HS_UNKNOWN;
          buffIndex = 0;
          pMsg = NULL;
        }
      } else {
        buff[buffIndex++] = val;
      }
      break;

    case STATE_PKG_READING_DATA:
      if (buffIndex >= pMsg->header.size - 1) {
        hsState = STATE_PKG_READING_CRC;
        goto checkState;
      } else {
        buff[buffIndex++] = val;
      }
      break;

    case STATE_PKG_READING_CRC:
      if (pMsg && pMsg->header.size <= buffIndex) {
        uint8_t crc = pMsg->CRC8();
        if (crc == val) {
          SetMatrixImageMessage *ptr = (SetMatrixImageMessage *)pMsg;
          if (ptr->HasValidSize()) {
            data.matrix_id = ptr->payload.matrix_id;
            data.img_id = ptr->payload.img_id;
          }
        }
      }
      buffIndex = 0;
      hsState = STATE_HS_UNKNOWN;
      pMsg = NULL;
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