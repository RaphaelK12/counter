# Make all examples.
# No Scons, no CMake, no Make or any other make tool
# One line one example
# Designed for easy copy/paste

g++ -fexceptions -std=c++11 -g -I../src one.cpp               -o  one
g++ -fexceptions -std=c++11 -g -I../src two.cpp               -o  two