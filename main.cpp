#include "./src/Quarzum.h"
using namespace Quarzum;
int main()
{   
    Source source("../code.qz");

    Tokenizer t(source.getContent());
    Lex::TokenList tok = t.tokenize();
    Parser p(tok);

    Assembler a(p.parse());

    createFile("out.asm", a.assemble());
    //system("as -o out.o out.asm");
    //system("ld -o out out.o");
    //system("./out");
    return 0;
}
