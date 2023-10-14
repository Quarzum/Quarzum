ECHO off
g++ main.cpp -o quarzum.exe
quarzum.exe --help --input "./examples/test/code.qz"
del quarzum.exe
exit