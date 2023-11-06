#define precedence(prec, other)                                                        \
    else if (a.type == prec and b.type == other or a.type == other and b.type == prec) \
    {                                                                                  \
        return prec;                                                                   \
    }

#define sameType          \
    if (a.type == b.type) \
    {                     \
        return a.type;    \
    }

TokenType blendTypes(NodeExpr a, NodeExpr b, string op)
{
    if (op == "sum")
    {
        sameType
            precedence(INT, BOOL)
                precedence(NUM, INT)
                    precedence(STR, CHAR)
                        Error.exit(TYPE_ERROR, "Invalid expression");
    }
    else if (op == "prod")
    {
        sameType
            precedence(STR, INT)
                precedence(NUM, INT)
                    precedence(NUM, BOOL)
                        precedence(INT, BOOL)

                            Error.exit(TYPE_ERROR, "Invalid expression");
    }
    Error.exit(TYPE_ERROR, "Invalid expression");
    return {};
}