// Void function to compile source code into asm
void compile(string source)
{
    /* Divide source code into tokens */
    Lexer lexer = Lexer(source);
    TokenList tokens = lexer.tokenize();

    if (SHOW_COMPILER_DEBUG)
    {
        debugTokens(tokens.items);
    }
    /* Pass from tokens to AST */

    // Parser parser = Parser(tokens);
    // parser.parse();

    /* Optimizes AST and checks for types */
    // Analyzer analyzer = Analyzer(ast.nodes);
    // analyzer.analyze();
}
