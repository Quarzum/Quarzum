class Generator
{
public:
    Generator(AST ast) : root(move(ast)) {}
    void generate()
    {
        string result;

        size_t size = root.getContent().size();
        result += "section .text";
        result += "global main \n\n main:";
        while (i < size)
        {
            NodeStmt stmt = root.getContent()[i];
            if (holds_alternative<NodeExit>(stmt.content))
            {
                result += "     mov eax, " + get<NodeExit>(stmt.content).value.size;
                result += "     ret";
            }
            i++;
        }
    }

private:
    AST root;
    size_t i = 0;
};