class AST
{
public:
    deque<Stmt> getContent()
    {
        return content;
    }
    void addAssign(TokenType type, string id, Expr value)
    {
        content.push_back({Assign{type, id, value}});
    }
    void addExit(Expr value)
    {
        content.push_back({Exit{value}});
    }

private:
    deque<string> errors;

    deque<Stmt> content;
};

static AST ast;