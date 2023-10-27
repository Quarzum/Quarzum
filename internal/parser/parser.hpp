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
                    Expr e = parseExpr(3);
                    if (see(3).type == INT)
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

    Expr parseExpr(int d);

    bool isTerm(TokenType t)
    {
        return t == INT || t == NUM || t == STR || t == BOOL || t == CHAR || t == ID;
    }
    bool isOp(TokenType t)
    {
        return t == PLUS || t == MINUS || t == PRODUCT || t == DIVIDE || t == POWER || t == MODULE;
    }
    string readExpr(int d)
    {
        string result;
        if (isTerm(see(d).type))
        {
            result += see(d).value;
            for (size_t i = 1; i < i + 1; i += 2)
            {
                if (not isOp(see(d + i).type) or not isTerm(see(d + i + 1).type))
                {
                    break;
                }
                result += see(d + i).value + see(d + i + 1).value;
            }
        }

        return result;
    }

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

#define findSymbol(s) src.find(s) != string::npos
#define firstDiv(s) src.substr(0, src.find(s))
#define secondDiv(s) src.substr(src.find(s) + 1, src.length())
deque<string> parsePemdas(string src)
{
    deque<string> result;

    if (findSymbol("-"))
    {
        cout << "IT'S A SUB" << endl;
        result.push_back(firstDiv("-"));
        result.push_back(secondDiv("-"));
    }
    else if (findSymbol("+"))
    {
        cout << "IT'S A SUM" << endl;
        result.push_back(firstDiv("+"));
        result.push_back(secondDiv("+"));
    }
    else if (findSymbol("/"))
    {
        cout << "IT'S A DIVISION" << endl;
        result.push_back(firstDiv("/"));
        result.push_back(secondDiv("/"));
    }
    else if (findSymbol("*"))
    {
        cout << "IT'S A PROD" << endl;
        result.push_back(firstDiv("*"));
        result.push_back(secondDiv("*"));
    }
    else if (findSymbol("^"))
    {
        cout << "IT'S A POWER" << endl;
        result.push_back(firstDiv("^"));
        result.push_back(secondDiv("^"));
    }
    else if (findSymbol("%"))
    {
        cout << "IT'S A INTDIV" << endl;
        result.push_back(firstDiv("%"));
        result.push_back(secondDiv("%"));
    }
    return result;
}

Expr Parser::parseExpr(int d)
{
    string e = readExpr(d);
    cout << e << endl;
    parsePemdas(e);
    return Expr{};
}
