class AST
{
public:
    AST() {}
    int size()
    {
        return childcount;
    }

    void addInit(TokenType type, Token name, Expr value = nullExpr)
    {
        debug(tokens[type] + "_INIT -> id: " + name.value + ", value: " + value.literal.value);
        nodes.push_back(Assign{type, name, value});
    }

    void addReturn(Expr expr)
    {
        debug("RETURN -> value: " + expr.literal.value);
        nodes.push_back(Return{expr});
    }

    void addExit(Expr expr)
    {
        debug("EXIT -> value: " + expr.literal.value);
        nodes.push_back(Exit{expr});
    }

    void addAssign(Token name, Expr value)
    {
        debug("REASSIGN -> id: " + name.value + ", value: " + value.literal.value);
        nodes.push_back(ReAssign{name, value});
    }

    void addUnaryPlus(Token name)
    {
        Expr expr = Expr{INT, name.value + " + 1", 3};
        addAssign(name, expr);
    }
    void addUnaryMinus(Token name)
    {
        Expr expr = Expr{INT, name.value + " - 1", 3};
        addAssign(name, expr);
    }

    deque<Statement> nodes;

private:
    int childcount;
};

static AST ast = AST();