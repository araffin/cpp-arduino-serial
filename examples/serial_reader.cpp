#include <iostream>
#include <string>
#include <exception>
#include <bitset> //Binary representation
#include "serial_reader.h"

using namespace std;


int main(int argc, char const *argv[])
{
	string default_filename = DEFAULT_PORT;
	string serial_filename = "";

	cout << "Enter the name of the serial file (default: " << default_filename << " )" << endl;
	getline(cin, serial_filename);

	if(serial_filename.empty())
	{
		cout << "Using default serial file : " << default_filename << endl;
		serial_filename = default_filename;
	}

	SerialPort serial_port(serial_filename);

	const unsigned int timeout_ms = TIMEOUT_MS;
	Order current_order;
	serial_port.Open(SerialPort::BAUD_115200, SerialPort::CHAR_SIZE_8,
									 SerialPort::PARITY_NONE, SerialPort::STOP_BITS_1,
									 SerialPort::FLOW_CONTROL_NONE);

	for (size_t i = 0; i <= MAX_N_ORDER; i++)
	{
		// while (!serial_port.IsDataAvailable()){}
		try
		{
			current_order = read_order(serial_port, timeout_ms);
			//  ReadTimeout
		}
		catch(exception& e)
		{
			std::cout << "Timeout!" << endl;
			serial_port.Close();
			return 0;
		}

		switch (current_order)
		{
			case HELLO:
			{
				cout << "HELLO" << endl;
				break;
			}
			case SERVO:
			{
				int16_t angle = read_i16(serial_port);
				cout << "SERVO: angle=" << angle << endl;
				break;
			}
			case MOTOR:
			{
				int speed = read_i8(serial_port);
				cout << "MOTOR: speed=" << speed << endl;
				break;
			}
			case ALREADY_CONNECTED:
			{
				cout << "ALREADY_CONNECTED" << endl;
				break;
			}
			case ERROR:
			{
				int16_t errorCode = read_i16(serial_port);
				cout << "ERROR " << errorCode << endl;
				break;
			}
			case RECEIVED:
			{
				cout << "RECEIVED" << endl;
				break;
			}
			case STOP:
			{
				cout << "STOP!" << endl;
				break;
			}
			default:
			{
				bitset<8> b(current_order);
				cout << "Unknown command:" << b << endl;
			}
		}
	}

	serial_port.Close();
  return 0;
}
