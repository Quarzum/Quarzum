enum StmtType
{
    STMT_NONE,

    STMT_GLOBAL_DECL,
    STMT_FUNCTION_DECL,

    STMT_RETURN,
    STMT_EXIT
};

enum ExprType
{

};

struct Expression
{
    unsigned int size;
};

struct Stmt
{
    StmtType type;
};