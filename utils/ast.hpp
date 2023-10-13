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

struct Stmt
{
    StmtType type;

    union
    {
        struct StmtGroup
        {
            Stmt **kids;
            uint32_t count;
        } _group;

        struct StmtDecl
        {
            TokenType type;
            DeclFlags flags;
            string name;
            Expression expr;
        } _decl;

        struct StmtReturn
        {
            Expression expr;
        } _return;

        struct StmtExit
        {
            Expression expr;
        } _exit;

        struct StmtIf
        {
            Expression condition;
            Stmt *body;
        } _if;
    };
};
