ECHO off
g++ main.cpp -o quarzum.exe
quarzum.exe run ./examples/test/code.qz
del quarzum.exe
exit