#pragma once

#include <Arduino.h>
#include <FastLED.h>
#include <inttypes.h>
#include <stdio.h>

#define MATRIX_COUNT 14
#define DEVICE_ID 0x20
#define FEATURE_ID "wall-screen"

#define DATA1_PIN 23
#define DATA2_PIN 22
#define DATA3_PIN 21
#define DATA4_PIN 19
#define DATA5_PIN 18
#define DATA6_PIN 5
#define DATA7_PIN 17
#define DATA8_PIN 16
#define DATA9_PIN 4
#define DATA10_PIN 0
#define DATA11_PIN 2
#define DATA12_PIN 15
#define DATA13_PIN 27
#define DATA14_PIN 14

#define LED_TYPE WS2812
#define COLOR_ORDER GRB

/* ==SETUP== */
#define BRIGHTNESS 127 // 0 ... 255
#define MAX_A 4
#define MAX_V 5
#define DEBUG false // true or false

#define WIDTH 16
#define HEIGHT 16
#define NUM_LEDS (WIDTH * HEIGHT)
#define MAX_POWER (MAX_A * 1000)

#pragma pack(1, push)

typedef struct {
  uint8_t matrix_id = 0;
  uint8_t img_id = 0;
  bool update = false;
  bool pong = false;
  uint8_t string = 0;
  bool input_matrix_id = true;
  bool input_img_id = false;
  bool received = true;
} Data;

struct MessageHeader {
  uint16_t magic;
  uint8_t target;
  uint8_t sender;
  uint16_t size;
};

struct MessageFooter {
  uint8_t crc;
};

#define PROTO_MAGIC 0x0411
struct MessageAPI {

  MessageHeader header;
  bool HasValidHeader() const { return header.magic == PROTO_MAGIC; }
  bool HasValidSize() const { return header.size <= 0x7fff; }
  virtual bool IsValid() const { return HasValidHeader() && HasValidSize(); }

  uint8_t CRC8() const {
    uint8_t crc = 0x00;
    uint8_t extract;
    uint8_t sum;
    const uint8_t *data = (const uint8_t *)this;
    for (int i = 0; i < GetSize() - 1; i++) {
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
  void Send() {
    MakeValid();
    Serial.write((uint8_t *)this, GetSize());
  }

protected:
  virtual void MakeValid() {
    header.magic = PROTO_MAGIC;
    header.target = 0x00;
    header.sender = DEVICE_ID;
    header.size = GetSize();
  }
  virtual uint16_t GetSize() const { return sizeof(MessageAPI) + 1; }
};

template <typename T> struct Message : public MessageAPI {
  T payload;
  MessageFooter footer;

  bool HasValidCrc() const { return footer.crc == MessageAPI::CRC8(); }
  bool IsValid() const { return MessageAPI::IsValid() && HasValidCrc(); }

protected:
  uint16_t GetSize() const {
    return sizeof(T) + sizeof(MessageHeader) + sizeof(MessageFooter);
  }

  void MakeValid() {
    MessageAPI::MakeValid();
    footer.crc = MessageAPI::CRC8();
  }
};

struct EmptyMessage : public MessageAPI {
  MessageFooter footer;

  bool HasValidCrc() const { return footer.crc == MessageAPI::CRC8(); }
  bool IsValid() const { return MessageAPI::IsValid() && HasValidCrc(); }

protected:
  uint16_t GetSize() const {
    return sizeof(MessageHeader) + sizeof(MessageFooter);
  }
  void MakeValid() {
    MessageAPI::MakeValid();
    footer.crc = MessageAPI::CRC8();
  }
};

typedef struct {
  uint8_t matrix_id;
  uint8_t img_id;
} SetMatrixImage;

typedef Message<SetMatrixImage> SetMatrixImageMessage;
typedef EmptyMessage PongMessage;

#pragma pack(pop)

extern CRGB matrix[MATRIX_COUNT][NUM_LEDS];
extern Data data;
extern const uint32_t *GetImage(uint8_t imgCode);

void Graphics();
void Serial_In();
void Serial_Out();
