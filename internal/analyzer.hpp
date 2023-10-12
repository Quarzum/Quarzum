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
                TokenType exprType;

                if (stat.assignContent.value.size == 1)
                {
                    exprType = stat.assignContent.value.literal.type;
                }

                if (assignType == NUMBER_LITERAL)
                {
                    if (exprType != NUMBER_LITERAL &&
                        exprType != INT_LITERAL &&
                        exprType != NULL_KEYWORD)
                    {
                        errorHandler.exit(TYPE_ERROR);
                    }
                }
                if (assignType == INT_LITERAL)
                {
                    if (exprType != INT_LITERAL &&
                        exprType != NULL_KEYWORD)
                    {
                        errorHandler.exit(TYPE_ERROR);
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
