class Parser
{
public:
    Parser(TokenList tokens) : m_tokens(move(tokens)) {}
    void parse()
    {
        size = m_tokens.size();
        while (i < size)
        {
            if (isDataType(see(0).type) && see(1).type == ID)
            {
                if (see(2).type == EQUAL)
                {
                    Expr e = parseExpr(3);
                    i += 3;
                    continue;
                }
                i += 2;
                continue;
            }

            i++;
        }
    }

private:
    TokenList m_tokens;
    size_t size, i = 0;
    bool isDataType(TokenType t)
    {
        return t == INT_K;
    }

    Token see(int d)
    {
        if (i + d < size)
        {
            return m_tokens.get(i + d);
        }
        return {};
    }

    Expr parseExpr(int d);
};

bool isLiteral(TokenType t)
{
    return t == INT || t == NUM || t == ID;
}
bool isTerm(TokenType t)
{
    return isLiteral(t) || t == PLUS;
}

Expr Parser::parseExpr(int d)
{
    Stack input;
    Stack op;

    for (size_t i = 0; i < i + 1; i++)
    {
        if (!isTerm(see(d + i).type))
        {
            cout << " -| s:" << i;
            break;
        }
        else
        {
            if (isLiteral(see(d + i).type))
            {
                cout << see(d + i).value;
                input.push(see(d + i).value);
            }
            else
            {
                cout << see(d + i).value;
                op.push(see(d + i).value);
            }
        }
    }
    return {};
}