// operator -> "+" || "-" || "*" || "/" || "%" || "^"
struct Operator
{
    TokenType op;
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
};

// exit -> "exit" <expr>
struct Exit
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

struct Root
{
    deque<Exit> childs;
    deque<Import> imports;
};