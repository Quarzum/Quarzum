struct Expr;

struct Expr
{
    Token value;
};

struct Assign
{
    TokenType type;
    string id;
    // Expression expr;
};

struct Stmt
{
    variant<Assign> content;
};