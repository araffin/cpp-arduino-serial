cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
project(Command)

# TODO: add the require for serial
# TODO: transform it into a shared library

include_directories(../lib)
# Command Parser
add_executable(command_parser.x command_parser.cpp ../lib/lib.cpp)
target_link_libraries(command_parser.x pthread)
target_link_libraries(command_parser.x serial)

# Serial Reader (require serial lib)
add_executable(serial_reader.x serial_reader.cpp  ../lib/lib.cpp)
target_link_libraries(serial_reader.x pthread)
target_link_libraries(serial_reader.x serial)
