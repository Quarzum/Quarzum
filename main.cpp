#include "./internal/Quarzum.h"
/*

    Minimal main.cpp, all the procedures are into Quarzum.h

*/
using namespace std;
int main(/*int argc, char *argv[]*/)
{   
    deque<Token> tokens = tokenize("int i = 4");
    debugTokens(tokens);
    return EXIT_SUCCESS;
}