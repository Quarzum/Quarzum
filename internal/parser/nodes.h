struct NodeExpr
{
    any value;
    int size;
};

struct NodeSum
{
    NodeExpr a;
    NodeExpr b;
};

struct NodeProd
{
    NodeExpr a;
    NodeExpr b;
};

struct NodeSub
{
    NodeExpr a;
    NodeExpr b;
};

struct NodeDiv
{
    NodeExpr a;
    NodeExpr b;
};

struct NodePow
{
    NodeExpr a;
    NodeExpr b;
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