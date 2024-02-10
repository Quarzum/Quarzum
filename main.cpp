#include "./internal/Quarzum.h"
/*

    Minimal main.cpp, all the procedures are into Quarzum.h

*/
int main(int argc, char *argv[])
{   
    Source source = Source("../test/helloworld.qz");
    Tokenizer t = Tokenizer(source.getContent());

    

    createFile("out.asm", 
    analyze(parse(t.tokenize())));
    system("as -o out.o out.asm");
    system("ld -o out out.o");
    system("./out");

    return EXIT_SUCCESS;
}