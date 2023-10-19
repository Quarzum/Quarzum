struct Statement;
// expr -> <literal> || <literal> <op> <expr>
struct Expr
{
    Token literal;
    int size;
};
// cond -> <bool> || <bool> <c_op> <bool>
struct Condition
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
struct Out
{
    Expr value;
};
// argument -> <type> <ident> (= <expr>)?
struct Argument
{
    TokenType type;
    string id;
    Expr value;

    int size;
};

// assign -> "static"? "const"? <size_modifier>* <type> <ident> = <expr>
struct Assign
{
    TokenType type;
    string id;
    variant<Expr, Condition> value;
};

// re_assign -> <ident> = <expr>
struct ReAssign
{
    string id;
    Expr value;
};

// function-call -> <id>(<expr>*)
struct FunctionCall
{
    string name;
    // deque<Argument> args;
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

// function -> <type>(|| "function") <id> ( <arg>* ) { <block> }
struct Function
{
    TokenType type;
    string id;
    // deque<Argument> args;
    Block content;
};
// if -> "if" ( <condition> ) { <block> }
struct If
{
    // Cond condition;
    Block content;
};

// else -> "else" { <block> }
struct Else
{
    Block content;
};

// while -> "while" ( <condition> ){ <block> }
struct While
{
    Condition condition;
    Block content;
};

// for -> "for" (<assign>; <condition>; <reassign> ){ <block> }
struct For
{
    Assign var;
    Condition condition;
    ReAssign step;
    Block content;
};

// module -> "module" <name> { <block> }
struct Module
{
    string name;
    Block content;
};

// identation -> <type> <name> <block>
struct Identation
{
    string type;
    string name;
    Block content;
};

struct Statement
{
    variant<
        Out,
        Assign,
        ReAssign,
        Exit,
        Return,
        Import,
        If,
        Else,
        For,
        While,
        Module,
        Block,
        Function,
        FunctionCall>
        stmt;
    string type;
};

Expr nullExpr = {Token{NULL_KEYWORD, "null"}, 0};