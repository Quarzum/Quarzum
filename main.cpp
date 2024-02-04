#include "./internal/Quarzum.h"
/*

    Minimal main.cpp, all the procedures are into Quarzum.h

*/
int main(/*int argc, char *argv[]*/)
{   
    TokenList tokens = tokenize("byte i = 200 out(\"¡Hola mundo!\")");
    debugTokens(tokens);
    
    string content = analyze(parse(tokens));

    createFile("out.asm", content);

    system("as -o out.o out.asm");
    system("ld -o out out.o");

    return EXIT_SUCCESS;
}