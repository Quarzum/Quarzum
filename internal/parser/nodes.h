struct NodeCond
{
    any value;
    int size;
    TokenType type;
};

struct NodeExpr
{
    any value;
    int size;
    TokenType type;
};

#define exprContent \
    NodeExpr a;     \
    NodeExpr b;     \
    TokenType type;

struct NodeSum
{
    exprContent;
};

struct NodeProd
{
    exprContent;
};

struct NodeSub
{
    exprContent;
};

struct NodeDiv
{
    exprContent;
};
struct NodePow
{
    exprContent;
};

struct NodeModule
{
    exprContent;
};

#define condContent \
    NodeCond a;     \
    NodeCond b;

struct NodeAnd
{
    condContent;
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