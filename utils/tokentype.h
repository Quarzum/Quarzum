enum TokenType
{
    // Exit statements
    EXIT,
    RETURN,
    IMPORT,
    FROM,
    // Data types and keywords
    INT,
    INT_KEYWORD,
    STRING,
    STRING_KEYWORD,
    NUMBER,
    NUMBER_KEYWORD,
    TRUE,
    FALSE,
    BOOL,
    BOOL_KEYWORD,
    ANY,
    ANY_KEYWORD,
    FUNCTION_KEYWORD,
    NULL_KEYWORD,
    STRUCT_KEYWORD,
    ENUM_KEYWORD,
    CLASS_KEYWORD,
    PUBLIC_KEYWORD,
    PRIVATE_KEYWORD,
    MODULE_KEYWORD,
    // Operators
    OPERATOR,
    AND,
    OR,
    NOT,
    GREATER,
    LOWER,
    // Symbols
    EQUAL,
    COMMA,
    POINT,
    PAR_OPEN,
    PAR_CLOSE,
    C_BRACKET_OPEN,
    C_BRACKET_CLOSE,
    S_BRACKET_OPEN,
    S_BRACKET_CLOSE,
    // Modifiers
    CONST,
    UNSIGNED,
    SHORT,
    LONG,
    THIS,
    STATIC,
    DELETE,
    // Others
    IDENTIFIER,
    EOL,
    SEMICOLON,
    // Built-in functions
    OUT,
    INPUT,
    TYPEOF,
    TO_INT,
    TO_STR,
    TO_NUM,
    // Bucles
    IF,
    ELSE,
    FOR,
    WHILE,
    COMMENT,
};
struct Token
{
    TokenType type;
    string value;
};