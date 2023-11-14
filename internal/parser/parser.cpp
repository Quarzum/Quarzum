#define Expr nullExpr
class Parser
{
public:
    Parser(TokenList tokens) : m_tokens(move(tokens))
    {
        size = m_tokens.size();
    }

    /* Parses only expressions, conditions, function calls and other */
    void parse()
    {

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
                        nodestack.push_back(e);
                        stack.clear();
                    }
                    else
                    {
                        nodestack.push_back(t);
                    }
                    stack.clear();
                }
            }
            // If not, push it directly into the result
            else
            {
                nodestack.push_back(t);
            }
        }
    }
    /* Once complex AST structures are created, build the AST iterating the list of Tokens/Expr */
    void buildAST()
    {
        while (index < nodestack.size())
        {
            cout << index;
            if (followSyntax({INT_K, ID, EQUAL, Expr}))
            {
                if (getExpr(3).type == INT)
                {
                    cout << "INT ASSIGN WITH VALUE";
                    index += 3 + getExpr(3).size;
                }
                else
                {
                    Debug.err("Initialization value is not an integer", "TypeError");
                }
            }
            else if (followSyntax({INT_K, ID}))
            {
                cout << "INT ASSIGN WITHOUT VALUE";
                index += 2;
                continue;
            }
            else
            {
                index++;
            }
            cout << index;
        }
    }

private:
    TokenList m_tokens;
    deque<variant<Token, NodeExpr>> nodestack;
    TokenList stack;
    TokenType exprTypes[15] = {INT, BOOL, NUM, STR, ID, PLUS, PRODUCT, MINUS, DIVIDE, INTDIV, POWER, STR, NUM, PAR_OPEN, PAR_CLOSE};
    size_t index = 0;
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

    bool followSyntax(deque<variant<TokenType, NodeExpr>> list)
    {
        for (size_t n = 0; n < list.size(); n++)
        {
            if (n < nodestack.size())
            {
                if (holds_alternative<TokenType>(list.at(n)))
                {
                    if (get<TokenType>(list.at(n)) != get<Token>(nodestack.at(index + n)).type)
                    {
                        return false;
                    }
                }
                else
                {
                    if (not holds_alternative<NodeExpr>(nodestack.at(index + n)))
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    NodeExpr getExpr(int d)
    {
        if (holds_alternative<NodeExpr>(nodestack.at(index + d)))
        {
            return get<NodeExpr>(nodestack.at(index + d));
        }
        return nullExpr;
    }

    size_t size;
};