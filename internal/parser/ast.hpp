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

    void debug()
    {
        cout << GRAY << "Statements\n-------------------" << endl;
        for (size_t a = 0; a < content.size(); a++)
        {
            if (holds_alternative<NodeAssign>(content[a].content))
            {
                cout << "ASSIGN     v:" << YELLOW << get<NodeAssign>(content[a].content).id << GRAY << "      t:" << YELLOW << get<NodeAssign>(content[a].content).type << GRAY << "      s:" << YELLOW << get<NodeAssign>(content[a].content).value.size << GRAY << endl;
            }
            else if (holds_alternative<NodeReturn>(content[a].content))
            {
                cout << "RETURN     s:" << YELLOW << get<NodeReturn>(content[a].content).value.size << GRAY << endl;
            }
        }
        cout << NC;
    }

private:
    deque<string> errors;

    deque<NodeStmt> content;
};

static AST ast;