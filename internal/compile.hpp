// Void function to compile source code into asm
void compile(string source)
{
    /* Divide source code into tokens */
    Lexer lexer = Lexer(source);

    TokenList tokens = lexer.tokenize();
    /* Pass from tokens to AST */

    Parser parser = Parser(tokens);
    parser.parse();
    parser.buildAST();

    Analyzer analyzer = Analyzer(ast);
    analyzer.analyze();

    Generator generator = Generator(ast);
    generator.generate();
}
