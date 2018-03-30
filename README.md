# Robust Arduino Serial Protocol in C++

```
sudo apt-get install libserial-dev
```

**Robust Arduino Serial** is a simple and robust serial communication protocol. It was designed to make two Arduinos communicate, but can also be useful when you want a computer (e.g. a Raspberry Pi) to communicate with an Arduino.

## Examples

To build the two examples, run the `build.sh` inside the `examples/` directory.

[Arduino Source Code](https://github.com/sergionr2/RacingRobot/tree/master/arduino)

Run the command parser to send order to the Arduino (optional: you can run it using rlwrap):
```
./command_parser.x
```

Idem for listening to the serial (for now during 30 seconds, it can be changed in the serial_reader.h)
```
./serial_reader.x
```
