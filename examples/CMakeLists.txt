cmake_minimum_required(VERSION 3.25 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")
project(RobustSerialExamples)


# TODO: add the require for serial
# TODO: transform it into a shared library

include_directories(../src)

# Command Parser
add_executable(command_parser.x command_parser.cpp ../src/robust_serial.cpp)
target_link_libraries(command_parser.x serial pthread)

# Serial Reader (require serial lib)
add_executable(serial_reader.x serial_reader.cpp  ../src/robust_serial.cpp)
target_link_libraries(serial_reader.x serial pthread)

# File read write example
add_executable(file_read_write.x file_read_write.cpp  ../src/robust_serial.cpp)
target_link_libraries(file_read_write.x serial pthread)
