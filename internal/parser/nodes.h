struct Expr;
struct Prod;
struct Sum;
struct Op
{
    variant<Sum, Prod, Token> *op;
};

struct Sum
{
    Op *l;
    Op *r;
};

struct Prod
{
    Op *l;
    Op *r;
};

struct Expr
{
    Op value;
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