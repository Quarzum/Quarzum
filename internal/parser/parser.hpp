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
            if (nextType(0) == INT_K && nextType(1) == ID)
            {
                if (nextType(2) == EQUAL)
                {
                    Expr e = parseExpr(3);
                    // if (see(3).type == INT)
                    // {
                    //     cout << "INT_ASSIGN" << endl;
                    //     i += 3;
                    //     continue;
                    // }
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
        return t == INT || t == NUM || t == ID || t == STR || t == PLUS;
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
            cout << "Sum(" << result[0] << "," << result[1] << ")" << endl;
        }
        else
        {
            result.push_back(e);
        }
        return result;
    }
    deque<string> readProd(string e)
    {
        deque<string> result;
        if (e.find('*') >= 0)
        {
            result.push_back(e.substr(0, e.find('*')));
            result.push_back(e.substr(e.find('*') + 1, e.length()));
            cout << "Prod(" << result[0] << "," << result[1] << ")" << endl;
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
    deque<string> res = readSum(e);
    if (res.size() == 2)
    {
        deque<string> a = readProd(res[0]);
        deque<string> b = readProd(res[1]);
    }

    for (size_t i = 0; i < e.length(); i += 2)
    {
        cout << e[i] << " - " << tokens[nextType(3 + i)] << endl;
    }

    return Expr{Sum{Token{see(3 + 0)}, Token{see(3 + 2)}}};
}
