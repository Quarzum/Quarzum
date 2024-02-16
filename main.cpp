#include "./src/Quarzum.h"
/*

    Minimal main.cpp, all the procedures are into Quarzum.h

*/
int main(int argc, char *argv[])
{   
    Source source("../code.qz");

    Tokenizer t(source.getContent());
    Parser p(t.tokenize());

    createFile("out.asm", analyze(p.parse()));
    system("as -o out.o out.asm");
    system("ld -o out out.o");
    system("./out");

    return 0;
}
