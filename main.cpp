#include "./src/Quarzum.h"

int main()
{   

    Tokenizer t(getContent("../code.qz"));
    TokenList tok = t.tokenize();
    //Parser p(tok);

    //Assembler a(p.parse());

    createFile("out.asm", ".data");
    //system("as -o out.o out.asm");
    //system("ld -o out out.o");
    //system("./out");
    return 0;
}
