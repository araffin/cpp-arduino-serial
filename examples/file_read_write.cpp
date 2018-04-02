#include <iostream>
#include <string>
#include <exception>
#include <bitset> //Binary representation
#include "file_read_write.h"

using namespace std;

fstream serial_file;

int main(int argc, char const *argv[])
{
	string default_filename = "test.log";
	string serial_filename = "";

	// Skip the prompt if an argument is passed
	if (argc < 1)
	{
		cout << "Enter the name of the serial file (default: " << default_filename << " )" << endl;
		getline(cin, serial_filename);
	}

	if(serial_filename.empty())
	{
		cout << "Using default serial file : " << default_filename << endl;
		serial_filename = default_filename;
	}
	// Open the serial file (read/write mode)
	// ios::app Append mode. All output to that file to be appended to the end.
  serial_file.open(serial_filename, ios::in|ios::out|ios::app|ios::binary);
	// If we couldn't open the output file stream for writing
	if (!serial_file)
	{
		// Print an error and exit
		cerr << "Uh oh, serial_file could not be opened for writing!" << endl;
		exit(1);
	}

	// Write some orders
	write_order(serial_file, HELLO);

	write_order(serial_file, MOTOR);
	write_i8(serial_file, -59);
	write_i32(serial_file, 131072);

	write_order(serial_file, SERVO);
	write_i16(serial_file, 3684);

	write_order(serial_file, ERROR);
	write_i16(serial_file, -2541);

	serial_file.seekg(0); //Return to the beginning

	size_t num_orders = 4;

	Order current_order;

	for (size_t i = 0; i < num_orders; i++)
	{
		current_order = read_order(serial_file);

		switch (current_order)
		{
			case HELLO:
			{
				cout << "HELLO" << endl;
				break;
			}
			case SERVO:
			{
				int16_t angle = read_i16(serial_file);
				cout << "SERVO: angle=" << angle << endl;
				break;
			}
			case MOTOR:
			{
				int speed = read_i8(serial_file);
				int32_t test = read_i32(serial_file);
				cout << "MOTOR: speed=" << speed << endl;
				cout << "test:"<< test << endl;
				break;
			}
			case ALREADY_CONNECTED:
			{
				cout << "ALREADY_CONNECTED" << endl;
				break;
			}
			case ERROR:
			{
				int16_t errorCode = read_i16(serial_file);
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

	serial_file.close();
  return 0;
}
