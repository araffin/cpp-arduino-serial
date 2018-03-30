#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H
#include <fstream>
#include "order.h"

#define PORT "/dev/ttyACM0"

int getIntFromUserInput(std::string infoMessage);
unsigned int getUnsignedIntFromUserInput(std::string infoMessage);
long getLongIntFromUserInput(std::string infoMessage);


void write_order(std::fstream &file, enum Order myOrder);
void write_i8(std::fstream &file, int8_t num);
void write_i16(std::fstream &file, int16_t num);
void write_u16(std::fstream &file, uint16_t num);
void write_i32(std::fstream &file, int32_t num);

#endif
