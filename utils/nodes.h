struct Statement;
// expr -> <literal> || <literal> <op> <expr>
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
// return -> "return" <expr>
struct Return
{
    Expr value;
};

// assign -> "static"? "const"? <size_modifier>* <type> <ident> = <expr>
struct Assign
{
    TokenType type;
    string id;
    Expr value;
};

// re_assign -> <ident> = <expr>
struct ReAssign
{
    string id;
    Expr value;
};

// import -> "import" <id> "from" <path>
struct Import
{
    Token id;
    string path;
};

struct Block
{
    deque<Statement> stmts;
};
// if -> "if" ( <condition> ) { <block> }
struct If
{
    // condition
    Block content;
};

// while -> "while" ( <condition> ){ <block> }
struct While
{
    // condition
    Block content;
};

// for -> "for" (<assign>; <condition>; <reassign> ){ <block> }
struct For
{
    Assign var;
    // condition
    ReAssign step;
    Block content;
};

// module -> "module" <name> { <block> }
struct Module
{
    string name;
    Block content;
};

struct Statement
{
    variant<Assign, ReAssign, Exit, Return, Import, If, For, While, Module, Block> stmt;
};

Expr nullExpr = {Token{NULL_KEYWORD, "null"}, 0};