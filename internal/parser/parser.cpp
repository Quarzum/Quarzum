#pragma once
#define nextType(d) see(d).type
#define hasExpr(d) if (auto e = parseExpr(d))
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
                        testExpr(e.value());
                        ast.addAssign(INT, see(1).value, e.value());
                        advance(3);
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
                    advance(2);
                }
                advance(1);
            }
            // RETURN EXPR
            if (followSyntax({RETURN}))
            {
                hasExpr(1)
                {
                    ast.addExit(e.value());
                    advance(2);
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

    optional<NodeExpr> parseExpr(int d);

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

    void testExpr(NodeExpr e)
    {
        string s = e.value.type().name();
        s = s.substr(1);
        if (s == "NodeSum")
        {
            cout << s << endl;
            NodeSum sum = any_cast<NodeSum>(e.value);
            testExpr(NodeExpr{sum.b});
        }
        else
        {
            cout << "Term" << endl;
        }
    }
};

optional<NodeExpr> Parser::parseExpr(int d)
{
    if (nextType(d) == INT or nextType(d) == ID)
    {
        return NodeExpr{.value = NodeSum{{see(d)}, NodeSum{{see(d)}, {see(d)}}}};
    }
    return {};
}
