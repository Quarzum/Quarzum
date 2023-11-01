class Analyzer
{
public:
    Analyzer(AST ast) : root(move(ast)) {}

    void analyze()
    {
        size_t size = root.getContent().size();
        while (i < size)
        {
            NodeStmt stmt = root.getContent()[i];
            if (holds_alternative<NodeExit>(stmt.content))
            {
                if (get<NodeExit>(stmt.content).value.type == INT)
                {
                    cout << "Exit is correct";
                    i++;
                    continue;
                }
                Error.exit(TYPE_ERROR, "Expected an integer exit code");
            }
            i++;
        }
    }

private:
    AST root;
    size_t i = 0;
};