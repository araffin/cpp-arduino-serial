#include "lib.hpp"

using namespace std;


/**
 * Send one order (one byte) to the other arduino
 * @param myOrder type of order
 */
void write_order(fstream &file, enum Order myOrder)
{
	write_i8(file, (int8_t) myOrder);
}

/**
 * Send a int of one byte
 * @param num
 */
void write_i8(fstream &file, int8_t num)
{
	int8_t* oneByte = (int8_t*) &num;
  file.write((char *)oneByte, sizeof(int8_t));
}


/**
 * Send a two bytes signed int via the serial
 * @param num the number to send
 */
void write_i16(fstream &file, int16_t num)
{
	int8_t buffer[2] = {(int8_t) (num & 0xff), (int8_t) (num >> 8)};
	file.write((char *)buffer, 2*sizeof(int8_t));
}

/**
 * Send a four bytes signed int (long) via the serial
 * @param num the number to send (−2,147,483,647, +2,147,483,647)
 */
void write_i32(fstream &file, int32_t num)
{
	int8_t buffer[4] = {(int8_t) (num & 0xff), (int8_t) (num >> 8 & 0xff), (int8_t) (num >> 16 & 0xff), (int8_t) (num >> 24 & 0xff)};
  file.write((char *)buffer, 4*sizeof(int8_t));
}

/**
 * Send a two bytes unsigned (max 2**16 -1) int via the serial
 * @param num the number to send
 */
void write_u32(fstream &file, uint16_t num)
{
	uint8_t buffer[2] = {(uint8_t) (num & 0xff), (uint8_t) (num >> 8)};
	file.write((char *)buffer, 2*sizeof(uint8_t));
}


/**
 * Read two bytes (16 bits) from the serial and convert it to an unsigned int
 * @return the decoded unsigned int
 */
uint16_t read_u16(SerialPort &serial_port)
{
  SerialPort::DataBuffer charBuff;
  serial_port.Read(charBuff, 2);
  return (uint16_t)(charBuff[0] & 0xff) | (uint16_t)(charBuff[1] << 8);
}
/**
 * Read two bytes from the serial and convert it to an int
 * @return the decoded int
 */
int16_t read_i16(SerialPort &serial_port)
{
  SerialPort::DataBuffer charBuff;
  serial_port.Read(charBuff, 2);
  return (int16_t)(charBuff[0] & 0xff) | (int16_t)(charBuff[1] << 8 & 0xff00);
}

/**
 * Read four bytes from the serial and convert it to an long
 * @return the decoded int
 */
int32_t read_i32(SerialPort &serial_port)
{
  SerialPort::DataBuffer charBuff;
  serial_port.Read(charBuff, 4);
  return (int8_t)(charBuff[0] & 0xff) | (int8_t)(charBuff[1] << 8 & 0xff00) | (int8_t)(charBuff[2] << 16 & 0xff0000) | (int8_t)(charBuff[3] << 24 & 0xff000000);
}

/**
 * Read one byte from the serial and convert it to an int
 * @return the decoded int
 */
int8_t read_i8(SerialPort &serial_port)
{
  SerialPort::DataBuffer charBuff;
  serial_port.Read(charBuff, 1);
  // We have to cast it to keep the sign
  return (int8_t) static_cast<signed char>(charBuff[0]);
}

/**
 * Read one byte from the serial and cast it to an Order
 * @return the order received
 */
Order read_order(SerialPort &serial_port, const unsigned int msTimeout)
{
  SerialPort::DataBuffer buffer;
  serial_port.Read(buffer, 1, msTimeout);
  return (Order) buffer[0];
}
