#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H
#include "order.h"

#define PORT "/dev/ttyACM0"

int getIntFromUserInput(std::string infoMessage);
unsigned int getUnsignedIntFromUserInput(std::string infoMessage);
long getLongIntFromUserInput(std::string infoMessage);


void write_order(enum Order myOrder);
void write_i8(int8_t num);
void write_i16(int16_t num);
void write_u16(uint16_t num);
void write_i32(int32_t num);

#endif
