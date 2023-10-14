ECHO off
g++ main.cpp -o quarzum.exe
quarzum.exe ./examples/test/code.qz
del quarzum.exe
exit