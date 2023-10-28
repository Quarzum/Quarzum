struct Expr;

struct Expr
{
    Token value;
};

struct Exit
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
    variant<Assign, Exit> content;
};