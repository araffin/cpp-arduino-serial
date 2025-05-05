#include <iostream>
#include <string>
#include <algorithm> // For strtolower
#include <exception>
#include "command_parser.h"

using namespace std;

fstream serialFile;

int main(int argc, char const *argv[])
{
  string defaultFileName = "/dev/ttyACM0";
  string serialFileName = "";
  string cmd;// the command name
  bool exitPrompt = false;
  bool validCommand = true;
  cout << "Enter the name of the serial file (default: /dev/ttyACM0 )" << endl;
  getline(cin, serialFileName);

  if(serialFileName.empty())
  {
    cout << "Using default serial file : " << defaultFileName << endl;
    serialFileName = defaultFileName;
  }
  // Open the serial file (read/write mode)
  // ios::app Append mode. All output to that file to be appended to the end.
  serialFile.open(serialFileName, ios::in|ios::out|ios::app|ios::binary);
  // If we couldn't open the output file stream for writing
  if (!serialFile)
  {
    // Print an error and exit
    cerr << "Uh oh, serialFile could not be opened for writing!" << endl;
    exit(1);
  }

  while (!exitPrompt)
  {
    cout << "=========" << endl;
    cout << "Commands: hello | motor | servo | stop | exit " << endl;
    cout << "=========" << endl;
    if(cmd != "")
    {
      if(!validCommand)
      {
        cmd += " Invalid command!";
        validCommand = true;
      }
      cout << "Last command: " << cmd << endl;
    }
    cout << "Please enter a command" << endl;
    cin >> cmd;
    // To lower case
    transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
    if (cmd == "motor")
    {
      int speed = getIntFromUserInput("speed (between -100 and 100) ?");
      write_order(serialFile, MOTOR);
      write_i8(serialFile, speed);
      cmd += " " + to_string(speed);
    }
    else if (cmd == "servo")
    {
      int angle = getIntFromUserInput("angle (between  0 and 180) ?");
      write_order(serialFile, SERVO);
      write_i16(serialFile, angle);
      cmd += " " + to_string(angle);
    }
    else if (cmd == "hello")
    {
      write_order(serialFile, HELLO);
    }
    else if (cmd == "stop")
    {
      write_order(serialFile, STOP);
    }
    else if (cmd == "exit")
    {
      exitPrompt = true;
    }
    else
    {
      validCommand = false;
      cout << endl << "Unknown command ! " << endl << endl;
    }
    flush(serialFile);// Write data in the buffer to the output file
    cout << "\033[2J\033[1;1H";//Clear the terminal
  }
  serialFile.close();
  return 0;
}

/**
 * Ask the user to enter an integer
 * Prompt until the input is valid
 * @param  infoMessage The message displayed to the user
 * @return   the integer entered by the user
 */
int getIntFromUserInput(std::string infoMessage)
{
  bool isValid = false;
  int intParam;
  string param;
  while(!isValid)
  {
    cout << infoMessage << endl;// Ask the user for input
    cin >> param;// Store the string entered
    try
    {
      // Convert String to int
      intParam = stoi(param);
      isValid = true;
    }
    catch(exception& e)
    {
      isValid = false;
      cout << "Please enter a valid integer "<< endl << endl;
    }
  }
  return intParam;
}

/**
 * Ask the user to enter a float
 * Prompt until the input is valid
 * @param  infoMessage The message displayed to the user
 * @return   the integer entered by the user
 */
float getFloatFromUserInput(std::string infoMessage)
{
  bool isValid = false;
  float floatParam;
  string param;
  while(!isValid)
  {
    cout << infoMessage << endl;// Ask the user for input
    cin >> param;// Store the string entered
    try
    {
      // Convert String to float
      floatParam = stof(param);
      isValid = true;
    }
    catch(exception& e)
    {
      isValid = false;
      cout << "Please enter a valid float "<< endl << endl;
    }
  }
  return floatParam;
}

unsigned int getUnsignedIntFromUserInput(std::string infoMessage)
{
  bool isValid = false;
  unsigned int intParam;
  string param;
  while(!isValid)
  {
    cout << infoMessage << endl;// Ask the user for input
    cin >> param;// Store the string entered
    try
    {
      // Convert String to int
      intParam = stoul(param);
      isValid = true;
    }
    catch(exception& e)
    {
      isValid = false;
      cout << "Please enter a valid unsigned integer "<< endl << endl;
    }
  }
  return intParam;
}

/**
 * Ask the user to enter an long
 * Prompt until the input is valid
 * @param  infoMessage The message displayed to the user
 * @return   the integer entered by the user
 */
long getLongIntFromUserInput(std::string infoMessage)
{
  bool isValid = false;
  long intParam;
  string param;
  while(!isValid)
  {
    cout << infoMessage << endl;// Ask the user for input
    cin >> param;// Store the string entered
    try
    {
      // Convert String to long int
      intParam = stol(param);
      isValid = true;
    }
    catch(exception& e)
    {
      isValid = false;
      cout << "Please enter a valid long integer "<< endl << endl;
    }
  }
  return intParam;
}
