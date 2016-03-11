# Make all examples.
# No Scons, no CMake, no Make or any other make tool
# One line one example
# Designed for easy copy/paste


g++ -fexceptions -std=c++11 -g -I../src hello.cpp             -o  hello
g++ -fexceptions -std=c++11 -g -I../src one.cpp               -o  one
g++ -fexceptions -std=c++11 -g -I../src two.cpp               -o  two

g++ -fexceptions -std=c++11 -g -I../src one.cpp   -DCOUNTER_USE_PP2FILE  -o  one_oneh
g++ -fexceptions -std=c++11 -g -I../src two.cpp   -DCOUNTER_USE_PP2FILE  -o  two_oneh

