#include "./internal/Quarzum.h"
/*

    Minimal main.cpp, all the procedures are into Quarzum.h

*/
using namespace std;
int main(/*int argc, char *argv[]*/)
{   

    deque<Token> tokens = tokenize("// comentario \n exit 73");
    debugTokens(tokens);
    string content = analyze(parse(tokens));

    ofstream outfile("out.asm");
    outfile << content;
    outfile.close();

    //system("as -o out.o out.asm");
    //system("ld -o out out.o");

    return EXIT_SUCCESS;
}