#define isType(d) if (holds_alternative<d>(stmt.content))
class AST
{
public:
    deque<NodeStmt> getContent()
    {
        return content;
    }
    void addAssign(TokenType type, string id, NodeExpr value)
    {
        content.push_back({NodeAssign{type, id, value}});
    }
    void addExit(NodeExpr value)
    {
        content.push_back({NodeExit{value}});
    }
    void addReturn(NodeExpr value)
    {
        content.push_back({NodeReturn{value}});
    }

private:
    deque<string> errors;

    deque<NodeStmt> content;
};

static AST ast;