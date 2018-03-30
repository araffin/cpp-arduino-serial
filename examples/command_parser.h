#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H
#include <robust_serial.hpp>

#define PORT "/dev/ttyACM0"

int getIntFromUserInput(std::string infoMessage);
unsigned int getUnsignedIntFromUserInput(std::string infoMessage);
long getLongIntFromUserInput(std::string infoMessage);


#endif
