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
            // STR ID
            if (followSyntax({STR_K, ID}))
            {
                // STR ID = EXPR
                if (nextType(2) == EQUAL)
                {
                    hasExpr(3)
                    {
                        ast.addAssign(STR, see(1).value, e.value());
                        advance(3 + e.value().size);
                    }
                }
                ast.addAssign(STR, see(1).value, nullExpr);
                advance(2);
            }
            // CHAR ID
            if (followSyntax({CHAR_K, ID}))
            {
                // CHAR ID = EXPR
                if (nextType(2) == EQUAL)
                {
                    hasExpr(3)
                    {
                        ast.addAssign(CHAR, see(1).value, e.value());
                        advance(3 + e.value().size);
                    }
                }
                ast.addAssign(CHAR, see(1).value, nullExpr);
                advance(2);
            }

            // NUM ID
            if (followSyntax({NUM_K, ID}))
            {
                // NUM ID = EXPR
                if (nextType(2) == EQUAL)
                {
                    hasExpr(3)
                    {
                        ast.addAssign(NUM, see(1).value, e.value());
                        advance(3 + e.value().size);
                    }
                }
                ast.addAssign(NUM, see(1).value, nullExpr);
                advance(2);
            }
            // ANY ID
            if (followSyntax({ANY_K, ID}))
            {
                // ANY ID = EXPR
                if (nextType(2) == EQUAL)
                {
                    hasExpr(3)
                    {
                        ast.addAssign(ANY_K, see(1).value, e.value());
                        advance(3 + e.value().size);
                    }
                }
                ast.addAssign(ANY_K, see(1).value, nullExpr);
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
                    ast.addReturn(e.value());
                    advance(2 + e.value().size);
                }
                advance(1);
            }

            i++;
        }
        ast.debug();
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
    return t == INT or t == NUM or t == STR or t == CHAR or t == ID;
}
bool isOp(TokenType t)
{
    return t == PLUS or t == PRODUCT or t == DIVIDE or t == MINUS or t == POWER;
}

#define makePartition(d) int partition = expr.rfind(d)
#define nodeDataA parseExpr(d, partition)
#define nodeDataB parseExpr(d + partition - extraLimit + 1, size)
#define findSymbol(d) if (expr.find(d) != string::npos)
optional<NodeExpr> Parser::parseExpr(int d, int limit)
{
    NodeExpr result = nullExpr;
    int size = 0;
    int index = 1;
    int extraLimit = 0;
    string expr;
    // Read first term
    if (isTerm(nextType(d)))
    {
        extraLimit += see(d).value.length() - 1;
        expr += see(d).value;
        size = 1;
        // Read next pairs of op-term
        while (isOp(nextType(index + d)) and isTerm(nextType(index + 1 + d)) and index < (limit - extraLimit))
        {
            expr += see(d + index).value + see(d + 1 + index).value;
            size += 2;
            index += 2;
        }
        cout << size << " | " << expr << endl;

        if (size > 1)
        {
            findSymbol("-")
            {
                makePartition("-");
                result = NodeExpr{
                    .value = NodeSub{.a = nodeDataA, .b = nodeDataB},
                    .size = size

                };
            }
            else findSymbol("+")
            {
                makePartition("+");

                result = NodeExpr{
                    .value = NodeSum{.a = nodeDataA, .b = nodeDataB},
                    .size = size

                };
            }
            else findSymbol("/")
            {
                makePartition("/");
                result = NodeExpr{
                    .value = NodeDiv{.a = nodeDataA, .b = nodeDataB},
                    .size = size

                };
            }
            else findSymbol("*")
            {
                makePartition("*");
                result = NodeExpr{
                    .value = NodeProd{.a = nodeDataA, .b = nodeDataB},
                    .size = size

                };
            }
            else findSymbol("^")
            {
                int partition = expr.find("^");
                result = NodeExpr{
                    .value = NodePow{.a = nodeDataA, .b = nodeDataB},
                    .size = size

                };
            }
        }
        else
        {
            result = NodeExpr{see(d), 1, nextType(d)};
        }
    }
    return result;
}
