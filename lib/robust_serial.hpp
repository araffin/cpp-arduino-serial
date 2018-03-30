#ifndef ROBUST_SERIAL_H
#define ROBUST_SERIAL_H
#include <fstream>
#include <cstdint>  // int8_t, int16_t, ...
#include <SerialStream.h>  // libserial-dev
#include "order.h"

void write_order(std::fstream &file, enum Order myOrder);
void write_i8(std::fstream &file, int8_t num);
void write_i16(std::fstream &file, int16_t num);
void write_u16(std::fstream &file, uint16_t num);
void write_i32(std::fstream &file, int32_t num);

Order read_order(SerialPort &serial_port, const unsigned int msTimeout);
int8_t read_i8(SerialPort &serial_port);
int16_t read_i16(SerialPort &serial_port);
uint16_t read_u16(SerialPort &serial_port);
int32_t read_i32(SerialPort &serial_port);

#endif
