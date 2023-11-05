class Parser
{
public:
    Parser(TokenList tokens) : m_tokens(move(tokens)) {}

    /* Parses only expressions, conditions, function calls and other */
    void parse()
    {
        size = m_tokens.size();
        for (size_t i = 0; i < size; i++)
        {
            Token t = m_tokens.get(i);
            // If it's an expr-type token, push it into the stack
            if (isExprType(t.type))
            {
                stack.addToken(t.type, t.value);
                // If it's the last expr-type token in a row, close the stack and parse the expression
                if ((i + 1 > size or !isExprType(m_tokens.get(i + 1).type)))
                {
                    if (stack.size() > 1 or (stack.size() == 1 and stack.get(0).type != ID))
                    {

                        stack.debug("Expression lexing");
                        NodeExpr e = parseExpr(stack);
                        // result.push_back(e);
                    }
                    else
                    {
                        result.push_back(t);
                    }
                    stack.clear();
                }
            }
            // If not, push it directly into the result
            else
            {
                result.push_back(t);
            }
        }
    }
    /* Once complex AST structures are created, build the AST iterating the list of Tokens/Expr */
    void buildAST()
    {
    }

private:
    TokenList m_tokens;
    deque<variant<Token, NodeExpr>> result;
    TokenList stack;
    TokenType exprTypes[15] = {INT, BOOL, NUM, STR, ID, PLUS, PRODUCT, MINUS, DIVIDE, INTDIV, POWER, STR, NUM, PAR_OPEN, PAR_CLOSE};
    bool isExprType(TokenType t)
    {
        for (size_t n = 0; n < 15; n++)
        {
            if (t == exprTypes[n])
            {
                return true;
            }
        }
        return false;
    }

    size_t size;
};