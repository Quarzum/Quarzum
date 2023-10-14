class AST
{
public:
    AST() {}
    int size()
    {
        return childcount;
    }

    deque<Statement> getParent()
    {
        return nodes;
    };

    void addIntInit(Token name, Expr value = Expr{})
    {
        nodes.push_back(Assign{INT, name, value});
    }

private:
    int childcount;
    deque<Statement> nodes;
};

static AST ast = AST();