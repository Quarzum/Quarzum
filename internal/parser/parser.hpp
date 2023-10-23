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

    Expr parseExpr(int d)
    {

        Stack input;
        Stack op;

        string v;
        if (see(d).type == INT)
        {
            v += see(d).value;
            if (see(d + 1).type == PLUS)
            {
                v += see(d + 1).value;
                if (see(d + 2).type == INT)
                {
                    v += see(d + 2).value;
                }
            }
        }
        cout << v;
        return {};
    }
};