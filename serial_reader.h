#ifndef SERIAL_READER_H
#define SERIAL_READER_H
#include "order.h"

#define PORT "/dev/ttyACM0"
#define MAX_N_ORDER 1000
#define TIMEOUT_MS 30000 // 30s

Order read_order(const unsigned int msTimeout);
int8_t read_i8();
int16_t read_i16();
uint16_t read_u16();
int32_t read_i32();

#endif
