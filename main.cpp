#include "./src/Quarzum.h"

int main()
{   
    Source source("../code.qz");

    Tokenizer t(source.getContent());
    TokenList tok = t.tokenize();
    for (size_t i = 0; i < tok.size(); i++)
    {
        cout << tok.get(i).value << '\n';
    }
    
    Parser p(tok);

    Assembler a(p.parse());

    createFile("out.asm", a.assemble());
    system("as -o out.o out.asm");
    system("ld -o out out.o");
    system("./out");
    return 0;
}
