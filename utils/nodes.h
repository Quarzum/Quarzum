/*

    Pre-initialize structs for recursion

*/
struct Expr;

// add -> t "+" expr
struct Add
{
    Token t;
    Expr *expr;
};

// size_modifier -> "x8" || "x16" || "x32" || "x64" || "x128" || "short" || "long" || "unsigned"
struct SizeModifier
{
    TokenType size;
};

// expr -> <literal> || <literal> <op> <literal>
struct Expr
{
    Token literal;
    int size;
};

// exit -> "exit" <expr>
struct Exit
{
    Expr value;
};

struct Return
{
    Expr value;
};

// assign -> "static"? "const"? <size_modifier>* <type> <ident> = <expr>
struct Assign
{
    TokenType type;
    Token ident;
    Expr value;
};

// re_assign -> <ident> = <expr>
struct ReAssign
{
    Token ident;
    Expr value;
};

// import -> "import" <id> "from" <path>
struct Import
{
    Token id;
    string path;
};
