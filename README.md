# useful_basics
A useful C-based library for basic datastructures &amp; functions

## Compile
libuseful_basics.so
```
mkdir build
cd build
cmake ..
cmake --build .
```
whatever you compile it into:
```
gcc test.c -o0 -Wall -luseful_basics -I../src/ -L./ -o test.out
```
