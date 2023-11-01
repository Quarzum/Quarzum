class Generator
{
public:
    Generator(AST ast) : root(move(ast)) {}
    void generate()
    {
        string result;
    }

private:
    AST root;
};