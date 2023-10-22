enum TokenType
{
    INT_K,
    NUM_K,
    STR_K,
    BOOL_K,
    ANY,
    NULL_K,

    INT,
    NUM,
    STR,
    BOOL,

    ID,

    EQUAL
};
struct Token
{
    TokenType type;
    string value;
};