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

#define SUM if (op == "sum")
#define PROD if (op == "prod")
#define POW if (op == "power")

// Returns the type that is the result of merging two different types
TokenType blendTypes(NodeExpr a, NodeExpr b, string op)
{
    SUM
    {
        sameType
            precedence(INT, BOOL)
                precedence(NUM, INT)
                    precedence(STR, CHAR)
                        Debug.err("Invalid expression", "TypeError");
    }
    else PROD
    {
        sameType
            precedence(STR, INT)
                precedence(NUM, INT)
                    precedence(NUM, BOOL)
                        precedence(INT, BOOL)
                            Debug.err("Invalid expression", "TypeError");
    }
    else POW
    {
        if (a.type != NUM or a.type != INT or b.type != INT or b.type == NUM)
        {
            Debug.err("Invalid expression", "TypeError");
        }
        return NUM;
    }
    Debug.err("Invalid expression", "TypeError");
    return {};
}