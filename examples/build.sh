# Build and copy executables to root dir
mkdir -p build
cd build
cmake ..
make
cp command_parser.x ../
cp serial_reader.x ../
