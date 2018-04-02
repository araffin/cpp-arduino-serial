# Build and copy executables to bin/ dir
mkdir -p build
mkdir -p bin
cd build
cmake ..
make
cp *.x ../bin
