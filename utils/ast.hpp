class AST
{
public:
    AST() {}
    int size()
    {
        return childcount;
    }

    void addInit(TokenType type, string name, Expr value = nullExpr)
    {
        debug(tokens[type] + "_INIT -> id: " + name + ", value: " + value.literal.value);
        nodes.push_back(Statement{Assign{type, name, value}});
    }

    void addReturn(Expr expr)
    {
        debug("RETURN -> value: " + expr.literal.value);
        nodes.push_back(Statement{Return{expr}});
    }

    void addExit(Expr expr)
    {
        debug("EXIT -> value: " + expr.literal.value);
        nodes.push_back(Statement{Exit{expr}});
    }

    void addAssign(string name, Expr value)
    {
        debug("REASSIGN -> id: " + name + ", value: " + value.literal.value);
        nodes.push_back(Statement{ReAssign{name, value}});
    }

    void addUnaryPlus(string name)
    {
        Expr expr = Expr{INT, name + " + 1", 3};
        addAssign(name, expr);
    }
    void addUnaryMinus(string name)
    {
        Expr expr = Expr{INT, name + " - 1", 3};
        addAssign(name, expr);
    }

    deque<Statement> nodes;

private:
    int childcount;
};

static AST ast = AST();