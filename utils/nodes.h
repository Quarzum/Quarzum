struct Operator
{
    TokenType op;
};

struct Expr
{
    Token literal;
};

struct Exit
{
    Expr value;
};

struct Assign
{
    TokenType type;
    Token ident;
    Expr value;
};
struct ReAssign
{
    Token ident;
    Expr value;
};

struct Import
{
    Token id;
    string path;
};

struct Root
{
    deque<Exit> childs;
    deque<Import> imports;
};