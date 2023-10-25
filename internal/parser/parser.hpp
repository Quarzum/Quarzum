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

    bool isTerm(TokenType t)
    {
        return t == INT || t == NUM || t == ID || t == PLUS;
    }
    string readExpr(int d)
    {
        string result;
        for (size_t i = 0; i < i + 1; i++)
        {
            if (!isTerm(see(d + i).type))
            {
                break;
            }
            result += see(d + i).value;
        }
        return result;
    }
    deque<string> readSum(string e)
    {
        deque<string> result;
        if (e.find('+') >= 0)
        {
            result.push_back(e.substr(0, e.find('+')));
            result.push_back(e.substr(e.find('+') + 1, e.length()));
            cout << "Sum(" << result[0] << "," << result[1] << ")";
        }
        else
        {
            result.push_back(e);
        }
        return result;
    }
};

Expr Parser::parseExpr(int d)
{
    string e = readExpr(d);
    cout << e << endl;
    deque<string> res = readSum(e);
    if (res.size() == 2)
    {
        // return Expr{Sum{Token{INT, res[0]}, Token{INT, res[1]}}};
    }
    return {};
}
