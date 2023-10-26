enum TokenType
{
    INT_K,
    NUM_K,
    STR_K,
    CHAR_K,
    BOOL_K,
    ANY_K,
    NULL_K,
    FUNCTION_K,
    RETURN,
    EXIT,
    IF,
    ELSE,
    FOR,
    WHILE,
    SWITCH,
    CASE,
    BREAK,
    CONTINUE,
    IMPORT,
    FROM,
    MODULE,

    INT,
    NUM,
    STR,
    BOOL,

    ID,

    EQUAL,
    PLUS,
    MINUS,
    PRODUCT,
    DIVIDE,
    POWER,
    INTDIV,
    PAR_OPEN,
    PAR_CLOSE,
    AND,
    OR,
    NOT
};
struct Token
{
    TokenType type;
    string value;
};