struct NodeExpr
{
    any value;
    int size;
    TokenType type;
};

struct NodeSum
{
    NodeExpr a;
    NodeExpr b;
    TokenType type;
};

struct NodeProd
{
    NodeExpr a;
    NodeExpr b;
    TokenType type;
};

struct NodeSub
{
    NodeExpr a;
    NodeExpr b;
    TokenType type;
};

struct NodeDiv
{
    NodeExpr a;
    NodeExpr b;
    TokenType type;
};

struct NodePow
{
    NodeExpr a;
    NodeExpr b;
    TokenType type;
};

NodeExpr nullExpr = {};

struct NodeExit
{
    NodeExpr value;
};
struct NodeReturn
{
    NodeExpr value;
};

struct NodeAssign
{
    TokenType type;
    string id;
    NodeExpr value;
};

struct NodeStmt
{
    variant<NodeAssign, NodeExit, NodeReturn> content;
};