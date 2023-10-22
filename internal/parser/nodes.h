struct Expr;

struct Sum
{
    Expr *l;
    Expr *r;
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