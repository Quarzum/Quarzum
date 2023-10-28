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
        while (i < size)
        {
            // INT ID
            if (followSyntax({INT_K, ID}))
            {
                // INT ID = EXPR
                if (nextType(2) == EQUAL)
                {
                    hasExpr(3)
                    {
                        ast.addAssign(INT, see(1).value, e.value());
                        advance(3 + e.value().size);
                    }
                }
                ast.addAssign(INT, see(1).value, nullExpr);
                advance(2);
            }
            // EXIT EXPR
            if (followSyntax({EXIT}))
            {
                hasExpr(1)
                {
                    ast.addExit(e.value());
                    advance(2 + e.value().size);
                }
                advance(1);
            }
            // RETURN EXPR
            if (followSyntax({RETURN}))
            {
                hasExpr(1)
                {
                    ast.addExit(e.value());
                    advance(2 + e.value().size);
                }
                advance(1);
            }

            i++;
        }
    }

private:
    TokenList m_tokens;
    size_t size, i = 0;

    // Returns the token at distance d from the actual token (position i)
    Token see(__int8 d)
    {
        if (i + d < size)
        {
            return m_tokens.get(i + d);
        }
        return {};
    }

    optional<NodeExpr> parseExpr(int d, int limit = 50);

    // Returns true if the following token types are the same in order as the list
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

bool isTerm(TokenType t)
{
    return t == INT or t == NUM or t == ID;
}
bool isOp(TokenType t)
{
    return t == PLUS or t == PRODUCT;
}

optional<NodeExpr> Parser::parseExpr(int d, int limit)
{
    NodeExpr result = nullExpr;
    int size = 0;
    int index = 1;
    str expr;
    // Read first term
    if (isTerm(nextType(d)))
    {
        expr += see(d).value;
        size = 1;
        // Read next pairs of op-term
        while (isOp(nextType(index + d)) and isTerm(nextType(index + 1 + d)) and index < limit)
        {
            expr += see(d + index).value + see(d + 1 + index).value;
            size += 2;
            index += 2;
        }
        cout << size << " | " << expr << endl;

        if (size > 1)
        {
            if (expr.find("+") != str::npos)
            {
                int partition = expr.rfind("+");
                result = NodeExpr{.value = NodeSum{.a = parseExpr(d, partition), .b = parseExpr(d + partition + 1, size - (partition + 1))}, .size = size};
            }
            else if (expr.find("*") != str::npos)
            {
                int partition = expr.rfind("*");
                result = NodeExpr{.value = NodeProd{.a = parseExpr(d, partition), .b = parseExpr(d + partition + 1, size - (partition + 1))}, .size = size};
            }
        }
        else
        {
            result = NodeExpr{see(d)};
        }
    }
    return result;
}
