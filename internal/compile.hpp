// Void function to compile source code into asm
void compile(string source)
{
    Lexer lexer = Lexer(source);
    TokenList tokens = lexer.tokenize();
    debug(tokens.getItems());

    Parser parser = Parser(tokens);
    Root root = parser.parse();

    Linker linker = Linker(root);
    Root AST = linker.link();
}
