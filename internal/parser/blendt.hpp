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

// Returns the type that is the result of merging two different types
TokenType blendTypes(NodeExpr a, NodeExpr b, string op)
{
    if (op == "sum")
    {
        sameType
            precedence(INT, BOOL)
                precedence(NUM, INT)
                    precedence(STR, CHAR)
                        Debug.err("Invalid expression", "TypeError");
    }
    else if (op == "prod")
    {
        sameType
            precedence(STR, INT)
                precedence(NUM, INT)
                    precedence(NUM, BOOL)
                        precedence(INT, BOOL)
                            Debug.err("Invalid expression", "TypeError");
    }
    else if (op == "power")
    {
        if (a.type != NUM or a.type != INT or b.type != INT or b.type == NUM)
        {
            Debug.err("Invalid expression", "TypeError");
        }
    }
    Debug.err("Invalid expression", "TypeError");
    return {};
}