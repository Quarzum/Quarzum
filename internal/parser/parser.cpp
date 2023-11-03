#pragma once
#define nextType(d) see(d).type
#define hasExpr(d) if (auto e = parseExpr(d, 50))
#undef advance
#define advance(d) \
    i += d;        \
    continue

class Parser
{
public:
    Parser(TokenList tokens) : m_tokens(move(tokens)) {}
    void parse()
    {
        size = m_tokens.size();
        for (size_t i = 0; i < size; i++)
        {
            Token t = m_tokens.get(i);
            if (isExprType(t.type))
            {
                stack.addToken(t.type, t.value);
                if (i + 1 > size or !isExprType(m_tokens.get(i + 1).type))
                {
                    NodeExpr e = parseExpr();
                    result.push_back(e);
                    stack.clear();
                }
            }
            else
            {
                result.push_back(t);
            }
        }
    }

private:
    TokenList m_tokens;
    deque<variant<Token, NodeExpr>> result;
    TokenList stack;
    TokenType exprTypes[3] = {INT, ID, PLUS};
    bool isExprType(TokenType t)
    {
        for (size_t n = 0; n < 3; n++)
        {
            if (t == exprTypes[n])
            {
                return true;
            }
        }
        return false;
    }

    NodeExpr parseExpr()
    {
    }

    size_t size;
};

class Builder
{
};