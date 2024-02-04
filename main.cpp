#include "./internal/Quarzum.h"
/*

    Minimal main.cpp, all the procedures are into Quarzum.h

*/
int main(/*int argc, char *argv[]*/)
{   

    TokenList  tokens = tokenize("exit");
    debugTokens(tokens);
    
    std::string content = analyze(parse(tokens));

    createFile("out.asm", content);

    //system("as -o out.o out.asm");
    //system("ld -o out out.o");

    return EXIT_SUCCESS;
}