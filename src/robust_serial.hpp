#ifndef ROBUST_SERIAL_H
#define ROBUST_SERIAL_H
#include <fstream>
#include <cstdint>  // int8_t, int16_t, ...
#include <SerialStream.h>  // libserial-dev
#include "order.h"

/**
 * Send one order (one byte)
 * @param order the order to send
 */
void write_order(std::fstream &file, enum Order order);

/**
 * Write one byte int to a file/serial port
 * @param file fstream object
 * @param num
 */
void write_i8(std::fstream &file, int8_t num);

/**
 * Write two bytes int to a file/serial port.
 * @param file fstream object
 * @param num the number to send
 */
void write_i16(std::fstream &file, int16_t num);

/**
 * Write four bytes int to a file/serial port.
 * @param num the number to send (−2,147,483,647, +2,147,483,647)
 */
void write_i32(std::fstream &file, int32_t num);

/**
 * Send a two bytes unsigned (max 2**16 -1) int via the serial
 * @param num the number to send
 */
void write_u16(std::fstream &file, uint16_t num);

/**
 * Read one byte from the serial and cast it to an Order
 * @param  serial_port SerialPort object
 * @param  msTimeout   Read Timeout in ms
 * @return the order received
 */
Order read_order(SerialPort &serial_port, const unsigned int timeout_ms);
Order read_order(std::fstream &file);

/**
 * Read one byte from a serial port and convert it to a 8 bits int
 * @param  serial_port SerialPort object
 * @return the decoded number
 */
int8_t read_i8(SerialPort &serial_port);
// Variant for reading file
int8_t read_i8(std::fstream &file);

/**
 * Read two bytes from a serial port and convert it to a 16 bits int
 * @param  serial_port SerialPort object
 * @return the decoded number
 */
int16_t read_i16(SerialPort &serial_port);
// Variant for reading file
int16_t read_i16(std::fstream &file);
/**
 * Read two bytes from a serial port and convert it to a 16 bits unsigned int
 * @param  serial_port SerialPort object
 * @return the decoded number
 */
uint16_t read_u16(SerialPort &serial_port);

/**
 * Read four bytes from a serial port and convert it to a 32 bits int
 * @param  serial_port SerialPort object
 * @return the decoded number
 */
int32_t read_i32(SerialPort &serial_port);
// Variant for reading file
int32_t read_i32(std::fstream &file);


#endif
