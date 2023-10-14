struct Stmt;
struct Expression;

enum StmtType
{
    STMT_NONE,

    STMT_GLOBAL_DECL,
    STMT_FUNCTION_DECL,

    STMT_IF,
    STMT_WHILE,
    STMT_FOR,
    STMT_SWITCH,
    STMT_CASE,
    STMT_DEFAULT,
    STMT_BREAK,
    STMT_CONTINUE,

    STMT_RETURN,
    STMT_EXIT
};
struct DeclFlags
{
    bool isConst;
};
struct Expression
{
    unsigned int size;
};

struct StmtGroup
{
    Stmt **kids;
    uint32_t count;
};

struct StmtDecl
{
    TokenType type;
    DeclFlags flags;
    string name;
    Expression expr;
};

struct StmtReturn
{
    Expression expr;
};

struct StmtExit
{
    Expression expr;
};

struct StmtIf
{
    Expression condition;
    Stmt *body;
};

struct Stmt
{

    StmtType type;
    union
    {
        StmtGroup _group;
        StmtReturn _return;
        StmtExit _exit;
        StmtIf _if;
    };
    ~Stmt() {}
};