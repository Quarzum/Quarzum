class Analyzer
{
public:
    Analyzer(AST ast) : root(move(ast)) {}
    AST analyze()
    {
        debug("\nSemantic analyzer\n----------");
        i = 0;
        while (i < size)
        {
            debug("HOLA");
            Statement stat = root.statements.at(i);
            if (stat.m_type == S_ASSIGN)
            {
                debug("HOLA");
            }
            i++;
        }
        return root;
    }

private:
    AST root;
    short size = root.statements.size();
    short i;
};