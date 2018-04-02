#include "robust_serial.hpp"

using namespace std;


void write_order(fstream &file, enum Order order)
{
	write_i8(file, (int8_t) order);
}

void write_i8(fstream &file, int8_t num)
{
  file.write((char *)&num, sizeof(int8_t));
}

void write_i16(fstream &file, int16_t num)
{
	int8_t buffer[2] = {(int8_t) (num & 0xff), (int8_t) (num >> 8)};
	file.write((char *)buffer, 2*sizeof(int8_t));
}

void write_i32(fstream &file, int32_t num)
{
	int8_t buffer[4] = {(int8_t) (num & 0xff), (int8_t) (num >> 8 & 0xff), (int8_t) (num >> 16 & 0xff), (int8_t) (num >> 24 & 0xff)};
  file.write((char *)buffer, 4*sizeof(int8_t));
}

void write_u32(fstream &file, uint16_t num)
{
	uint8_t buffer[2] = {(uint8_t) (num & 0xff), (uint8_t) (num >> 8)};
	file.write((char *)buffer, 2*sizeof(uint8_t));
}


Order read_order(SerialPort &serial_port, const unsigned int timeout_ms)
{
  SerialPort::DataBuffer buffer;
  serial_port.Read(buffer, 1, timeout_ms);
  return (Order) buffer[0];
}

Order read_order(fstream &serial_file)
{
  return (Order) read_i8(serial_file);
}

int8_t read_i8(SerialPort &serial_port)
{
  SerialPort::DataBuffer buffer;
  serial_port.Read(buffer, 1);
  // We have to cast it to keep the sign
  return (int8_t) static_cast<signed char>(buffer[0]);
}

int8_t read_i8(fstream &file)
{
	char buffer[1];
  file.read(buffer, 1);
  return (int8_t) buffer[0];
}

int16_t read_i16(SerialPort &serial_port)
{
  SerialPort::DataBuffer buffer;
  serial_port.Read(buffer, 2);
  return (((int16_t) buffer[0]) & 0xff) | (((int16_t) buffer[1]) << 8 & 0xff00);
}

int16_t read_i16(fstream &file)
{
  char buffer[2];
  file.read(buffer, 2);
	return (((int16_t) buffer[0]) & 0xff) | (((int16_t) buffer[1]) << 8 & 0xff00);
}

uint16_t read_u16(SerialPort &serial_port)
{
  SerialPort::DataBuffer buffer;
  serial_port.Read(buffer, 2);
  return (((uint16_t) buffer[0]) & 0xff) | (((uint16_t) buffer[1]) << 8);
}

int32_t read_i32(SerialPort &serial_port)
{
  SerialPort::DataBuffer buffer;
  serial_port.Read(buffer, 4);
  return (((int32_t) buffer[0]) & 0xff) | (((int32_t) buffer[1]) << 8 & 0xff00) | (((int32_t) buffer[2]) << 16 & 0xff0000) | (((int32_t) buffer[3]) << 24 & 0xff000000);
}

int32_t read_i32(fstream &file)
{
  char buffer[4];
  file.read(buffer, 4);
  return (((int32_t) buffer[0]) & 0xff) | (((int32_t) buffer[1]) << 8 & 0xff00) | (((int32_t) buffer[2]) << 16 & 0xff0000) | (((int32_t) buffer[3]) << 24 & 0xff000000);
}
