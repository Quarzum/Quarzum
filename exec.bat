ECHO off
g++ main.cpp -o main.exe
main.exe ./examples/code.qz
del main.exe
exit