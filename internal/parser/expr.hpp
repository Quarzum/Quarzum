#define NodePartition(d)                                       \
    NodeExpr a = parseExpr(TokenList(stack.divide(n, true)));  \
    NodeExpr b = parseExpr(TokenList(stack.divide(n, false))); \
    TokenType type = blendTypes(a, b, d)

NodeExpr parseExpr(TokenList stack)
{
    /*

        Single token expr

    */
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
            NodePartition("sum");
            return NodeExpr{

                .value = NodeSum{a, b},
                .size = (int)stack.size(),
                .type = type,

            };
        }
        else if (stack.get(n).type == MINUS)
        {
            NodePartition("sum");
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
            NodePartition("prod");
            return NodeExpr{

                .value = NodeProd{a, b},
                .size = (int)stack.size(),
                .type = type,

            };
        }
    }

    return nullExpr;
}