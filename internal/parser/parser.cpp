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

    /* Parses only expressions, conditions, function calls and other */
    void parse()
    {
        size = m_tokens.size();
        for (size_t i = 0; i < size; i++)
        {
            Token t = m_tokens.get(i);
            // If it's an expr-type token, push it into the stack
            if (isExprType(t.type))
            {
                stack.addToken(t.type, t.value);
                // If it's the last expr-type token in a row, close the stack and parse the expression
                if ((i + 1 > size or !isExprType(m_tokens.get(i + 1).type)))
                {
                    if (stack.size() > 1 or (stack.size() == 1 and stack.get(0).type != ID))
                    {

                        stack.debug("Expression lexing");
                        NodeExpr e = parseExpr(stack);
                        // result.push_back(e);
                    }
                    else
                    {
                        result.push_back(t);
                    }
                    stack.clear();
                }
            }
            // If not, push it directly into the result
            else
            {
                result.push_back(t);
            }
        }
    }
    /* Once complex AST structures are created, build the AST iterating the list of Tokens/Expr */
    void buildAST()
    {
    }

private:
    TokenList m_tokens;
    deque<variant<Token, NodeExpr>> result;
    TokenList stack;
    TokenType exprTypes[15] = {INT, BOOL, NUM, STR, ID, PLUS, PRODUCT, MINUS, DIVIDE, INTDIV, POWER, STR, NUM, PAR_OPEN, PAR_CLOSE};
    bool isExprType(TokenType t)
    {
        for (size_t n = 0; n < 15; n++)
        {
            if (t == exprTypes[n])
            {
                return true;
            }
        }
        return false;
    }

    NodeExpr parseExpr(TokenList stack)
    {
        if (stack.size() == 1)
        {
            return NodeExpr{
                .value = stack.get(0),
                .size = 1,
                .type = stack.get(0).type

            };
        }
        /*

            Operator Precedence Level 0

        */
        for (size_t n = stack.size(); n > 0; n--)
        {
            if (stack.get(n).type == PLUS)
            {
                NodeExpr a = parseExpr(TokenList(stack.divide(n, true)));
                NodeExpr b = parseExpr(TokenList(stack.divide(n, false)));

                TokenType type = blendTypes(a, b, "sum");
                cout << type << endl;
                return NodeExpr{

                    .value = NodeSum{a, b},
                    .size = (int)stack.size(),
                    .type = type,

                };
            }
            else if (stack.get(n).type == MINUS)
            {
                NodeExpr a = parseExpr(TokenList(stack.divide(n, true)));
                NodeExpr b = parseExpr(TokenList(stack.divide(n, false)));

                TokenType type = blendTypes(a, b, "sum");
                cout << type << endl;
                return NodeExpr{

                    .value = NodeSub{a, b},
                    .size = (int)stack.size(),
                    .type = type,

                };
            }
        }
        /*

            Operator Precedence Level 1

        */
        for (size_t n = stack.size(); n > 0; n--)
        {
            if (stack.get(n).type == PRODUCT)
            {
                NodeExpr a = parseExpr(TokenList(stack.divide(n, true)));
                NodeExpr b = parseExpr(TokenList(stack.divide(n, false)));

                TokenType type = blendTypes(a, b, "prod");
                cout << type << endl;
                return NodeExpr{

                    .value = NodeProd{a, b},
                    .size = (int)stack.size(),
                    .type = type,

                };
            }
        }

        return nullExpr;
    }

    size_t size;
};