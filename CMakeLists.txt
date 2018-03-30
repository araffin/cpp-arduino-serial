cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
project(Command)
# Command Parser
add_executable(command_parser.x command_parser.cpp)
target_link_libraries (command_parser.x pthread)
target_link_libraries (command_parser.x serial)

# Serial Reader (require serial lib)
# TODO: add the require
add_executable(serial_reader.x serial_reader.cpp)
target_link_libraries (serial_reader.x pthread)
target_link_libraries (serial_reader.x serial)
