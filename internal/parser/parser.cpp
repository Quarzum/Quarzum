#define nextType(d) see(d).type

class Parser
{
public:
    Parser(TokenList tokens) : m_tokens(move(tokens)) {}
    void parse()
    {
        size = m_tokens.size();
        while (i < size)
        {
            if (followSyntax({INT_K, ID}))
            {
                if (nextType(2) == EQUAL)
                {
                    if (auto e = parseExpr(3))
                    {
                        cout << "INT_ASSIGN" << endl;
                        i += 3;
                        continue;
                    }
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

    Token see(__int8 d)
    {
        if (i + d < size)
        {
            return m_tokens.get(i + d);
        }
        return {};
    }

    optional<Expr> parseExpr(int d);

    bool followSyntax(deque<TokenType> list)
    {
        bool res = true;
        for (size_t n = 0; n < list.size(); n++)
        {
            if (nextType(n) != list[n])
            {
                res = false;
                break;
            }
        }
        return res;
    }
};

optional<Expr> Parser::parseExpr(int d)
{
    if (see(d).type == INT)
    {
        return Expr{.value = see(d)};
    }
    return {};
}
