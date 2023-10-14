ECHO off
g++ main.cpp -o main.exe
main.exe ./examples/test/code.qz -init
del main.exe
exit