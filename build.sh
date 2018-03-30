# Build and copy executables to root dir
cd build
cmake ..
make
cp command_parser.x ../
cp serial_reader.x ../
