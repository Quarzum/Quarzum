#include "./internal/Quarzum.h"
/*

    Minimal main.cpp, all the procedures are into Quarzum.h

*/
int main(/*int argc, char *argv[]*/)
{   
    Source source = Source("../code.qz");

    TokenList tokens = tokenize(source.getContent());

    createFile("out.asm", analyze(parse(tokens)));
    system("as -o out.o out.asm");
    system("ld -o out out.o");
    system("./out");

    return EXIT_SUCCESS;
}