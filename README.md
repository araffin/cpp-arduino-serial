# Robust Arduino Serial Protocol in C++

[![CI](https://github.com/araffin/cpp-arduino-serial/workflows/CI/badge.svg)](https://github.com/araffin/cpp-arduino-serial/actions/workflows/ci.yml)


**Robust Arduino Serial** is a simple and robust serial communication protocol. It was designed to make two Arduinos communicate, but can also be useful when you want a computer (e.g. a Raspberry Pi) to communicate with an Arduino.

This repository is part of the Robust Arduino Serial project, main repository: [https://github.com/araffin/arduino-robust-serial](https://github.com/araffin/arduino-robust-serial)

**Please read the [Medium Article](https://medium.com/@araffin/simple-and-robust-computer-arduino-serial-communication-f91b95596788) to have an overview of this protocol.**

Implementations are available in various programming languages:

- [Arduino](https://github.com/araffin/arduino-robust-serial)
- [Python](https://github.com/araffin/python-arduino-serial)
- [C++](https://github.com/araffin/cpp-arduino-serial)
- [Rust](https://github.com/araffin/rust-arduino-serial)

## Dependency

Dependency (libserial):
```bash
sudo apt-get install libserial-dev
```

## Examples

To build the two examples, run the `build.sh` inside the `examples/` directory, the binaries will be located in the `bin/` folder.

Read write in a file
```bash
./file_read_write.x
```

If you want to use `command_parser` and `serial_reader` with a real Arduino, you need to flash it with this code:
[Arduino Source Code](https://github.com/araffin/arduino-robust-serial/tree/master/arduino-board/)

Run the command parser to send order to the Arduino (optional: you can run it using rlwrap):
```bash
./command_parser.x
```

Idem for listening to the serial port (for now during 30 seconds, it can be changed in the serial_reader.h)
```bash
./serial_reader.x
```
