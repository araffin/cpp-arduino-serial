#include <iostream>
#include <string>
#include <algorithm> // For strtolower
#include <exception>
#include <bitset>//Binary representation
#include "serial_reader.h"

using namespace std;


int main(int argc, char const *argv[])
{
	string defaultFileName = DEFAULT_PORT;
	string serialFileName = "";

	cout << "Enter the name of the serial file (default: " << defaultFileName << " )" << endl;
	getline(cin, serialFileName);

	if(serialFileName.empty())
	{
		cout << "Using default serial file : " << defaultFileName << endl;
		serialFileName = defaultFileName;
	}

	SerialPort serial_port(serialFileName);

	const unsigned int msTimeout = TIMEOUT_MS;
	Order currentOrder;
	serial_port.Open(SerialPort::BAUD_115200, SerialPort::CHAR_SIZE_8,
									 SerialPort::PARITY_NONE, SerialPort::STOP_BITS_1,
									 SerialPort::FLOW_CONTROL_NONE);

	for (size_t i = 0; i <= MAX_N_ORDER; i++)
	{
		// while (!serial_port.IsDataAvailable()){}
		try
		{
			currentOrder = read_order(serial_port, msTimeout);
			//  ReadTimeout
		}
		catch(exception& e)
		{
			std::cout << "Timeout!" << endl;
			serial_port.Close();
			return 0;
		}

		switch (currentOrder)
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
				bitset<8> b(currentOrder);
				cout << "Unknown command:" << b << endl;
			}
		}
	}

	serial_port.Close();
  // WEIRD STUFF DO NOT REMOVE LINE FOR NOW
  stoul("1");
  return 0;
}
