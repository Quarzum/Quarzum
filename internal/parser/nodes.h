
struct Expr
{
    Token value;
};

Expr nullExpr = {};

struct Exit
{
    Expr value;
};
struct Return
{
    Expr value;
};

struct Assign
{
    TokenType type;
    string id;
    Expr value;
};

struct Stmt
{
    variant<Assign, Exit, Return> content;
};