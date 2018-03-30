#ifndef SERIAL_READER_H
#define SERIAL_READER_H
#include <SerialStream.h>  // libserial-dev
#include "order.h"

#define PORT "/dev/ttyACM0"
#define MAX_N_ORDER 1000
#define TIMEOUT_MS 30000 // 30s

Order read_order(SerialPort &serial_port, const unsigned int msTimeout);
int8_t read_i8(SerialPort &serial_port);
int16_t read_i16(SerialPort &serial_port);
uint16_t read_u16(SerialPort &serial_port);
int32_t read_i32(SerialPort &serial_port);

#endif
