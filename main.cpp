#include "./src/Quarzum.h"

int main()
{   
    Source source("../code.qz");

    Tokenizer t(source.getContent());
    Parser p(t.tokenize());
    vector<Statement> s = p.parse();

    //createFile("out.asm", analyze(p.parse()));
    //system("as -o out.o out.asm");
    //system("ld -o out out.o");
    //system("./out");
    return 0;
}
