ECHO off
g++ main.cpp -o main.exe
main.exe ./examples/test/code.qz
del main.exe
exit