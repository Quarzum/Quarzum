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

// root -> {import, import,...},{child, child, child,...}
struct Root
{
    deque<any> childs;
    deque<Import> imports;
};

// struct Statement
// {
//     enum class Type
//     {
//         ASSIGN,
//         EXIT
//     };

//     Type type;
//     union
//     {
//         Assign assignContent;
//         Exit exitContent;
//     };

//     Statement(Assign content) : type(Type::ASSIGN), assignContent(content) {}
//     Statement(Exit content) : type(Type::EXIT), exitContent(content) {}
// };
