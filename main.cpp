#include "./src/Quarzum.h"

int main()
{   
    vector<Token> list = tokenize(getContent("../code.qz"));

    //Parser p(tok);

    //Assembler a(p.parse());

    createFile("out.asm", ".data");
    //system("as -o out.o out.asm");
    //system("ld -o out out.o");
    //system("./out");
    return 0;
}
