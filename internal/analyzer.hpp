class Analyzer
{
public:
    Analyzer(AST ast) : root(move(ast)) {}
    AST analyze()
    {
        debug("\nSemantic analyzer\n------------");
        i = 0;
        while (i < size)
        {
            Statement stat = root.statements.at(i);
            if (stat.m_type == S_ASSIGN)
            {
                debug("ASSIGN");
                TokenType assignType = stat.assignContent.type;
                if (stat.assignContent.value.size == 1)
                {
                    TokenType exprType = stat.assignContent.value.literal.type;
                    cout << tokens[assignType] << " - " << tokens[exprType] << endl;
                    if (assignType == NUMBER_LITERAL)
                    {
                        if (exprType == NUMBER_LITERAL || exprType == INT_LITERAL || exprType == NULL_KEYWORD)
                        {
                            cout << "NUM - " << tokens[exprType] << endl;
                        }
                                        }
                }
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
