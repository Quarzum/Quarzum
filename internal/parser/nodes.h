struct Expr;

struct Sum
{
    Token l;
    Token r;
};

struct Expr
{
    variant<Sum, Token> value;
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